/**
 * @file DisplayControl.h
 * @brief OLEDディスプレイの制御を提供します。
 * @details OLEDへの文字越や画像の出力制御などを提供します。 @n
 */

#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/// @def SCREEN_WIDTH
/// @brief 入力するディスプレイの幅
#define SCREEN_WIDTH 128

/// @def SCREEN_HEIGHT
//! @brief 入力するディスプレイの高さ
#define SCREEN_HEIGHT 64

/// @def OLED_RESET
//! @brief RESET入力
#define OLED_RESET -1

/**
 * @brief Displayの初期化を提供します。
 * @details ソースコード上の設定に従いディスプレイを初期化します。 @n
 * ハードウェアの変更がある場合は注意してください。
 */
void initDisplay();

/**
 * @brief 現在表示されているデータをクリアします。
 */
void clearDisplay();

/**
 * @brief Displayに文字列を表示します。
 * @details 入力した文字列をディスプレイに表示します。 @n
 * 複数回の入力は改行されます。
 *
 * @param message : ディスプレイに表示したい文字列データ
 */
void displayMessage(const char* message);

#endif
