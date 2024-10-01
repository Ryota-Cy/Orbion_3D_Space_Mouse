#include "HIDInterface.h"

const RGBColor red = {255, 0, 0};
const RGBColor green = {0, 255, 0};
const RGBColor blue = {0, 0, 255};
const RGBColor yellow = {255, 255, 0};
const RGBColor light_blue = {0, 255, 255};

void onButtonPushd(InputState &inputState, 
    UserSetting &userSetting){
    if (inputState.button1.isPressed) {
        displayMessage("Button 1 Pressed");
        setNeoPixelColor(0, red);
        showNeoPixel();
        Keyboard.press(userSetting.button1key);
    }

    if (inputState.button2.isPressed) {
        displayMessage("Button 2 Pressed");
        setNeoPixelColor(1, green);
        showNeoPixel();
        Keyboard.press(userSetting.button2key);
    }

    if (inputState.button3.isPressed) {
        displayMessage("Button 3 Pressed");
        setNeoPixelColor(2, blue);
        showNeoPixel();
        Keyboard.press(userSetting.button3key);
    }
}

void selectCADMode(UserSetting &userSetting){
    switch (userSetting.joyMode)
    {
      case CADMode::MouseMode :
      break;

      case CADMode::Autodesk :
        Keyboard.press(KEY_LEFT_SHIFT);
        delay(3);
        Mouse.press(MOUSE_MIDDLE);
      break;

      case CADMode::SolidWorkAndEdge :
        Mouse.press(MOUSE_MIDDLE);
      break;

      case CADMode::Blender :
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_LEFT_ALT);
        Mouse.press(MOUSE_MIDDLE);
      break;

      case CADMode::Adobe :
        Keyboard.press(32);
        Mouse.press(MOUSE_LEFT);
      break;

      case CADMode::Freecad :
        Mouse.press(MOUSE_MIDDLE);
        Mouse.press(MOUSE_RIGHT);
      break;

      case CADMode::Rhino :
        Mouse.press(MOUSE_RIGHT);
      break;

      case CADMode::ZBrush :
        Mouse.press(MOUSE_LEFT);
      break;

      case CADMode::ANSA :
        Keyboard.press(KEY_LEFT_CTRL);
        Mouse.press(MOUSE_LEFT);
      break;

      case CADMode::Onshape :
        Mouse.press(MOUSE_RIGHT);
      break;
    }  
}

void sendMessageToHIDDevice(InputState &inputState, 
    UserSetting &userSetting){

    onButtonPushd(inputState, userSetting);
    selectCADMode(userSetting);

    Mouse.move(-1 * (inputState.joystick.xValue / userSetting.joySens),
        (inputState.joystick.yValue / userSetting.joySens), 0);

    if(inputState.joystick.xValue == 0 && inputState.joystick.yValue == 0){
      Keyboard.releaseAll();
    }
}
