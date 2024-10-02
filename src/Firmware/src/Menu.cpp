#include "Menu.h"

DelayState joySensDelay = initDelay(300);
DelayState joyModeDelay = initDelay(300);
DelayState buttonModeDelay = initDelay(300);

void setJoySens(InputState &inputState, UserSetting &userSetting, RingStatus status){
    do
    {
        if(isElapsed(joySensDelay)){
            updateInputDevices(inputState);
            if(status == RingStatus::up){
            userSetting.joySens++;
            }
            else if(status == RingStatus::down){
                userSetting.joySens--;
            }
        }

        displayMessage("Sens: " + userSetting.joySens);
    } while (!inputState.joystick.button.isPressed);
}


void setJoyMode(InputState &inputState, UserSetting &userSetting, RingStatus status){
    do
    {
        if(isElapsed(joyModeDelay)){
            updateInputDevices(inputState);
            if(status == RingStatus::up){
                userSetting.joyMode++;
            }
            else if(status == RingStatus::down){
                userSetting.joyMode--;
            }

            if(userSetting.joyMode >= CADMode::MaxCount){
                userSetting.joyMode = CADMode::MouseMode;
            }
        }

        displayMessage("JoyMode: " + userSetting.joyMode);
    } while (!inputState.joystick.button.isPressed);
}


void buttonMode(int buttonIndex,InputState &inputState, 
    UserSetting &userSetting, RingStatus status){
    
    if(isElapsed(buttonModeDelay)){
        int* btn;
        switch (buttonIndex)
        {
        case 1:
            btn = &(userSetting.button1key);
            break;
        case 2:
            btn = &(userSetting.button2key);
            break;
        case 3:
            btn = &(userSetting.button3key);
            break;
        default:
            displayMessage("Error!");
            break;
        }
        
        do
        {
            updateInputDevices(inputState);
            if(status == RingStatus::up){
                *btn++;
            }
            else if(status == RingStatus::down){
                *btn--;
            }

            if(*btn > KEY_RIGHT_GUI){
                *btn = KEY_LEFT_CTRL;
            }

            // TODO 表示する文字列への変換はまた今度。
            displayMessage("Select Button Key");
            displayMessage("Button: " + *btn);

        } while (!inputState.joystick.button.isPressed);
    }
}

bool handleMenuSelection(MenuItem &selection, 
    InputState &inputState, 
    UserSetting &userSetting, 
    int &lastEncoderPosition) {    
        
    updateInputDevices(inputState);
    RingStatus ringStatus = RingStatus::neutral;
    if(inputState.encoder.position > lastEncoderPosition){
        // オーバー/アンダーフローは考えないことにする。
        selection++;
        lastEncoderPosition = inputState.encoder.position;
        ringStatus = RingStatus::up;
    }
    else if (inputState.encoder.position < lastEncoderPosition){
        selection--;
        lastEncoderPosition = inputState.encoder.position;
        ringStatus = RingStatus::down;
    }

    bool buttonIsPressed = inputState.joystick.button.isPressed;
    switch (selection) {
        case MenuItem::joySens :
            displayMessage("Joy Sense");
            if(buttonIsPressed){
                setJoySens(inputState, userSetting, ringStatus);
            }
            break;
        case MenuItem::joyMode :
            displayMessage("Joy Mode");
            if(buttonIsPressed){
                setJoyMode(inputState, userSetting, ringStatus);
            }
            break;
        case MenuItem::butt1Mode :
            displayMessage("Button1 Mode");
            if(buttonIsPressed){
                buttonMode(1, inputState, userSetting, ringStatus);
            }
            break;
        case MenuItem::butt2Mode :
            displayMessage("Button2 Mode");
            if(buttonIsPressed){
                buttonMode(2, inputState, userSetting, ringStatus);
            }
            break;
        case MenuItem::butt3Mode :
            displayMessage("Button3 Mode");
            if(buttonIsPressed){
                buttonMode(3, inputState, userSetting, ringStatus);
            }
            break;
        case MenuItem::setLED :
            displayMessage("LED Setting");
            if(buttonIsPressed){
                // TODO
            }
            break;
        case MenuItem::setBrightness :
            displayMessage("Brightness Setting");
            if(buttonIsPressed){
                // TODO
            }
            break;
        case MenuItem::exitMenu :
            displayMessage("Exit");
            if(buttonIsPressed){
                putUserSetting(userSetting);
                return false;
            }
            break;
        default:
            return false;
            break;
    }

    return true;
}

void showMainMenu(InputState &inputState, UserSetting &userSetting){
    bool menuMode = true;
    MenuItem selection = MenuItem::joySens;
    int lastEncoderPosition = 0;
    int lastDebounceTime = millis();

    do
    {
        if((millis() - lastDebounceTime) > DEBOUNCE_DELAY){
            selection = (MenuItem)(selection % MenuItem::itemCount);
            menuMode = handleMenuSelection(selection, 
                inputState, 
                userSetting, 
                lastEncoderPosition);

            lastDebounceTime = millis();
        }
    } while (menuMode);
}

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