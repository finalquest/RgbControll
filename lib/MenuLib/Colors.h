#ifndef _COLORS_
#define _COLORS_

#define FULL_RED            0   
#define FULL_GREEN          FULL_RED + 1
#define FULL_BLUE           FULL_GREEN + 1
#define FULL_WHITE          FULL_BLUE + 1
#define FULL_ORANGE         FULL_WHITE + 1
#define FULL_YELLOW_DARK    FULL_ORANGE + 1
#define FULL_YELLOW_MEDIUM  FULL_YELLOW_DARK + 1
#define FULL_YELLOW_LIGHT   FULL_YELLOW_MEDIUM + 1
#define FULL_GREEN_LIGHT    FULL_YELLOW_LIGHT + 1
#define FULL_GREEN_BLUE1    FULL_GREEN_LIGHT + 1
#define FULL_GREEN_BLUE2    FULL_GREEN_BLUE1 + 1
#define FULL_GREEN_BLUE3    FULL_GREEN_BLUE2 + 1
#define FULL_BLUE_RED       FULL_GREEN_BLUE3 + 1
#define FULL_PURPLE_DARK    FULL_BLUE_RED + 1
#define FULL_PURPLE_LIGHT   FULL_PURPLE_DARK + 1
#define FULL_PINK           FULL_PURPLE_LIGHT + 1
#define COLOR_AMOUNT        FULL_PINK + 1

unsigned long ColorArray[COLOR_AMOUNT] = {      0x00FF0000,
                                                0x0000FF00,
                                                0x000000FF,
                                                0x00FFFFFF,
                                                0x00FF7F00,
                                                0x00FFAA00,
                                                0x00FFD400,
                                                0x00FFFF00,
                                                0x0000FFAA,
                                                0x0000FFFF,
                                                0x0000AAFF,
                                                0x000055FF,
                                                0x00000080,
                                                0x003F0080,
                                                0x007A00BF,
                                                0x00FF00FF};
#endif