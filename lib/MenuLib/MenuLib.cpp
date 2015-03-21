#include "MenuLib.h"
#define DEBUG_SERIAL
MenuLib::MenuLib(LcdColorHelper *helper,char * menuTexts,int menuSize, int backgroundColor, int selectionColor,int textColor) {
    
    items = new MenuItem[menuSize];

    pages = menuSize / 16; //MAXIMA CANTIDAD QUE PUEDO TENER EN CHARS VERTICALES
    this->menuSize = menuSize;

    items[0].text = strtok(menuTexts, ",");
    for(int i = 1; i<menuSize; i++) {
        items[i].text = strtok(NULL, ",");
    }

    this->textColor = textColor;
    this->backgroundColor = backgroundColor;
    this->selectionColor = selectionColor;
    lcdHelper = helper;
}

MenuLib::~MenuLib() {

}

void MenuLib::ClearScren(int color) {
    lcdHelper->lcd.clear(color);
}

void MenuLib::DrawMenu() {
    if(pages == 0) {
        for(int i = 0; i<menuSize; i++) {
            lcdHelper->lcd.setStr(items[i].text, i * 16, 0, textColor, selectionColor);
        }
    }
}