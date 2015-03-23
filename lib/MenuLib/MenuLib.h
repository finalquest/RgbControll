#ifndef _MENU_LIB_
#define _MENU_LIB_
#include "Colors.h"
#include "LcdColorHelper.h"
#include "MenuItem.h"

class MenuLib
{
public:

    MenuItem *items;
    int backgroundColor;
    int selectionColor;
    int textColor;
    int pages;
    int menuSize;
    int selectedItemIndex;

    MenuLib(LcdColorHelper *helper, char *menuTexts[], int menuSize, int backgroundColor, int selectionColor,int textColor);
    MenuLib(LcdColorHelper *helper);
    MenuLib();
    MenuLib(LcdColorHelper *helper, int backgroundColor, int selectionColor,int textColor);
    ~MenuLib();

    void ClearScren(int color);
    void ClearScreen();
    void IncrementMenuSelection();
    void DecrementMenuSelection();
    void DrawMenu();
    void DrawRGBMenu();
    virtual char * GetMenuString(byte index);
    virtual char * GetMenuString();
    LcdColorHelper *lcdHelper;
    /* data */

private:
    long ColorForWell(int well, int totalWells);
};

#endif
