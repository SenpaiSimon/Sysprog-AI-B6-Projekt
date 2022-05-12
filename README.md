# Sysprog-AI-B6-Projekt

## Entwickler:  
- Anton Kraus
- Simon Obermeier

---

## Referenz 

Dieses Projekt wurde im Rahmen einer Studienarbeit für das Modul **"Systemprogrammierung"** an der Technischen Hochschule Deggendorf im Studiengang **Angewandte Informatik** des 6. Semesters, angelegt. 

---

## Kurzbeschreibung

Dieses Projekt beinhaltet das schreiben eines **Linux Kernel Drivers** für einen **Raspberry PI 4** und eine dazugehörige **User-App**.  
Diese sollen eine **8 * 8 LED-Matrix** ansteuern.   
Weitere Infos dazu werden in der schriftlichen Ausarbeitung des Projekts behandelt.

---

## How to use 

Um die den das Module zu installieren müssen zunächst die Linux Kernel Treiber installiert werden mit dem Befehlen: 
> sudo apt-get install linux-headers-$(uname -r)  
> sudo apt-get upgrade  
> sudo reboot

Danach kann das einfache install-script unter:
> /src/install

ausgeführt werden mit dem Befehl:

> bash install_compile.sh

Dies kompiliert das Kernel Module, installiert es in den Kernel, kompiliert die User-App und startet diese. 

---

### Start User App

Die User App liegt dann unter
> /src/user_app

und kann mit dem Kommando: 
> ./app

ausgeführt werden.

---

### Live Kamera Feed

Um die Matrix Remote zu betrachten wurde ein Script eingerichtet um das Live-Bild der Kamera an einen lokale IP-Adresse zu streamen.

Das Skript liegt unter
> /src/install/

und kann mit:
> bash start_camera_feed.sh

gestartet werden.

Danach kann man auf die angezeigten Hostnamen mit (z.B.) VLC Media Player zugreifen.
