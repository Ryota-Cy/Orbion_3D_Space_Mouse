/**
 * @file InputHandler.h
 * @brief 入力デバイスの初期化および更新に関する機能を提供します。
 * @details このヘッダーファイルでは、ボタン、ジョイスティック、エンコーダーなどの入力デバイスの初期化と更新処理を行う関数を定義しています。 @n
 * 様々な入力デバイスの状態を管理するための構造体も含まれています。
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Button.h"
#include "Joystick.h"
#include "Encoder.h"

/** 
 * @brief 各種入力デバイスの状態を保持する構造体です。
 * @details ボタン、ジョイスティック、エンコーダーの状態を管理し、これらのデバイスに対する操作を処理します。
 * 
 * @param button1 : ボタン1の状態を表します。
 * @param button2 : ボタン2の状態を表します。
 * @param button3 : ボタン3の状態を表します。
 * @param joystick : ジョイスティックの状態を管理します。
 * @param encoder : エンコーダーの状態を管理します。
 */
struct InputState {
    Button button1;
    Button button2;
    Button button3;
    Joystick joystick;
    Encoder encoder;
};

/**
 * @brief 入力デバイスを初期化します。
 * @details この関数は、各入力デバイスの初期化を行います。 @n
 * ボタン、ジョイスティック、エンコーダーの初期状態を設定します。
 * 
 * @param input : 初期化される入力デバイスの状態を管理する構造体。
 */
void initInputDevices(InputState &input);

/**
 * @brief 入力デバイスの状態を更新します。
 * @details 各入力デバイスの現在の状態を更新し、@n
 *          ボタンの押下状態やジョイスティックの移動状態、エンコーダーの回転などを管理します。
 * 
 * @param input : 更新される入力デバイスの状態を管理する構造体。
 */
void updateInputDevices(InputState &input);

#endif
