#ifndef HIDINTERFACE_H
#define HIDINTERFACE_H

#include <Mouse.h>
#include <Keyboard.h>
#include "UserSetting.h"
#include "InputHandler.h"
#include "DisplayControl.h"
#include "Neopixel.h"

void sendMessageToHIDDevice(InputState &inputState, UserSetting &userSetting);

#endif
