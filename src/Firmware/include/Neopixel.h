/**
 * @file Neopixel.h
 * @brief NeoPixel LEDの制御に関する機能を提供します。
 * @details このヘッダーファイルでは、NeoPixel LEDの初期化、色の設定、および表示に関する関数を定義しています。
 */

#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Adafruit_NeoPixel.h>
#include "RGBColor.h" 

/**
 * @def NUMPIXELS
 * @brief 使用するNeoPixel LEDの数を定義します。
 * @details 制御するNeoPixelのLEDの個数を定義します。ここでは7つのLEDを制御します。
 */
#define NUMPIXELS 7       

/**
 * @def LED_PIN
 * @brief NeoPixel LEDが接続されているピンを定義します。
 * @details NeoPixel LEDを制御するために使用するArduinoのピン番号を定義します。@n
 *          ここではピン15が使用されています。
 */
#define LED_PIN   15        

/**
 * @brief NeoPixelの初期化を行います。
 * @details この関数は、NeoPixel LEDのピンとLEDの数を指定して初期化を行います。
 */
void initNeoPixel();

/**
 * @brief NeoPixelの特定のピクセルの色を設定します。
 * @details 指定されたインデックスのNeoPixel LEDの色を、`RGBColor`構造体で渡された値に設定します。
 * 
 * @param pixelIndex : 色を設定するピクセルのインデックス（0から始まる）。
 * @param color : 設定する色を表すRGBColor構造体。
 */
void setNeoPixelColor(int pixelIndex, const RGBColor &color);

/**
 * @brief NeoPixel LEDに設定された色を反映します。
 * @details この関数を呼び出すと、設定された色がNeoPixel LEDに表示されます。
 */
void showNeoPixel();

#endif
