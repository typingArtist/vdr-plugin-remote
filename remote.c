/*
 * remote.c: Remote Control plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>
#include <vdr/remote.h>
#include <vdr/thread.h>
#include <stdio.h>
#include <sys/fcntl.h>
#include <getopt.h>
#include <termios.h>
#include <linux/input.h>
#include "i18n.h"

#define NUMREMOTES      5         // maximum number of remote control devices

#define KEYMAP_DEVICE_AV7110   "/proc/av7110_ir"

static const char *VERSION        = "0.2.0";
static const char *DESCRIPTION    = "Remote control";

//#define DEBUG

#ifdef DEBUG
#define DSYSLOG(x...)    dsyslog(x)
#else
#define DSYSLOG(x...)
#endif

//------------------------------------------------------------------------------

class cRemoteGeneric : protected cRemote, protected cThread
{
protected:
  static const uint64 INVALID_KEY = (uint64) -1;
  int fh;
  char *device;
  int polldelay;
  int repeatdelay;
  int repeatfreq;
  int repeattimeout;
  cRemoteGeneric(const char *name, int f, char *d);
  virtual ~cRemoteGeneric();
  virtual uint64 getKey(void) = 0;
  virtual bool keyPressed(uint64 code) = 0;
  virtual void Action(void);
};

cRemoteGeneric::cRemoteGeneric(const char *name, int f, char *d)
:cRemote(name)
{
    fh = f;
    device = d;
    polldelay     = 40;   // ms
    repeatdelay   = 350;  // ms
    repeatfreq    = 100;  // ms
    repeattimeout = 500;  // ms
}

cRemoteGeneric::~cRemoteGeneric()
{
    Cancel();
}

void cRemoteGeneric::Action(void)
{
    int now, first = 0, last = 0;
    uint64 code, lastcode = INVALID_KEY;
    bool repeat = false;

    for (;;)
    {
        if (polldelay)
            delay_ms(polldelay);

        code = getKey();
        if (code == INVALID_KEY)
        {
            esyslog("error reading '%s'\n", device);
            delay_ms(100*polldelay);
            continue;
        }

        now = time_ms();

        if (keyPressed(code))
        {
            // key down
            if (now - last > repeattimeout)
            {
                if (repeat)
                {
                    Put(lastcode,false,true);
                    DSYSLOG("%s: timeout %016llx\n", device, code);
                    repeat = false;
                }
                lastcode = INVALID_KEY;
            }

            if (code != lastcode)
            {
                Put(code);
                DSYSLOG("%s: press %016llx\n", device, code);
                lastcode = code;
                last = first = now;
                repeat = false;
            }
            else
            {
                if (now - first < repeatdelay || now - last < repeatfreq)
                    continue;
                Put(code,true);
                DSYSLOG("%s: repeat %016llx\n", device, code);
                last = now;
                repeat = true;
            }
        }
        else
        {
            // key up
            if (repeat)
            {
                Put(lastcode,false,true);
                DSYSLOG("%s: release %016llx\n", device, lastcode);
                repeat = false;
            }
            lastcode = INVALID_KEY;
        }
    }/* for */
}

//------------------------------------------------------------------------------

class cRemoteDevInput : protected cRemoteGeneric
{
private:
  char description[256];
  bool testMode;
  uint64 testKey;
  void loadKeymap(const char *devname, uint32_t options);
protected:
  virtual uint64 getKey(void);
  virtual bool keyPressed(uint64 code);
public:
  cRemoteDevInput(const char *name, int f, char *d);
  virtual bool Initialize(void);
};

void cRemoteDevInput::loadKeymap(const char *devname, uint32_t options)
{
    int fh;
    uint16_t keymap[2+256];
    int n;

    fh = open(devname, O_RDWR);
    if (fh < 0)
    {
        esyslog("%s: unable to open '%s'", Name(), devname);
        return;
    }

    keymap[0] = (uint16_t) options;
    keymap[1] = (uint16_t) (options >> 16);

    for (int i = 1; i <= 256; i++)
        keymap[1+i] = i;

    n = write(fh, keymap, sizeof keymap);
    if (n == sizeof keymap)
        dsyslog("%s: keymap loaded '%s' flags %.8x", Name(), devname, options);
    else
        esyslog("%s: error uploading keymap to '%s'", Name(), devname);

    close(fh);
}

