#!/bin/bash
echo "UWAGA: SKRYPT ZABIJA ARDUINO IDE, ABY PRZEŁADOWAĆ BIBLIOTEKI. PRZED URUCHOMIENIEM TEGO SKRYPTU UPEWNIJ SIĘ, ŻE ZAPISAŁEŚ PRACE I JESTEŚ GOTÓW DO URUCHOMIENIA TEGO SKRYPTU!"
read
echo "Kopiowanie bibliotek do katalogu ~/sketchbook"

cp -R * ~/sketchbook/libraries

if [[ -z $IDPROCESS ]]; then
	killall arduino
	nohup arduino &
fi
