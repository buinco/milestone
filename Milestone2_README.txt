looooooooooool
ho hi ha
Wie die Abgabe ausgef�hrt wird:

Im Ordner "Milestone 2" befinden sich 2 Ordner.
In Snake(Konsole) befindet sich das Spiel Snake konsolenbasiert.
In Snake(UI) befindet sich das Spiel Snake als Erg�nzung zu Conway-Spiel-des-Lebens. Als Grundlage wird die Musterl�sung benutzt.

Aufgrund von Schwierigkeiten bei der Eingabe �ber die Tastatur in Snake(UI) und anderen kleinen Problemen mit QT, haben wir uns dazu entschieden, dass Spiel Snake, mit all seinen Regeln, zuerst f�r die Konsole zu implementieren und erst danach in den zellul�ren Automaten einzubinden.  
Leider haben wir es nicht geschafft, dass Spiel vollst�ndig auf die Snake(UI) Version zu �bertragen.

Ausf�hrung:

Snake(Konsole):
Snake_Konsole.pro mit QT �ffnen und dann in QT ausf�hren.
Programm ausf�hren und Menu folgen.

Snake(UI):
Die CAbase.pro Datei mit QT �ffnen und dann in QT ausf�hren.
Programm ausf�hren, den Universe Mode auf Snake stellen, Start dr�cken.
Nachdem die dr�cken des Startknopfes ist das klicken mit dem Mauszeiger auf das Spielfeld notwendig, damit eine Steuerung mittels Tastatur m�glich ist.
Nun kann man mit den Tasten W = oben, A = links, S = unten und D = rechts,  die Schlange steuern.

Wo evtl. Ergebnisdateien liegen:
-

Wer woran gearbeitet hat:
Aufgabe 1 - 4: Elias, Christopher und Tobias
Vorbesprechung: Christopher, Elias, Tobias
Dokumentation: Christopher, Elias, Tobias
Tests: Christopher, Elias, Tobias
Wir benutzen zur Versionskontrolle einen SubversionServer. Es gibt einen Zugang (nur Lesen) f�r den Tutor dort kann in Zukunft genauer nachgesehen werden was wer gemacht hat.

Subversion:
Um Subversion mit einem Windowsexplorer verwenden zu k�nnen sind folgende Schritte n�tig: svnClient herunterladen und installieren: http://www.chip.de/downloads/TortoiseSVN-64-Bit_36441412.html Nachdem Sie das installiert haben brauchen Sie die Daten f�r den Zugriff auf das Verzeichnis auf dem Server: url= https://srv139.svn-repos.de/dev1238/PrgPrak/ Benutzer= Tutor Kennwort= 12Euer Vorname34


Bekannte Probleme:

Snake(UI):
-Die Schlange ist bunt und bei zunehmender l�nge wird sie teilweise grau, das kommt von der Implementierung von Conways Game of Life
-Dadurch das wir einen Strongfocus benutzen kann die funktion SpawnNahrung nicht mehr von in der CAbase aufgerufen werden egal wo man sie hinstellt. Wenn man die Tastatureingabe wegl�sst funktioniert die Funktion einwandfrei.
Um das Problem zu umgehen kann man Manuell neue Nahrung per F-Taste spawnen
-Wenn man den Rand trifft bleibt das Spiel erst 2 Evolutionsschritte sp�ter stehen. Das liegt and der Implementierung des 1. Milestones. Damit der Classic Mode einwandfrei weiter l�uft wurde das so gelassen.
-Die Schlange wird an einem Festenpunkt gespawnt(25,40) mit einer l�nge von 5 und bewegt sich nach links. Dh. das Spielfeld sollte entsprechend gew�hlt werden.



Snake(Konsole):
Die minimale Spielfeldgr��e ist 5.





