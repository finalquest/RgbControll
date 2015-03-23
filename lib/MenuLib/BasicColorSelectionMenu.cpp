#include "BasicColorSelectionMenu.h"
#include "Colors.h"

BasicColorSelectionMenu::BasicColorSelectionMenu(LcdColorHelper *helper) : MenuLib(helper) {

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