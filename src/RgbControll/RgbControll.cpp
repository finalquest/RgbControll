#include <Arduino.h>
#include "MenuLib.h"

LcdColorHelper *lcdHelper;
MenuLib *menuHelper;

/*

EL MAXIMO LARGO DE UN TITULO DE MENU TIENE QUE SER 16 CHARS

*/
int buttonPins[3] = {3, 4, 5};

void setup() {
    lcdHelper = new LcdColorHelper(PHILLIPS, 60, BLUE);
    menuHelper = new MenuLib(lcdHelper,"PRIMER MENU,SEGUNDO MENU,TERCERO,CUARTO,QUINTO,SEXTO,SEPTIMO",7,YELLOW,WHITE,RED);
    menuHelper->ClearScren(YELLOW);
	Serial.begin(115200);
    Serial.println("Arranco");
	delay(1000);
    menuHelper->DrawMenu();

    for (int i=0; i<3; i++)
    {
        pinMode(buttonPins[i], INPUT);
        digitalWrite(buttonPins[i], HIGH);
    }
}

void loop() {
    if(!digitalRead(buttonPins[0])) {
        menuHelper->DecrementMenuSelection();
    }

    if(!digitalRead(buttonPins[1])) {
        menuHelper->IncrementMenuSelection();
    }
}

