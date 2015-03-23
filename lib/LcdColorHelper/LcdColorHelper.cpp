#include "LcdColorHelper.h"

/*extern "C" {
    #include "wiring.h"
}*/

#include "Arduino.h"

LcdColorHelper::LcdColorHelper(int lcdType,char contrast,int clearColor) {

    lcd.init(lcdType);
    lcd.contrast(contrast);
    lcd.clear(clearColor);
}

LcdColorHelper::~LcdColorHelper() {
    
}

void LcdColorHelper::ClearScreen(int color) {
    lcd.clear(color);
}