/**
 * @file HIDInterface.h
 * @brief HIDデバイスへのメッセージ送信機能を提供するインターフェースです。
 * @details このヘッダーファイルは、ユーザー入力と設定に基づいてHIDデバイス（マウス、キーボードなど）に
 * メッセージを送信する機能を提供します。 @n
 * Mouse、Keyboardライブラリを使用して、HIDデバイスへのコマンドを送信します。
 */

#ifndef HIDINTERFACE_H
#define HIDINTERFACE_H

#include <Mouse.h>
#include <Keyboard.h>
#include "UserSetting.h"
#include "InputHandler.h"
#include "DisplayControl.h"
#include "Neopixel.h"

/**
 * @brief HIDデバイスにメッセージを送信します。
 * @details この関数は、ユーザーの入力状態と設定に基づいてHIDデバイスに対して
 * マウスやキーボードの入力をシミュレートして送信します。 @n
 * 入力状態とユーザー設定に応じたHIDデバイスへの動作が行われます。
 *
 * @param inputState : 現在のユーザー入力の状態を保持する構造体。
 * @param userSetting : 現在のユーザー設定を保持する構造体。
 */
void sendMessageToHIDDevice(InputState &inputState, UserSetting &userSetting);

#endif
