#include "BasicColorSelectionMenu.h"

BasicColorSelectionMenu::BasicColorSelectionMenu(LcdColorHelper *helper) : MenuLib(helper) {
    menuSize = 16;
}

BasicColorSelectionMenu::~BasicColorSelectionMenu() {
    
}

void BasicColorSelectionMenu::DrawMenu() {
    int maxWidth = 131 / 4;
    int maxHeight = maxWidth;

    int cont = 0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            lcdHelper->lcd.setRect(i * maxHeight, j * maxWidth, (i * maxHeight) + maxHeight, (j * maxWidth) + maxWidth, 1,ConvertFullColorToLCD(ColorArray[cont]));
            cont++;
        }   
    }
}

int BasicColorSelectionMenu::ConvertFullColorToLCD(unsigned long intVal) {
    return ((intVal & 0xF00000) >> 12) + ((intVal & 0x00F000) >> 8) + ((intVal & 0x0000F0) >> 4 );
}

void BasicColorSelectionMenu::DrawSelectionBorder() {
    int maxWidth = 131 / 4;
    int row = lastSelectedIndex / 4 ;
    int col = lastSelectedIndex % 4;
    int maxHeight = maxWidth;
    lcdHelper->lcd.setRect(row * maxHeight, col * maxWidth, (row * maxHeight) + maxHeight, (col * maxWidth) + maxWidth, 1,ConvertFullColorToLCD(ColorArray[lastSelectedIndex]));

    row = selectedItemIndex / 4 ;
    col = selectedItemIndex % 4;
    maxHeight = maxWidth;
    lcdHelper->lcd.setRect(row * maxHeight, col * maxWidth, (row * maxHeight) + maxHeight, (col * maxWidth) + maxWidth, 0,BLACK);
    lcdHelper->lcd.setRect((row * maxHeight) + 1, (col * maxWidth) + 1, ((row * maxHeight) + maxHeight) - 1, ((col * maxWidth) + maxWidth - 1), 0,BLACK);
    lcdHelper->lcd.setRect((row * maxHeight) + 2, (col * maxWidth) + 2, ((row * maxHeight) + maxHeight) - 2, ((col * maxWidth) + maxWidth - 2), 0,BLACK);

    lastSelectedIndex = selectedItemIndex;
}