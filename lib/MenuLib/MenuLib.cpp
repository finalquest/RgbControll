#include "MenuLib.h"
#define DEBUG_SERIAL
MenuLib::MenuLib(LcdColorHelper *helper,char * menuTexts[],int menuSize, int backgroundColor, int selectionColor,int textColor) {
    
    items = new MenuItem[menuSize];

    pages = menuSize / 16; //MAXIMA CANTIDAD QUE PUEDO TENER EN CHARS VERTICALES
    this->menuSize = menuSize;
    for(int i = 0; i<menuSize; i++) {
        items[i].text = menuTexts[i];
    }

    this->textColor = textColor;
    this->backgroundColor = backgroundColor;
    this->selectionColor = selectionColor;
    lcdHelper = helper;

    selectedItemIndex = 0;
}

MenuLib::MenuLib(LcdColorHelper *helper, int backgroundColor, int selectionColor,int textColor) {
    
    this->textColor = textColor;
    this->backgroundColor = backgroundColor;
    this->selectionColor = selectionColor;
    lcdHelper = helper;

    selectedItemIndex = 0;
    menuSize = 0;
}

MenuLib::MenuLib() {

}

MenuLib::MenuLib(LcdColorHelper *helper) {
    lcdHelper = helper;
}

MenuLib::~MenuLib() {

}

void MenuLib::DrawRGBMenu() {
    for(int i=0;i<131;i++){
        int color = ColorForWell(i, 2);
        lcdHelper->lcd.setLine(i, 0, i, 131, color);
    }
}

void MenuLib::ClearScren(int color) {
    lcdHelper->lcd.clear(color);
}

void MenuLib::ClearScreen() {
    lcdHelper->lcd.clear(backgroundColor);
}

void MenuLib::DrawMenu() {

    if(menuSize == 0) {
        lcdHelper->lcd.setStr(GetMenuString(), 35, 2, textColor, backgroundColor);
    } else {
        if(pages == 0) {
            for(int i = 0; i<menuSize; i++) {
                int color = backgroundColor;
                if(selectedItemIndex == i) {
                    color = selectionColor;
                }       
                Serial.println(GetMenuString(i));
                lcdHelper->lcd.setStr(GetMenuString(i), i * 16, 0, textColor, color);
            }
        }
    } 
}

char * MenuLib::GetMenuString() {
    return "must be implemented";
}

char * MenuLib::GetMenuString(byte index) {
    return items[index].text;
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