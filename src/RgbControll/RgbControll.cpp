#include "MenuLib.h"
#include "BrightnessMenu.h"
#include "RGBStripHelper.h"
#include "BasicColorSelectionMenu.h"

LcdColorHelper *lcdHelper;
MenuLib *mainMenu;
BrightnessMenu *brightnessMenu;
MenuLib *currentMenu;
BasicColorSelectionMenu *colorSelectionMenu;
RGBStripHelper *stripHelper;


/*

EL MAXIMO LARGO DE UN TITULO DE MENU TIENE QUE SER 16 CHARS

*/
int buttonPins[3] = {3, 4, 5};
bool buttonPressed[3] = {false,false,false};
char *menuList[] = {"PRENDER","APAGAR","BRILLO","Sel. Col.","QUINTO","SEXTO","SEPTIMO"};

void setup() {
    lcdHelper = new LcdColorHelper(PHILLIPS, 60, BLUE);

    mainMenu = new MenuLib(lcdHelper,menuList,7,YELLOW,WHITE,RED);
    brightnessMenu = new BrightnessMenu(lcdHelper,YELLOW,WHITE,RED);

    currentMenu = mainMenu;
    currentMenu->ClearScren(YELLOW);
	Serial.begin(115200);
    Serial.println("Arranco");
	delay(1000);
    currentMenu->DrawMenu();
    //currentMenu->DrawRGBMenu();
    for (int i=0; i<3; i++)
    {
        pinMode(buttonPins[i], INPUT);
        digitalWrite(buttonPins[i], HIGH);
    }

    stripHelper = new RGBStripHelper(2, 6, 7);
    //stripHelper->DefaultOn();
}

void loop() {
    if(!digitalRead(buttonPins[0]) && buttonPressed[0] == false) {
        if(currentMenu == brightnessMenu) {
            stripHelper->DecrementBrightness();
            ((BrightnessMenu*)currentMenu)->DrawMenu(stripHelper->brightness);
        } else {
            currentMenu->IncrementMenuSelection();
            buttonPressed[0] = true;
        }
        
    } else if (digitalRead(buttonPins[0]) && buttonPressed[0] == true) {
        buttonPressed[0] = false;
    }

    if(!digitalRead(buttonPins[1]) && buttonPressed[1] == false ) {
        if(currentMenu == brightnessMenu) {
            stripHelper->IncrementBrightness();
            ((BrightnessMenu*)currentMenu)->DrawMenu(stripHelper->brightness);
        } else {
            currentMenu->DecrementMenuSelection();
            buttonPressed[1] = true;
        }
        
    } else if (digitalRead(buttonPins[1]) && buttonPressed[1] == true) {
        buttonPressed[1] = false;
    }

    if(!digitalRead(buttonPins[2]) && buttonPressed[2] == false) {
        buttonPressed[2] = true;
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
            if(currentMenu->selectedItemIndex == 2) {
                currentMenu = (MenuLib*)brightnessMenu;
                currentMenu->ClearScreen();
                ((BrightnessMenu*)currentMenu)->DrawMenu(stripHelper->brightness);
            }
            if(currentMenu->selectedItemIndex == 3) {
                currentMenu = (BasicColorSelectionMenu*)brightnessMenu;
                lcdHelper->ClearScreen(BLACK);
                ((BasicColorSelectionMenu*)currentMenu)->DrawMenu();
            }
        } else if(currentMenu == brightnessMenu) {
            currentMenu = mainMenu;
            currentMenu->ClearScreen();
            currentMenu->DrawMenu();
        }
    } else if (digitalRead(buttonPins[2]) && buttonPressed[2] == true) {
        buttonPressed[2] = false;
    }
}


