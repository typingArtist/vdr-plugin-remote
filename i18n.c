/*
 * Remote Control plugin for the Video Disk Recorder
 *
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 * Translations provided by:
 * Finnish	Ville Skytt� <ville dot skytta at iki dot fi>
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
    "Portugu�s",
    "Fran�ais",
    "Norsk",
    "suomi",
    "Polski",
    "Espa�ol",
    "Ellinika",
    "Svenska",
    "Romaneste",
    "Magyar",
    "Catal�",
    "�a�����", // Russian
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
    "T�l�commande",
    "",
    "Kaukos��din",
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
    "Taste dr�cken, um zuvor geladene Keymap zu verwenden",
    "",
    "",
    "",
    "",
    "Appuyez sur une touche pour utiliser un Keymap pr�charg�",
    "",
    "Paina mit� tahansa n�pp�int� k�ytt��ksesi oletusn�pp�inkarttaa",
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
    "Keymap personnalis� va �tre utilis�",
    "",
    "K�ytet��n k�ytt�j�n m��rittelem�� n�pp�inkarttaa",
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
    "Test der Fernbedienung - beliebige Taste gedr�ckt halten",
    "",
    "",
    "",
    "",
    "Test t�l�commande - Appuyer et maintenir une touche enfonc�e",
    "",
    "Kaukos��dintesti - paina ja pid� alhaalla jotain kaukos��timen n�pp�int�",
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
    "Protocole RC5 d�tect�",
    "",
    "RC5-yhteysk�yt�nt� tunnistettu",
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
    "Protocole RC5 d�tect� (signal invers�)",
    "",
    "RC5-yhteysk�yt�nt� tunnistettu (k��nteinen signaali)",
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
    "Protocole RCMM d�tect�",
    "",
    "RCMM-yhteysk�yt�nt� tunnistettu",
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
    "Protocole RCMM d�tect� (signal invers�)",
    "",
    "RCMM-yhteysk�yt�nt� tunnistettu (k��nteinen signaali)",
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
    "Aucune t�l�commande d�tect�e",
    "",
    "Kaukos��dint� ei tunnistettu",
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
    "N�pp�inkartan lataaminen ep�onnistui",
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
