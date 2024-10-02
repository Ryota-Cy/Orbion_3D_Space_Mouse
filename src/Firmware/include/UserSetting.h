/**
 * @file UserSetting.h
 * @brief ユーザー設定に関するデータ構造および操作を定義しています。
 * @details ユーザーが設定したキーやジョイパッド、色などの情報を保持し、変更を保存するための関数を提供します。@n
 *          また、CADモードに関する操作も含まれています。
 */

#ifndef USERSETTING_H
#define USERSETTING_H

#include <EEPROM.h>
#include "RGBColor.h"
#include <Keyboard.h>

/**
 * @def USERSETTING_MEMORY_INDEX
 * @brief EEPROMに保存するユーザー設定の開始アドレスを定義します。
 */
#define USERSETTING_MEMORY_INDEX 0


/**
 * @brief CADモードを列挙する列挙型です。
 * @details さまざまなCADソフトウェアのモードを定義しています。
 */
enum CADMode
{
    MouseMode,
    Autodesk,
    SolidWorkAndEdge,
    Blender,
    Adobe,
    Freecad,
    Rhino,
    ZBrush,
    ANSA,
    Onshape,
    MaxCount,
};

/**
 * @brief ユーザー設定を保持する構造体です。
 * @details 各種設定項目（ボタン、ジョイスティック、ピクセル色など）を保持します。
 * 
 * @param enabled : 設定が有効かどうかを示すフラグ。
 * @param joySens : ジョイスティックの感度設定。
 * @param joyMode : CADモードの設定。
 * @param joyButton : ジョイスティックボタンの設定。
 * @param button1key : ボタン1のキー設定。
 * @param button2key : ボタン2のキー設定。
 * @param button3key : ボタン3のキー設定。
 * @param pixelColor : 画面上のピクセルの色設定。
 */
struct UserSetting
{
    bool enabled;
    int joySens;
    CADMode joyMode;
    int joyButton;
    int button1key;
    int button2key;
    int button3key;
    RGBColor pixelColor;
};

/**
 * @brief ユーザー設定をEEPROMから読み込みます。
 * @details EEPROMに保存されたユーザー設定を読み出し、@n
 *          ユーザーが設定した内容を復元します。
 * 
 * @return 読み込まれたユーザー設定の構造体。
 */
UserSetting readUserSetting();

/**
 * @brief ユーザー設定をEEPROMに保存します。
 * @details 現在のユーザー設定をEEPROMに書き込み、@n
 *          永続的に保存します。
 * 
 * @param userSetting : 保存するユーザー設定構造体。
 */
void putUserSetting(UserSetting &userSetting);

/**
 * @brief CADModeのインクリメント演算子のオーバーロード。
 * @details CADモードを次に進めます。
 * 
 * @param cadMode : 操作対象のCADモード。
 * @return 次のCADモード。
 */
CADMode& operator ++ (CADMode& cadMode)
{
    cadMode = static_cast<CADMode>(cadMode + 1);
    return cadMode;
}

/**
 * @brief CADModeの後置インクリメント演算子のオーバーロード。
 * @details 現在のCADモードを返しつつ、次のCADモードに進めます。
 * 
 * @param cadMode : 操作対象のCADモード。
 * @return 進める前のCADモード。
 */
CADMode& operator ++ (CADMode& cadMode, int)
{
    CADMode prev = cadMode;
    ++cadMode;
    return prev;
}

/**
 * @brief CADModeのデクリメント演算子のオーバーロード。
 * @details CADモードを前に戻します。
 * 
 * @param cadMode : 操作対象のCADモード。
 * @return 前のCADモード。
 */
CADMode& operator -- (CADMode& cadMode)
{
    cadMode = static_cast<CADMode>(cadMode - 1);
    return cadMode;
}

/**
 * @brief CADModeの後置デクリメント演算子のオーバーロード。
 * @details 現在のCADモードを返しつつ、前のCADモードに戻します。
 * 
 * @param cadMode : 操作対象のCADモード。
 * @return 戻す前のCADモード。
 */
CADMode& operator -- (CADMode& cadMode, int)
{
    CADMode prev = cadMode;
    --cadMode;
    return prev;
}

#endif
