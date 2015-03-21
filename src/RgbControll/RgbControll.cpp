#include <Arduino.h>
#include "MenuLib.h"

LcdColorHelper *lcdHelper;
MenuLib *menuHelper;

/*

EL MAXIMO LARGO DE UN TITULO DE MENU TIENE QUE SER 16 CHARS

*/

void setup() {
    lcdHelper = new LcdColorHelper(PHILLIPS, 60, BLUE);
    menuHelper = new MenuLib(lcdHelper,"PRIMER MENU,SEGUNDO MENU,TERCERO,CUARTO,QUINTO,SEXTO,SEPTIMO",7,WHITE,YELLOW,RED);
    menuHelper->ClearScren(YELLOW);
	Serial.begin(115200);
    Serial.println("Arranco");
	delay(1000);
    menuHelper->DrawMenu();
}

void loop() {

}

