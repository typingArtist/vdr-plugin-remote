/*
 * Remote Plugin for the Video Disk Recorder
 *
 * ttystatus.c: tty osd emulation
 *
 * See the README file for copyright information and how to reach the author.
 */


#include <vdr/plugin.h>
#include <vdr/status.h>
#include "ttystatus.h"


void cTtyStatus::display(const char *buf)
{
    int n = strlen(buf);
    int tabs = 0;
    int tabstop = 30;
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (buf[i] == '\t')
            tabs++;
    }

    if (tabs == 1)
        tabstop = 40;
    else if (tabs == 2)
        tabstop = 10;
    else if (tabs == 3)
        tabstop = 8;
    else
        tabstop = 4;
  
    for (int i = 0; i < n && pos < 80; i++)
    {
        switch (buf[i])
        {
            case '\t':
                do 
                {
                    write(fd, " ", 1);
                    pos++;
                }
                while (pos % tabstop != 0);
                break;

            case '\n':
                write(fd, "\r\n", 2);
                break;

            default:
                write(fd, buf+i, 1);
                pos++;
                break;
        }
    }
}


void cTtyStatus::display2(const char *buf)
{
    for (size_t i = 0; i < strlen(buf); i++)
    {
        switch(buf[i])
        {
            case '\n':
                write(fd, "\r\n", 2);
                break;

            default:
                write(fd, buf+i, 1);
                break;
        }
    } 
}


void cTtyStatus::set_color(int col)
{
    switch(col)
    {
        case WHITE_BLACK:
            print("\e[1m\e[37m\e[40m");
	    break;

        case YELLOW_BLACK:
            print("\e[1m\e[33m\e[40m");
	    break;

        case CYAN_BLACK:
            print("\e[1m\e[36m\e[40m");
	    break;

        case BLACK_CYAN:
            print("\e[0m\e[30m\e[46m");
	    break;

        case BLACK_RED:
            print("\e[0m\e[30m\e[41m");
	    break;

        case BLACK_GREEN:
            print("\e[0m\e[30m\e[42m");
            break;

        case BLACK_YELLOW:
            print("\e[0m\e[30m\e[43m");
            break;

        case WHITE_BLUE:
            print("\e[1m\e[37m\e[44m");
            break;
    }
}		  


void cTtyStatus::Recording(const cDevice *Device, const char *Name)
{
    set_pos(24, 0);
    if (Name)
    {
        set_color(BLACK_GREEN);
        print("     Card %d:  Recording '%s'%-60s",
              Device->CardIndex()+1, Name, "");
    }
    else
    {
        set_color(WHITE_BLACK);
        print("%-80s", "");
    }
    refresh();
    set_pos(2, 0);
}


void cTtyStatus::Replaying(const cControl *Control, const char *Name)
{
    set_pos(24, 0);
    if (Name)
    {
        set_color(BLACK_GREEN);
        print("     Playing '%s'%-70s", Name, "");
    }
    else
    {
        set_color(WHITE_BLACK);
        print("%-80s", "");
    }
    refresh();
    set_pos(2, 0);
}


void cTtyStatus::SetVolume(int Volume, bool Absolute)
{
    // dsyslog("%s: vol %d abs %d", __FUNCTION__, Volume, Absolute);

    set_pos(24, 0);
    set_color(BLACK_GREEN);
    print("     Set volume %d %-70s", Volume, Absolute ? "(muted)" : "");
    refresh();
    set_pos(2, 0);
}


void cTtyStatus::OsdClear(void)
{
    clear_screen();
    refresh();
}


void cTtyStatus::OsdTitle(const char *Title)
{
    // dsyslog("%s: '%s'", __FUNCTION__, Title);

    clear_screen();
    set_color(BLACK_CYAN);
    set_pos(0, 0);
    print("     %-80s", Title);
    set_color(WHITE_BLACK);
    refresh();
    set_pos(2, 0);
    memset (lineBuf, 0, numEntries * sizeof(char *));
}


void cTtyStatus::OsdStatusMessage(const char *Message)
{
    set_pos(23,0);
    if (Message)
    {
        set_color(BLACK_YELLOW);
        print("     %-80s", Message);
    }
    else
    {
        set_color(WHITE_BLACK);
        print("%-80s", "");
    }
    refresh();
    set_pos(2, 0);
}


