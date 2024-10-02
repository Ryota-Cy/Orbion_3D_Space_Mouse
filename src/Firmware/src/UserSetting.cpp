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
        RGBColor pixelColor ={0, 0, 0};
        UserSetting defaultUserSetting = {
        true,
        8,
        CADMode::MouseMode,
        KEY_LEFT_SHIFT,
        KEY_LEFT_CTRL, 
        KEY_LEFT_ALT,
        KEY_LEFT_SHIFT,
        pixelColor,
        };

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
