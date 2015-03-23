#include "BrightnessMenu.h"


BrightnessMenu::BrightnessMenu(LcdColorHelper *helper,int backgroundColor, int selectionColor,int textColor) : MenuLib(helper,backgroundColor,selectionColor,textColor) {
    buffer = NULL;
}

BrightnessMenu::~BrightnessMenu() {
}

void BrightnessMenu::DrawMenu(byte brightness) {
    this->brightness = brightness;
    MenuLib::DrawMenu();
}

char * BrightnessMenu::GetMenuString() {
    if(buffer != NULL) {
        Serial.println("NULLLLL");
        delete buffer;   
    }

    buffer = new char[16];
    sprintf(buffer, "Brillo: %d ",(255 - brightness));
    return buffer;
}

