/**
 * @file Encoder.h
 * @brief ロータリーエンコーダーの制御を提供します。
 * @details ロータリーエンコーダーからの入力や回転方向などを読み取ることができます。 @n
 * ハードウェアによってはプッシュスイッチがついているものもありますが、この実装では対象外です。
 */

#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

/**
 * @brief ロータリーエンコーダーの状態を管理する構造体
 * @details ロータリーエンコーダーの回転方向などを扱うことができます。 @n
 *
 * @param pinA : トリガーPIN
 * @param pinB : データPIN
 * @param position : 現在の位置情報を持ちます。
 */
struct Encoder {
    int pinA;
    int pinB;
    int position;
};

/**
 * @brief ロータリーエンコーダーの初期化を行います。
 * @details ロータリーエンコーダーとして使用する構造体とPINの初期化を行います。 @n
 *
 * @param encoder : ロータリーエンコーダーの状態を管理する構造体
 * @param pinA : トリガーPIN
 * @param pinB : データPIN
 */
void initEncoder(Encoder &encoder, int pinA, int pinB);

/**
 * @brief 構造体の状態を現在の状態に更新します。
 * @details 構造体を入力すると現在の状態更新されます。 @n
 *
 * @param encoder : 更新対象の構造体。
 */
void updateEncoder(Encoder &encoder);

#endif