void cTtyStatus::OsdHelpKeys(const char *Red, const char *Green,
                             const char *Yellow, const char *Blue)
{
    if (Red)
    {
        set_color(BLACK_RED);
        set_pos(24,0);
        print("     %-15s", Red);
    }
    if (Green)
    {
        set_color(BLACK_GREEN);
        set_pos(24,20);
        print("     %-15s", Green);
    }
    if (Yellow)
    {
        set_color(BLACK_YELLOW);
        set_pos(24,40);
        print("     %-15s", Yellow);
    }
    if (Blue)
    {
        set_color(WHITE_BLUE);
        set_pos(24,60);
        print("     %-15s", Blue);
    }
    refresh();
    set_pos(2, 0);
}


void cTtyStatus::OsdItem(const char *Text, int Index)
{
    // dsyslog("%s[%4d]: '%s'", __FUNCTION__, Index, Text);

    if (numEntries <= Index)
    {
        int oldNumEntries = numEntries;
        numEntries = Index + 100;
        lineBuf = (const char **) realloc((void *)lineBuf, numEntries * sizeof(char *));
        if (lineBuf == NULL)
        {
            numEntries = 0;
            return;
        }
        for (int i = oldNumEntries; i < numEntries; i++)
            lineBuf[i] = NULL;
    }

    if (Text && 0 <= Index && Index < numEntries)
    {
        lineBuf[Index] = Text;
        lastIndex = Index;
    }
}


void cTtyStatus::OsdCurrentItem(const char *Text)
{
    int i;
    int first, last;
  
    // dsyslog("%s: '%s'", __FUNCTION__, Text);

    if (numEntries > 0 && Text)
    {
        for (i = 0; i <= lastIndex; i++)
        {
            if (lineBuf[i] == NULL)
                continue;
            if (strcmp(Text, lineBuf[i]) == 0)
                break;
        }

        if (i <= lastIndex)
        {
            // found
            currIndex = i;
        }
        else
        {
            // not found, item changed
            lineBuf[currIndex] = Text;
        }

        first = min(currIndex-10,lastIndex-20);
        first = max(first,0);
        last = min(first+20,lastIndex);

        set_color(WHITE_BLACK);
        for (i = first; i <= last; i++)
        {
            if (i == currIndex)
                set_color(BLACK_CYAN);
            set_pos(2+i-first, 0);
            print("%-80s", lineBuf[i]);
            if (i == currIndex)
                set_color(WHITE_BLACK);
        }
        set_color(WHITE_BLACK);
        refresh();
    }
}

void cTtyStatus::OsdTextItem(const char *Text, bool Scroll)
{
    // dsyslog("%s: '%s' scroll %d", __FUNCTION__, Text, Scroll);

    if (Text)
    {
        set_color(CYAN_BLACK);
        display2(Text);
        display2("\n\n");
        refresh();
    }
    else
    {
        set_pos(2, 0);
    }
}


void cTtyStatus::OsdChannel(const char *Text)
{
    clear_screen();
    set_color(WHITE_BLACK);
    set_pos(19, 0);
    print("%-80s", Text);
    refresh();
}


void cTtyStatus::OsdProgramme(time_t PresentTime, const char *PresentTitle,
                      const char *PresentSubtitle, time_t FollowingTime,
                      const char *FollowingTitle, const char *FollowingSubtitle)
{
    char buffer[25];
    struct tm tm_r;
    int line = 20;

    strftime(buffer, sizeof(buffer), "%R", localtime_r(&PresentTime, &tm_r));
    if (PresentTitle)
    {
        set_color(YELLOW_BLACK);
        set_pos(line++, 0);
        print("%5s ", buffer);
        set_color(CYAN_BLACK);
        print("%s", PresentTitle);
    }
    if (PresentSubtitle)
    {
        if (strlen(PresentSubtitle))
        {
            set_pos(line++, 0);
            print("%5s %s", "", PresentSubtitle);
        }
    }

    strftime(buffer, sizeof(buffer), "%R", localtime_r(&FollowingTime, &tm_r));
    if (FollowingTitle)
    {
        set_color(YELLOW_BLACK);
        set_pos(line++, 0);
        print("%5s ", buffer);
        set_color(CYAN_BLACK);
        print("%s", FollowingTitle);
    }
    if (FollowingSubtitle)
    {
        set_pos(line++, 0);
        print("%5s %s", "", FollowingSubtitle);
    }

    refresh();
}


cTtyStatus::cTtyStatus(int f)
{
    // initialize variables
    lineBuf = NULL;
    numEntries = 0;
    lastIndex = 0;
    currIndex = 0;
    fd = f;
}


cTtyStatus::~cTtyStatus(void)
{
}
