/*
 * Remote Control plugin for the Video Disk Recorder
 *
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 * Translations provided by:
 */

#include "i18n.h"

/* 
  // The name of the language (this MUST be the first phrase!):
  { "English",
    "Deutsch",
    "Slovenski",
    "Italiano",
    "Nederlands",
    "Português",
    "Français",
    "Norsk",
    "suomi",
    "Polski",
    "Español",
    "Ellinika",
    "Svenska",
    "Romaneste",
    "Magyar",
    "Català",
    "ÀaááÚØÙ", // Russian
  },
*/

const tI18nPhrase remotePhrases[] = {

  // Menu titles:
  { "Remote control",
    "Fernbedienung",
    "",
    "",
    "",
    "",
    "",
    "",
    "Kaukosäädin",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "Press any key to use pre-loaded keymap",
    "Taste drücken, um zuvor geladene Keymap zu verwenden",
    "",
    "",
    "",
    "",
    "",
    "",
    "Paina mitä tahansa näppäintä käyttääksesi oletusnäppäinkarttaa",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "User-supplied keymap will be used",
    "Benutzerdefinierte Keymap wird verwendet",
    "",
    "",
    "",
    "",
    "",
    "",
    "Käytetään käyttäjän määrittelemää näppäinkarttaa",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },


  { "Remote control test - press and hold down any key",
    "Test der Fernbedienung - beliebige Taste gedrückt halten",
    "",
    "",
    "",
    "",
    "",
    "",
    "Kaukosäädintesti - paina ja pidä alhaalla jotain kaukosäätimen näppäintä",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "RC5 protocol detected",
    "RC5-Protokoll erkannt",
    "",
    "",
    "",
    "",
    "",
    "",
    "RC5-yhteyskäytäntö tunnistettu",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "RC5 protocol detected (inverted signal)",
    "RC5-Protokoll erkannt (invertiertes Signal)",
    "",
    "",
    "",
    "",
    "",
    "",
    "RC5-yhteyskäytäntö tunnistettu (käänteinen signaali)",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "RCMM protocol detected",
    "RCMM-Protokoll erkannt",
    "",
    "",
    "",
    "",
    "",
    "",
    "RCMM-yhteyskäytäntö tunnistettu",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "RCMM protocol detected (inverted signal)",
    "RCMM-Protokoll erkannt (invertiertes Signal)",
    "",
    "",
    "",
    "",
    "",
    "",
    "RCMM-yhteyskäytäntö tunnistettu (käänteinen signaali)",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "No remote control detected",
    "Keine Fernbedienung erkannt",
    "",
    "",
    "",
    "",
    "",
    "",
    "Kaukosäädintä ei tunnistettu",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "Error uploading keymap",
    "Fehler beim Laden der Tastenbelegung",
    "",
    "",
    "",
    "",
    "",
    "",
    "Näppäinkartan lataaminen epäonnistui",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { "%s: %s",
    "%s: %s",
    "",
    "",
    "",
    "",
    "",
    "",
    "%s: %s",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "",
#endif
  },

  { NULL }
  };
