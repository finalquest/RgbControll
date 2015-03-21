#include <Arduino.h>
#include "LcdColorHelper.h"

LcdColorHelper *lcdHelper;

void setup() {
    lcdHelper = new LcdColorHelper(PHILLIPS, 0, RED);
	Serial.begin(115200);
	delay(1000);


    
}

void loop() {

}