cRemoteDevInput::cRemoteDevInput(const char *name, int f, char *d)
:cRemoteGeneric(name, f, d)
{
    testMode = false;

    Start();

    // input device name
    if (ioctl(f, EVIOCGNAME(sizeof(description)), description) < 0)
        memset(description, 0, sizeof description);

    // autorepeat
#define BITS_PER_LONG	(sizeof(unsigned long) * 8)
    unsigned long data[EV_MAX];
    memset(data, 0, sizeof data);
    ioctl(f, EVIOCGBIT(0,EV_MAX), data); 
    if ( data[EV_REP/BITS_PER_LONG] & (1 << EV_REP%BITS_PER_LONG) )
    {
        // autorepeat driver
        DSYSLOG("%s: supports autorepeat!", d);
        polldelay = 0;
    }
    else
    {
        // non-autorepeat drivers
        polldelay = repeatdelay = repeatfreq = repeattimeout = 0;
    }

    // setup keymap
    const char *setupStr = GetSetup();
    char kDevname[256]; memset(kDevname, 0, sizeof kDevname);
    uint32_t kOptions = 0;
    int kAddr = -1;

    if (setupStr)
    {
        sscanf(setupStr, "%s %lx %d", kDevname, &kOptions, &kAddr);
        if (kAddr != -1)
            kOptions |= ((kAddr << 16) | 0x4000);
    }

    if (kDevname[0])
    {    
        loadKeymap(kDevname, kOptions);
    }
}

bool cRemoteDevInput::Initialize()
{
    testMode = true;

    char setupStr[256]; memset (setupStr, 0, sizeof setupStr);
		
    if (!strcmp(description, "DVB on-card IR receiver"))
    {
        char *kDevname = "/proc/av7110_ir";
        uint32_t kOptions;
        int kAddr = -1;
        int i, n;

	for (n = 0; n < 2; n++)
        {
            if (n == 0)
            {
                Interface->Info(tr("Press any key to use pre-loaded keymap"));
                for (testKey = 0, i = 0; testKey == 0 && i < 35; i++)
                    usleep(200000);
                if (testKey != 0)
                {
                    Interface->Info(tr("User-supplied keymap will be used"));
                    break;
                }
            }

            kOptions = 0x0000;
            Interface->Info(tr("Remote control test - press and hold down any key"));
            loadKeymap(kDevname, kOptions);
            for (testKey = 0, i = 0; testKey == 0 && i < 10; i++)
                usleep(200000);
            if (testKey != 0)
            {
                for (i = 0; i < 64; i++)
                {
                    int a = (i & 0x1f);
                    loadKeymap(kDevname, kOptions | 0x4000 | (a << 16));
                    usleep(400000);
                    testKey = 0;
                    usleep(400000);
                    if (testKey != 0)
                    {
                        kAddr = a;
			break;
		    }
		}
                Interface->Info(tr("RC5 protocol detected"));
                sprintf (setupStr, "%s %.8lx %d", kDevname, kOptions, kAddr);
                break;
            }

            kOptions = 0x8000;
            loadKeymap(kDevname, kOptions);
            for (testKey = 0, i = 0; testKey == 0 && i < 10; i++)
                usleep(200000);
            if (testKey != 0)
            {
                for (i = 0; i < 64; i++)
                {
                    int a = (i & 0x1f);
                    loadKeymap(kDevname, kOptions | 0x4000 | (a << 16));
                    usleep(400000);
                    testKey = 0;
                    usleep(400000);
                    if (testKey != 0)
                    {
                        kAddr = a;
                        break;
                    }
                }
                Interface->Info(tr("RC5 protocol detected (inverted signal)"));
                sprintf (setupStr, "%s %.8lx %d", kDevname, kOptions, kAddr);
                break;
            }

            kOptions = 0x0001;
            loadKeymap(kDevname, kOptions);
            for (testKey = 0, i = 0; testKey == 0 && i < 10; i++)
                usleep(200000);
            if (testKey != 0)
            {
                Interface->Info(tr("RCMM protocol detected"));
                sprintf (setupStr, "%s %.8lx %d", kDevname, kOptions, kAddr);
                break;
            }

            kOptions = 0x8001;
            loadKeymap(kDevname, kOptions);
            for (testKey = 0, i = 0; testKey == 0 && i < 10; i++)
                usleep(200000);
            if (testKey != 0)
            {
                Interface->Info(tr("RCMM protocol detected (inverted signal)"));
                sprintf (setupStr, "%s %.8lx %d", kDevname, kOptions, kAddr);
                break;
            }
        }/* for */

        if (testKey == 0)
	{
            Interface->Error(tr("No remote control detected"));
            esyslog("%s: no remote control detected", device);
            usleep(5000000);
            testMode = false;
            return false;
        }
    }/* DVB card */

    if (setupStr[0])
        PutSetup(setupStr);

    testMode = false;
    return true;
}

