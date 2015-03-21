#include "MenuLib.h"
#include "RGBStripHelper.h"

LcdColorHelper *lcdHelper;
MenuLib *mainMenu;
MenuLib *currentMenu;
RGBStripHelper *stripHelper;


/*

EL MAXIMO LARGO DE UN TITULO DE MENU TIENE QUE SER 16 CHARS

*/
int buttonPins[3] = {3, 4, 5};

void setup() {
    lcdHelper = new LcdColorHelper(PHILLIPS, 60, BLUE);
    mainMenu = new MenuLib(lcdHelper,"PRENDER,APAGAR,TERCERO,CUARTO,QUINTO,SEXTO,SEPTIMO",7,YELLOW,WHITE,RED);
    currentMenu = mainMenu;
    currentMenu->ClearScren(YELLOW);
	Serial.begin(115200);
    Serial.println("Arranco");
	delay(1000);
    currentMenu->DrawMenu();

    for (int i=0; i<3; i++)
    {
        pinMode(buttonPins[i], INPUT);
        digitalWrite(buttonPins[i], HIGH);
    }

    stripHelper = new RGBStripHelper(2, 6, 7);
    //stripHelper->DefaultOn();
}

void loop() {
    if(!digitalRead(buttonPins[0])) {
        currentMenu->DecrementMenuSelection();
    }

    if(!digitalRead(buttonPins[1])) {
        currentMenu->IncrementMenuSelection();
    }

    if(!digitalRead(buttonPins[2])) {
        Serial.println("Accion");
        if(currentMenu == mainMenu) {
            Serial.println("IGUALES");
            if(currentMenu->selectedItemIndex == 0) {
                Serial.println("APAGO");
                stripHelper->DefaultOn();
            }
            if(currentMenu->selectedItemIndex == 1) {
                Serial.println("APAGO");
                stripHelper->TurnOff();
            }
        }
    }
}


