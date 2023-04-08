/*
 * Remote Control plugin for the Video Disk Recorder
 *
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 * Translations provided by:
 * Finnish	Ville Skyttä <ville dot skytta at iki dot fi>
 * French	Pierre Briec <eclipse dot vdr at gmail dot com>
 *  
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
    "Télécommande",
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
    "Appuyez sur une touche pour utiliser un Keymap préchargé",
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
    "Keymap personnalisé va être utilisé",
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
    "Test télécommande - Appuyer et maintenir une touche enfoncée",
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
    "Protocole RC5 détecté",
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
    "Protocole RC5 détecté (signal inversé)",
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
    "Protocole RCMM détecté",
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
    "Protocole RCMM détecté (signal inversé)",
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
    "Aucune télécommande détectée",
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
    "Erreur chargement tables de touches",
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
    "%s: %s",
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
