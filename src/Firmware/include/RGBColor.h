/**
 * @file RGBColor.h
 * @brief RGBカラーに関するデータ構造および操作を定義しています。
 * @details このヘッダーファイルでは、RGB形式のカラー値を保持し、@n
 *          そのカラーを1つの値に変換する機能を提供します。
 */

#ifndef RGBCOLOR_H
#define RGBCOLOR_H

/**
 * @brief RGBカラーの値を保持する構造体です。
 * @details 各色（赤、緑、青）の値を8ビットで管理し、@n
 *          それらをまとめて1つの32ビット値として取得する関数を提供します。
 * 
 * @param red : 赤色の強度を示す8ビット値（0～255）。
 * @param green : 緑色の強度を示す8ビット値（0～255）。
 * @param blue : 青色の強度を示す8ビット値（0～255）。
 */
struct RGBColor {
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    /**
     * @brief RGB値を1つの32ビット値として返します。
     * @details 赤、緑、青の各色を合成して1つの32ビット値に変換します。
     * 
     * @return 32ビット形式のカラー値。
     */
    uint32_t toColor() const {
        return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
    }
};

#endif
