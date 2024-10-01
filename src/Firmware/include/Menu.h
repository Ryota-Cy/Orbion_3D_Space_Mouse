#ifndef MENU_H
#define MENU_H

#include "DisplayControl.h"
#include "InputHandler.h"
#include "UserSetting.h"

#define DEBOUNCE_DELEY 30

enum MenuItem: int
{
    joySens = 0,
    joyMode,
    butt1Mode,
    butt2Mode,
    butt3Mode,
    setLED,
    setBrightness,
    exitMenu,
    itemCount
};

enum RingStatus: int
{
    neutral,
    up,
    down,
};

void showMainMenu(InputState &inputState, UserSetting &userSetting);

MenuItem& operator ++ (MenuItem& menuItem)
{
    menuItem = static_cast<MenuItem>(menuItem + 1);
    return menuItem;
}

MenuItem& operator ++ (MenuItem& menuItem, int)
{
    MenuItem prev = menuItem;
    ++menuItem;
    return prev;
}

MenuItem& operator -- (MenuItem& menuItem)
{
    menuItem = static_cast<MenuItem>(menuItem - 1);
    return menuItem;
}

MenuItem& operator -- (MenuItem& menuItem, int)
{
    MenuItem prev = menuItem;
    --menuItem;
    return prev;
}
#endif
