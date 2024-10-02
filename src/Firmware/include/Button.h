/**
 * @file Button.h
 * @brief ボタンに関する制御を提供します。
 * @details チャタリングの防止処理などが記載されており、ハードに近い部分のみ実装しています。 @n
 * 押された後のロジックに関しては別な部分で処理を行います。
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/** @brief Buttonに関係するデータの構造体です。
 * 
 * @param pin : ﾎﾞタンに対応しているArduinoの入力番号です。
 * @param isPressed : ボタンが押された状態であるかを表現しています。
 * @param lastDebounceTime : 最後に押された時間です。
 * @param debounceDelay : チャタリング防止として、最後に押されてからのディレイ時間を設定します。
 * @param lastButtonState :  ボタンの直前の状態です。
 */
struct Button {
    int pin;               
    bool isPressed;        
    unsigned long lastDebounceTime;  // デバウンス用のタイマー
    unsigned long debounceDelay;     // デバウンスの遅延時間
    bool lastButtonState;            // ボタンの直前の状態
};

/**
 * @brief ボタンの初期化処理を行います。
 * @details 入力されたPin番号とボタン構造体を紐づけます。 @n
 * 例えば、構造体と5が入力された場合、構造体の状態はは5PINの入力で変化するようになります。
 *
 * @param button : ボタンの状態を管理させる構造体
 * @param pin : 入力PIN
 * @param debounceDelay : チャタリング防止のでバウンス時間
 */
void initButton(Button &button, int pin, unsigned long debounceDelay = 50);

/**
 * @brief 現在のボタンの状態を取得します。
 * @details ボタン構造体を渡すと、現在の状態にデータが更新されます。 @n
 *
 * @param button : ボタンの状態を管理している構造体
 */
void updateButton(Button &button);

#endif
