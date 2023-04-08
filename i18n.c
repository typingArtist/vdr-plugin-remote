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
 * Italian	Nicola Franchi <franchi at cefriel dot it>
 * Polish	Jakub Wolnicki
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
    "Telecomando",
    "",
    "",
    "Télécommande",
    "",
    "Kaukosäädin",
    "Zdalne sterowanie",
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
    "Premi un tasto per usare una mappa dei tasti pre-caricata",
    "",
    "",
    "Appuyez sur une touche pour utiliser un Keymap préchargé",
    "",
    "Paina mitä tahansa näppäintä käyttääksesi oletusnäppäinkarttaa",
    "Nacisnij dowolny klawisz, aby uzyc zaladowanej mapy klawiszy",
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
    "Verrà usata una mappa dei tasti fornita dall'utente",
    "",
    "",
    "Keymap personnalisé va être utilisé",
    "",
    "Käytetään käyttäjän määrittelemää näppäinkarttaa",
    "Uzyta zostanie mapa klawiszy, zdefinowana przez uzytkownika",
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
    "Test del telecomando - premi e tieni premuto un tasto",
    "",
    "",
    "Test télécommande - Appuyer et maintenir une touche enfoncée",
    "",
    "Kaukosäädintesti - paina ja pidä alhaalla jotain kaukosäätimen näppäintä",
    "Test zdalnego sterowania - nacisnij i przytrzymaj dowolny klawisz",
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
    "Rilevato il protocollo RC5",
    "",
    "",
    "Protocole RC5 détecté",
    "",
    "RC5-yhteyskäytäntö tunnistettu",
    "Wykryto protokol RC5",
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
    "Rilevato il protocollo RC5 (segnale invertito)",
    "",
    "",
    "Protocole RC5 détecté (signal inversé)",
    "",
    "RC5-yhteyskäytäntö tunnistettu (käänteinen signaali)",
    "Wykryto protokol RC5 (sygnal odwrocony)",
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
    "Rilevato il protocollo RCMM",
    "",
    "",
    "Protocole RCMM détecté",
    "",
    "RCMM-yhteyskäytäntö tunnistettu",
    "Wykryto protokol RCMM",
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
    "Rilevato il protocollo RCMM (segnale invertito)",
    "",
    "",
    "Protocole RCMM détecté (signal inversé)",
    "",
    "RCMM-yhteyskäytäntö tunnistettu (käänteinen signaali)",
    "Wykryto protokol RCMM (sygnal odwrocony)",
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
    "Nessun telecomando rilevato",
    "",
    "",
    "Aucune télécommande détectée",
    "",
    "Kaukosäädintä ei tunnistettu",
    "Nie znaleziono zdalnego sterowania",
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
    "Errore nel caricamento della mappa dei tasti",
    "",
    "",
    "Erreur chargement tables de touches",
    "",
    "Näppäinkartan lataaminen epäonnistui",
    "Blad przy przesylaniu mapy klawiszy",
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
    "%s: %s",
    "",
    "",
    "%s: %s",
    "",
    "%s: %s",
    "%s: %s",
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