uint64 cRemoteDevInput::getKey(void)
{
    struct input_event ev;
    int n;
    uint64 code;

    n = read(fh, &ev, sizeof ev);
    if (n == sizeof ev)
    {
        if (ev.value)
            ev.value = 1;
        code = ((uint64)ev.value << 32) | ((uint64)ev.type << 16) | (uint64)ev.code;
    }
    else
        code = INVALID_KEY;

    if (testMode)
    {
        testKey = code;
        code = 0ULL;
    }

    return code;
}

bool cRemoteDevInput::keyPressed(uint64 code)
{
    return (code & 0xFFFF00000000ULL);
}

//------------------------------------------------------------------------------

#ifdef OLD_LIRC

class cRemoteDevLirc : protected cRemoteGeneric
{
protected:
  virtual uint64 getKey(void);
  virtual bool keyPressed(uint64 code);
public:
  cRemoteDevLirc(const char *name, int f, char *d)
  :cRemoteGeneric(name, f, d) { Start(); }
};

uint64 cRemoteDevLirc::getKey(void)
{
    unsigned long code;
    int n;

    n = read(fh, &code, sizeof code);
    if (n != sizeof code)
        return INVALID_KEY;
    else
        return (uint64)code;
}

bool cRemoteDevLirc::keyPressed(uint64 code)
{
    return (code & 0x80);
}

#endif // OLD_LIRC

//------------------------------------------------------------------------------

class cRemoteDevTty : protected cRemoteGeneric
{
private:
  struct termios tm;
protected:
  virtual uint64 getKey(void);
  virtual bool keyPressed(uint64 code);
public:
  cRemoteDevTty(const char *name, int f, char *d);
  virtual ~cRemoteDevTty(); 
};

cRemoteDevTty::cRemoteDevTty(const char *name, int f, char *d)
:cRemoteGeneric(name, f, d)
{
    struct termios t;

    if (!tcgetattr(f, &tm))
    {
        t = tm;   
        t.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(f, TCSANOW, &t);
    }
    polldelay     = 0;
    repeattimeout = 80;
    Start();
}

cRemoteDevTty::~cRemoteDevTty()
{
    tcsetattr(fh, TCSANOW, &tm);
}

uint64 cRemoteDevTty::getKey(void)
{
    int n;
    uint64 code = 0;

    n = read(fh, &code, sizeof code);
    return (n > 0) ? code : INVALID_KEY;
}

bool cRemoteDevTty::keyPressed(uint64 code)
{
    return true;
}

//------------------------------------------------------------------------------

