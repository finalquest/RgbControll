#ifndef _LCD_COLOR_HELPER_LIB_
#define _LCD_COLOR_HELPER_LIB_

#include <Arduino.h>
#include "ColorLCDShield.h"

class LcdColorHelper
{
public:
    LCDShield lcd;

    LcdColorHelper(int lcdType,char contrast,int clearColor);
    ~LcdColorHelper();

    void ClearScreen(int color);
    /* data */
};

#endif