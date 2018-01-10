looooooooooool
ho hi ha
Wie die Abgabe ausgeführt wird:

Im Ordner "Milestone 2" befinden sich 2 Ordner.
In Snake(Konsole) befindet sich das Spiel Snake konsolenbasiert.
In Snake(UI) befindet sich das Spiel Snake als Ergänzung zu Conway-Spiel-des-Lebens. Als Grundlage wird die Musterlösung benutzt.

Aufgrund von Schwierigkeiten bei der Eingabe über die Tastatur in Snake(UI) und anderen kleinen Problemen mit QT, haben wir uns dazu entschieden, dass Spiel Snake, mit all seinen Regeln, zuerst für die Konsole zu implementieren und erst danach in den zellulären Automaten einzubinden.  
Leider haben wir es nicht geschafft, dass Spiel vollständig auf die Snake(UI) Version zu übertragen.

Ausführung:

Snake(Konsole):
Snake_Konsole.pro mit QT öffnen und dann in QT ausführen.
Programm ausführen und Menu folgen.

Snake(UI):
Die CAbase.pro Datei mit QT öffnen und dann in QT ausführen.
Programm ausführen, den Universe Mode auf Snake stellen, Start drücken.
Nachdem die drücken des Startknopfes ist das klicken mit dem Mauszeiger auf das Spielfeld notwendig, damit eine Steuerung mittels Tastatur möglich ist.
Nun kann man mit den Tasten W = oben, A = links, S = unten und D = rechts,  die Schlange steuern.

Wo evtl. Ergebnisdateien liegen:
-

Wer woran gearbeitet hat:
Aufgabe 1 - 4: Elias, Christopher und Tobias
Vorbesprechung: Christopher, Elias, Tobias
Dokumentation: Christopher, Elias, Tobias
Tests: Christopher, Elias, Tobias
Wir benutzen zur Versionskontrolle einen SubversionServer. Es gibt einen Zugang (nur Lesen) für den Tutor dort kann in Zukunft genauer nachgesehen werden was wer gemacht hat.

Subversion:
Um Subversion mit einem Windowsexplorer verwenden zu können sind folgende Schritte nötig: svnClient herunterladen und installieren: http://www.chip.de/downloads/TortoiseSVN-64-Bit_36441412.html Nachdem Sie das installiert haben brauchen Sie die Daten für den Zugriff auf das Verzeichnis auf dem Server: url= https://srv139.svn-repos.de/dev1238/PrgPrak/ Benutzer= Tutor Kennwort= 12Euer Vorname34


Bekannte Probleme:

Snake(UI):
-Die Schlange ist bunt und bei zunehmender länge wird sie teilweise grau, das kommt von der Implementierung von Conways Game of Life
-Dadurch das wir einen Strongfocus benutzen kann die funktion SpawnNahrung nicht mehr von in der CAbase aufgerufen werden egal wo man sie hinstellt. Wenn man die Tastatureingabe weglässt funktioniert die Funktion einwandfrei.
Um das Problem zu umgehen kann man Manuell neue Nahrung per F-Taste spawnen
-Wenn man den Rand trifft bleibt das Spiel erst 2 Evolutionsschritte später stehen. Das liegt and der Implementierung des 1. Milestones. Damit der Classic Mode einwandfrei weiter läuft wurde das so gelassen.
-Die Schlange wird an einem Festenpunkt gespawnt(25,40) mit einer länge von 5 und bewegt sich nach links. Dh. das Spielfeld sollte entsprechend gewählt werden.



Snake(Konsole):
Die minimale Spielfeldgröße ist 5.





