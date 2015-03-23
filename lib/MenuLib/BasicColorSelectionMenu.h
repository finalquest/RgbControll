#ifndef _BASIC_COLOR_SELECTION_
#define _BASIC_COLOR_SELECTION_
#include "MenuLib.h"

class BasicColorSelectionMenu : public MenuLib
{
public:
    BasicColorSelectionMenu(LcdColorHelper *helper);
    ~BasicColorSelectionMenu();

    void DrawMenu();

private:
    int ConvertFullColorToLCD(unsigned long intVal);
    /* data */
};

#endif