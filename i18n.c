/*
 * Remote Control plugin for the Video Disk Recorder
 *
 * i18n.c: Internationalization
 *
 * Copyright (C) 2002-2012 Oliver Endriss <o.endriss@gmx.de>
 *
 * Translations provided by:
 * Finnish      Ville Skytt� <ville dot skytta at iki dot fi>
 * French       Pierre Briec <eclipse dot vdr at gmail dot com>
 * Italian      Nicola Franchi <franchi at cefriel dot it>
 * Italian      Gringo <vdr-italian@tiscali.it>
 * Polish       Jakub Wolnicki
 * Russian      Waldemar Nikel
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * Or, point your browser to http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
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
    "�������", // Russian
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
    "T�l�commande",
    "",
    "Kaukos��din",
    "Zdalne sterowanie",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "����� ����������",
#endif
  },

  { "Press any key to use pre-loaded keymap",
    "Taste dr�cken, um zuvor geladene Keymap zu verwenden",
    "",
    "Premi un tasto per usare una tabella dei tasti precaricata",
    "",
    "",
    "Appuyez sur une touche pour utiliser un Keymap pr�charg�",
    "",
    "Paina mit� tahansa n�pp�int� k�ytt��ksesi oletusn�pp�inkarttaa",
    "Nacisnij dowolny klawisz, aby uzyc zaladowanej mapy klawiszy",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������� ����� ������ ��� ������������� ����� ���������� ���������",
#endif
  },

  { "User-supplied keymap will be used",
    "Benutzerdefinierte Keymap wird verwendet",
    "",
    "Verr� usata una mappa dei tasti fornita dall'utente",
    "",
    "",
    "Keymap personnalis� va �tre utilis�",
    "",
    "K�ytet��n k�ytt�j�n m��rittelem�� n�pp�inkarttaa",
    "Uzyta zostanie mapa klawiszy, zdefinowana przez uzytkownika",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "����� �������������� ��������� ������������",
#endif
  },


  { "Remote control test - press and hold down any key",
    "Test der Fernbedienung - beliebige Taste gedr�ckt halten",
    "",
    "Prova telecomando - premi e tieni premuto un tasto",
    "",
    "",
    "Test t�l�commande - Appuyer et maintenir une touche enfonc�e",
    "",
    "Kaukos��dintesti - paina ja pid� alhaalla jotain kaukos��timen n�pp�int�",
    "Test zdalnego sterowania - nacisnij i przytrzymaj dowolny klawisz",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "�������� ������ - ������� � �������� ����� ������",
#endif
  },

  { "RC5 protocol detected",
    "RC5-Protokoll erkannt",
    "",
    "Rilevato protocollo RC5",
    "",
    "",
    "Protocole RC5 d�tect�",
    "",
    "RC5-yhteysk�yt�nt� tunnistettu",
    "Wykryto protokol RC5",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������� �������� RC5",
#endif
  },

  { "RC5 protocol detected (inverted signal)",
    "RC5-Protokoll erkannt (invertiertes Signal)",
    "",
    "Rilevato protocollo RC5 (segnale invertito)",
    "",
    "",
    "Protocole RC5 d�tect� (signal invers�)",
    "",
    "RC5-yhteysk�yt�nt� tunnistettu (k��nteinen signaali)",
    "Wykryto protokol RC5 (sygnal odwrocony)",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������� �������� RC5 (� ��������������� �������)",
#endif
  },

  { "RCMM protocol detected",
    "RCMM-Protokoll erkannt",
    "",
    "Rilevato protocollo RCMM",
    "",
    "",
    "Protocole RCMM d�tect�",
    "",
    "RCMM-yhteysk�yt�nt� tunnistettu",
    "Wykryto protokol RCMM",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������� �������� RCMM",
#endif
  },

  { "RCMM protocol detected (inverted signal)",
    "RCMM-Protokoll erkannt (invertiertes Signal)",
    "",
    "Rilevato protocollo RCMM (segnale invertito)",
    "",
    "",
    "Protocole RCMM d�tect� (signal invers�)",
    "",
    "RCMM-yhteysk�yt�nt� tunnistettu (k��nteinen signaali)",
    "Wykryto protokol RCMM (sygnal odwrocony)",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������� �������� RCMM (� ��������������� �������)",
#endif
  },

  { "No remote control detected",
    "Keine Fernbedienung erkannt",
    "",
    "Nessun telecomando rilevato",
    "",
    "",
    "Aucune t�l�commande d�tect�e",
    "",
    "Kaukos��dint� ei tunnistettu",
    "Nie znaleziono zdalnego sterowania",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "����� ���������� �� �������",
#endif
  },

  { "Error uploading keymap",
    "Fehler beim Laden der Tastenbelegung",
    "",
    "Errore caricamento tabella dei tasti",
    "",
    "",
    "Erreur chargement tables de touches",
    "",
    "N�pp�inkartan lataaminen ep�onnistui",
    "Blad przy przesylaniu mapy klawiszy",
    "",
    "",
    "",
    "",
    "",
    "",
#if VDRVERSNUM >= 10302
    "������ ��� �������� ���������",
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
    "%s: %s",
#endif
  },

  { NULL }
  };
