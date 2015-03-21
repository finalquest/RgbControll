#ifndef _MENU_LIB_
#define _MENU_LIB_
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

    MenuLib(LcdColorHelper *helper, char *menuTexts, int menuSize, int backgroundColor, int selectionColor,int textColor);
    ~MenuLib();

    void ClearScren(int color);
    void DrawMenu();
    LcdColorHelper *lcdHelper;
    /* data */
};

#endif
