/**
 * @file Joystick.h
 * @brief ジョイスティックの操作と状態管理を行う機能を提供します。
 * @details このヘッダーファイルでは、ジョイスティックの初期化と状態の更新に関する関数を定義しています。 @n
 * また、ジョイスティックの状態を管理する構造体も含まれています。
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>
#include "Button.h"

/** 
 * @brief ジョイスティックの状態を管理する構造体です。
 * @details ジョイスティックのX軸とY軸のピン、ボタンの状態、 @n
 * それらのアナログ値やデッドゾーンを管理します。
 * 
 * @param xPin : ジョイスティックのX軸に接続されたピン番号。
 * @param yPin : ジョイスティックのY軸に接続されたピン番号。
 * @param button : ジョイスティックの押し込みボタンの状態を管理します。
 * @param xValue : X軸の現在のアナログ値を表します。
 * @param yValue : Y軸の現在のアナログ値を表します。
 * @param rawXValue : フィルタリングされていないX軸のアナログ値。
 * @param rawYValue : フィルタリングされていないY軸のアナログ値。
 * @param deadZone : ジョイスティックのデッドゾーン（無反応ゾーン）を設定します。
 */
struct Joystick {
    int xPin;      
    int yPin;      
    Button button;
    int xValue;    
    int yValue;    
    int rawXValue; 
    int rawYValue;
    int deadZone;
};

/**
 * @brief ジョイスティックを初期化します。
 * @details ジョイスティックのX軸、Y軸、ボタンを指定されたピンに基づいて初期化し、 @n
 * デッドゾーンも設定します。
 * 
 * @param joystick : 初期化されるジョイスティックの状態を管理する構造体。
 * @param xPin : X軸のピン番号。
 * @param yPin : Y軸のピン番号。
 * @param buttonPin : ボタンに接続されたピン番号。
 * @param deadZone : ジョイスティックのデッドゾーン（無反応ゾーン）を指定します（デフォルトは20）。
 */
void initJoystick(Joystick &joystick, int xPin, int yPin, int buttonPin, int deadZone = 20);

/**
 * @brief ジョイスティックの状態を更新します。
 * @details ジョイスティックのX軸、Y軸、およびボタンの現在の状態を更新します。 @n
 * アナログ値を読み取り、デッドゾーンの処理を行います。
 * ß
 * @param joystick : 更新されるジョイスティックの状態を管理する構造体。
 */
void updateJoystick(Joystick &joystick);

#endif
