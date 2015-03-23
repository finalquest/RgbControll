#include "MenuLib.h"

class BrightnessMenu : public MenuLib 
{
public:

    char *buffer;
    byte brightness;

    BrightnessMenu(LcdColorHelper *helper,int backgroundColor, int selectionColor,int textColor);
    ~BrightnessMenu();

    void DrawMenu(byte brightness);
    char * GetMenuString();
    /* data */
};