class cPluginRemote : public cPlugin
{
private:
  int  devcnt;
  char devtyp[NUMREMOTES];
  char *devnam[NUMREMOTES];
  int  fh[NUMREMOTES];
public:
  cPluginRemote(void);
  virtual ~cPluginRemote();
  virtual const char *Version(void) { return VERSION; }
  virtual const char *Description(void) { return tr(DESCRIPTION); }
  virtual const char *CommandLineHelp(void);
  virtual bool ProcessArgs(int argc, char *argv[]);
#if VDRVERSNUM >= 10131
  virtual bool Initialize(void);
#else
  virtual bool Start(void);
#endif
};

cPluginRemote::cPluginRemote(void)
{
    for (int i = 0; i < NUMREMOTES; i++)
    {
        devtyp[i] = '\0';
        devnam[i] = NULL;
        fh[i] = -1;
    }
    devcnt = 0;
}

cPluginRemote::~cPluginRemote()
{
    // must not delete any remotes, see PLUGINS.html!

    for (int i = 0; i < devcnt; i++)
    {
        if (fh[i] >= 0)
            close(fh[i]);
        fh[i] = -1;
    }
    devcnt = 0;
}

const char *cPluginRemote::CommandLineHelp(void)
{
    return "  -i dev,   --input=dev    kernel input device (/dev/input/...)\n"
#ifdef OLD_LIRC
           "  -l dev,   --lirc=dev     kernel lirc device (/dev/lirc)\n"
#endif
           "  -t dev,   --tty=dev      tty device\n";
}

bool cPluginRemote::ProcessArgs(int argc, char *argv[])
{
    static struct option long_options[] =
            { { "input", required_argument, NULL, 'i' },
#ifdef OLD_LIRC
              { "lirc",  required_argument, NULL, 'l' },
#endif
              { "tty",   required_argument, NULL, 't' },
              { NULL } };
    int c;

    while ((c = getopt_long(argc, argv, "i:l:t:", long_options, NULL)) != -1)
    {
        switch (c)
        {
          case 'i':
          case 'l':
          case 't':
              if (devcnt >= NUMREMOTES)
              {
                  esyslog("%s: too many remotes", Name());
                  return false;
              }
              devtyp[devcnt] = c;
              devnam[devcnt] = optarg;
	      devcnt++;
              break;

          default:
              esyslog("%s: invalid argument", Name());
              return false;
        }
    }

    return true;
}

#if VDRVERSNUM >= 10131
bool cPluginRemote::Initialize(void)
#else
bool cPluginRemote::Start(void)
#endif
{
    char nam[25];
    bool ok = false;

    // translations
    RegisterI18n(remotePhrases);

    // defaults
    if (devcnt == 0)
    {
        devtyp[0] = 'i';
        devnam[0] = "/dev/input/event0";
        devcnt = 1;
    }

    for (int i = 0; i < devcnt; i++)
    {
        fh[i] = open(devnam[i], O_RDONLY);
        if (fh[i] < 0)
        {
            esyslog("%s: unable to open '%s'", Name(), devnam[i]);
            continue;
        }
	
        // at least, one device opened successfully
        ok = true;
        dsyslog("%s: using '%s'", Name(), devnam[i]);

        // build name for remote.conf
        char *cp = strrchr(devnam[i], '/');
	if (cp)
            sprintf (nam, "%s-%s", Name(), cp+1);
        else
            sprintf (nam, "%s-%u", Name(), i);

	switch (devtyp[i])
        {
            case 'i':
                new cRemoteDevInput(nam,fh[i],devnam[i]);
                break;

#ifdef OLD_LIRC
            case 'l':
                new cRemoteDevLirc(nam,fh[i],devnam[i]);
                break;
#endif

            case 't':
                new cRemoteDevTty(nam,fh[i],devnam[i]);
                break;
        }
    }
    
    if (!ok)
        esyslog("%s: fatal error - unable to open input device", Name());
    return ok;
}

//------------------------------------------------------------------------------

VDRPLUGINCREATOR(cPluginRemote); // Don't touch this!
