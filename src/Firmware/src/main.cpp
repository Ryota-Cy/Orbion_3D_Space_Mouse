/**********************************************************************************************/
/*	                                      Orbion Firmware                                     */
/**********************************************************************************************/
/*                                        version 0.26.5                                      */
/*                                       Since: June 2021                                     */
/*                                Creator: Mattia Russo (FaqTotum)                            */
/**********************************************************************************************/
/*                                           LICENSE                                          */
/*                                                                                            */
/*                                      (CC BY-NC-ND 4.0)                                     */
/*               CC - Attribution-NonCommercial-NoDerivatives 4.0 International               */
/**********************************************************************************************/

#include <Arduino.h>
#include "DisplayControl.h"
#include "InputHandler.h"
#include "Menu.h"
#include "Neopixel.h"
#include "UserSetting.h"
#include "HIDInterface.h"

InputState inputState;
UserSetting userSetting;

void setup() {
    initDisplay();
    initInputDevices(inputState);
    initNeoPixel();
    userSetting = readUserSetting();
}

void loop() {
    updateInputDevices(inputState);
    sendMessageToHIDDevice(inputState, userSetting);
    
    if(inputState.button1.isPressed && inputState.joystick.button.isPressed){
        showMainMenu(inputState, userSetting);
        userSetting = readUserSetting();
        delay(100);
    }

    // TODO  Time out Display 
    
}
