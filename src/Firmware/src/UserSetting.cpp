#include "UserSetting.h"

UserSetting bakupUserSetting;

UserSetting readUserSetting(){
    UserSetting userSetting;
    EEPROM.get(USERSETTING_MEMORY_INDEX, userSetting);

    if(userSetting.enabled){
        bakupUserSetting = userSetting;
        return userSetting;
    }
    else{
        UserSetting defaultUserSetting;
        bakupUserSetting = defaultUserSetting;
        return defaultUserSetting;
    }
}

bool checkUpdateValues(const UserSetting &userSetting){
    if(userSetting.button1key != bakupUserSetting.button1key ||
        userSetting.button2key != bakupUserSetting.button2key ||
        userSetting.button3key != bakupUserSetting.button3key ||
        userSetting.enabled != bakupUserSetting. enabled ||
        userSetting.joyButton != bakupUserSetting.joyButton ||
        userSetting.joyMode != bakupUserSetting.joyMode ||
        userSetting.joySens != bakupUserSetting.joySens ||
        userSetting.pixelColor.toColor() != bakupUserSetting.pixelColor.toColor()){
            return true;
        }
            return false;
}

void putUserSetting(UserSetting &userSetting){
    if(checkUpdateValues(userSetting)){
        EEPROM.put(USERSETTING_MEMORY_INDEX, userSetting);
    }
}

CADMode& operator ++ (CADMode& cadMode)
{
    cadMode = static_cast<CADMode>(cadMode + 1);
    return cadMode;
}

CADMode operator ++ (CADMode& cadMode, int)
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

CADMode operator -- (CADMode& cadMode, int)
{
    CADMode prev = cadMode;
    --cadMode;
    return prev;
}
