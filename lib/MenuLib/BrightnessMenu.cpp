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

/*char* BrightnessMenu::GetMenuString(byte index) {
    
    char integer_string[3];
    sprintf(integer_string, "%d", 255 - 12);
    Serial.println(items[0].text);
    Serial.println(strcat(items[0].text, integer_string));
    return strcat(items[0].text, integer_string);
}*/
char * BrightnessMenu::GetMenuString() {
    if(buffer != NULL) {
        Serial.println("NULLLLL");
        delete buffer;   
    }

    buffer = new char[16];
    sprintf(buffer, "Brillo: %d ",(255 - brightness));
    return buffer;
}

