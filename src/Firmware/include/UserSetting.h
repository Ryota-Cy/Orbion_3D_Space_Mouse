#ifndef USERSETTING_H
#define USERSETTING_H

#include <EEPROM.h>
#include "RGBColor.h"
#include <Keyboard.h>

#define USERSETTING_MEMORY_INDEX 0

enum CADMode
{
    MouseMode,
    Autodesk,
    SolidWorkAndEdge,
    Blender,
    Adobe,
    Freecad,
    Rhino,
    ZBrush,
    ANSA,
    Onshape,
    MaxCount,
};

struct UserSetting
{
    bool enabled;
    int joySens;
    CADMode joyMode;
    int joyButton;
    int button1key;
    int button2key;
    int button3key;
    RGBColor pixelColor;
};

UserSetting readUserSetting();
void putUserSetting(UserSetting &userSetting);

CADMode& operator ++ (CADMode& cadMode)
{
    cadMode = static_cast<CADMode>(cadMode + 1);
    return cadMode;
}

CADMode& operator ++ (CADMode& cadMode, int)
{
    CADMode prev = cadMode;
    ++cadMode;
    return prev;
}

CADMode& operator -- (CADMode& cadMode)
{
    cadMode = static_cast<CADMode>(cadMode - 1);
    return cadMode;
}

CADMode& operator -- (CADMode& cadMode, int)
{
    CADMode prev = cadMode;
    --cadMode;
    return prev;
}

#endif
