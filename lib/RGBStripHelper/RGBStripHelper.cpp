#include "RGBStripHelper.h"

RGBStripHelper::RGBStripHelper(byte pinR, byte pinG, byte pinB) {
    this->pinR = pinR;
    this->pinG = pinG;
    this->pinB = pinB;

    this->colorR = 255;
    this->colorG = 255;
    this->colorB = 255;

    brightness = byte(0);

    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
}

RGBStripHelper::~RGBStripHelper() {

}

void RGBStripHelper::LongToRGB(unsigned long value) {
  colorR = value >> 16; 
  colorG = (value >> 8) & 0xFF; 
  colorB = value & 0xFF; 

  WriteColorToPins();
}

void RGBStripHelper::setColor(byte red,byte green,byte blue)
{
  colorR = red;
  colorG = green;
  colorB = blue;
}

void RGBStripHelper::DefaultOn() {
    setColor(255, 255, 255);
    WriteColorToPins();
}

void RGBStripHelper::TurnOff() {
    setColor(0, 0, 0);
    WriteColorToPins();
}

void RGBStripHelper::IncrementBrightness() {
    if(brightness > 0) {
      brightness--;
    }
    WriteColorToPins();
}

void RGBStripHelper::DecrementBrightness() {
    if(brightness < 255) {
      brightness++;
    }
    WriteColorToPins();
}

void RGBStripHelper::WriteColorToPins()
{
  byte colorR;
  byte colorG;
  byte colorB;

  if(this->colorR - brightness < 0)
    colorR = 0;
  else
    colorR = this->colorR  - brightness;

  if(this->colorG - brightness < 0)
    colorG = 0;
  else
    colorG = this->colorG - brightness;

  if(this->colorB - brightness < 0)
    colorB = 0;
  else
    colorB = this->colorB - brightness;

  analogWrite(pinR,colorR);
  analogWrite(pinG,colorG);
  analogWrite(pinB,colorB);
}