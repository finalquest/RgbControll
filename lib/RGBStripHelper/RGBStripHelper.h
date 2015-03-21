#ifndef _RBG_STRIP_HELPE_LIB_
#define _RBG_STRIP_HELPE_LIB_

#include <Arduino.h>

class RGBStripHelper
{
public:

    byte pinR, pinG, pinB;
    byte colorR, colorG, colorB;
    byte brightness;

    RGBStripHelper(byte pinR, byte pinG, byte pinB);
    ~RGBStripHelper();

    void LongToRGB(unsigned long value);
    void setColor(byte red,byte green,byte blue);
    /* data */
    void WriteColorToPins();
    void DefaultOn();
    void TurnOff();
    
};

#endif