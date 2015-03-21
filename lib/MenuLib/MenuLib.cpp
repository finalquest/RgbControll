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

    selectedItemIndex = 0;
}

MenuLib::~MenuLib() {

}

void MenuLib::ClearScren(int color) {
    lcdHelper->lcd.clear(color);
}

void MenuLib::DrawMenu() {
    if(pages == 0) {
        for(int i = 0; i<menuSize; i++) {
            int color = backgroundColor;
            if(selectedItemIndex == i) {
                color = selectionColor;
            }
            lcdHelper->lcd.setStr(items[i].text, i * 16, 0, textColor, color);
        }
    }
}

void MenuLib::IncrementMenuSelection() {
    selectedItemIndex++;
    if(selectedItemIndex > menuSize) {
        selectedItemIndex = 0;
    }
    DrawMenu();
}

void MenuLib::DecrementMenuSelection() {
    selectedItemIndex--;
    if(selectedItemIndex < 0) {
        selectedItemIndex = menuSize;
    }
    DrawMenu();
}