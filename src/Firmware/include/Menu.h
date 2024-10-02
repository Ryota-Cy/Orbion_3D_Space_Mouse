/**
 * @file Menu.h
 * @brief メニュー表示と操作に関する機能を提供します。
 * @details このヘッダーファイルでは、ユーザーインターフェース用のメニュー項目を定義し、 @n
 * メニューの表示や選択処理に関する関数や演算子のオーバーロードを提供します。
 */

#ifndef MENU_H
#define MENU_H

#include "DisplayControl.h"
#include "InputHandler.h"
#include "UserSetting.h"
#include "BlockManager.h"

/**
 * @def DEBOUNCE_DELAY
 * @brief ボタン入力のデバウンス時間を設定します。
 * @details ボタンが押された際のチャタリング防止のための遅延時間をミリ秒単位で定義します。@n
 *          この時間が経過しないと次の入力が有効になりません。
 */
#define DEBOUNCE_DELAY 30

/**
 * @brief メニュー項目を列挙する列挙型です。
 * @details ユーザーが選択できるメニュー項目を定義します。@n
 *          項目にはジョイスティック感度設定、モード設定、LEDの設定などが含まれます。
 */
enum MenuItem: int
{
    joySens = 0,
    joyMode,
    butt1Mode,
    butt2Mode,
    butt3Mode,
    setLED,
    setBrightness,
    exitMenu,
    itemCount
};

/**
 * @brief メニュー操作の状態を表す列挙型です。
 * @details メニューのリング操作における状態（ニュートラル、上、下）を定義します。
 */
enum RingStatus: int
{
    neutral,
    up,
    down,
};

/**
 * @brief メインメニューを表示します。
 * @details メニューの表示や選択処理を行い、@n
 *          ユーザー入力に基づいてメニュー項目を移動または決定します。
 * 
 * @param inputState : ユーザー入力の状態を保持する構造体。
 * @param userSetting : ユーザーの現在の設定を保持する構造体。
 */
void showMainMenu(InputState &inputState, UserSetting &userSetting);

/**
 * @brief MenuItemのインクリメント演算子のオーバーロード。
 * @details メニュー項目を1つ次に進めます。
 * 
 * @param menuItem : 操作対象のメニュー項目。
 * @return MenuItem : 次のメニュー項目。
 */
MenuItem& operator ++ (MenuItem& menuItem)
{
    menuItem = static_cast<MenuItem>(menuItem + 1);
    return menuItem;
}

/**
 * @brief MenuItemの後置インクリメント演算子のオーバーロード。
 * @details 現在のメニュー項目を返しつつ、メニュー項目を1つ次に進めます。
 * 
 * @param menuItem : 操作対象のメニュー項目。
 * @return MenuItem : 進める前のメニュー項目。
 */
MenuItem& operator ++ (MenuItem& menuItem, int)
{
    MenuItem prev = menuItem;
    ++menuItem;
    return prev;
}

/**
 * @brief MenuItemのデクリメント演算子のオーバーロード。
 * @details メニュー項目を1つ前に戻します。
 * 
 * @param menuItem : 操作対象のメニュー項目。
 * @return MenuItem : 前のメニュー項目。
 */
MenuItem& operator -- (MenuItem& menuItem)
{
    menuItem = static_cast<MenuItem>(menuItem - 1);
    return menuItem;
}

/**
 * @brief MenuItemの後置デクリメント演算子のオーバーロード。
 * @details 現在のメニュー項目を返しつつ、メニュー項目を1つ前に戻します。
 * 
 * @param menuItem : 操作対象のメニュー項目。
 * @return MenuItem : 戻す前のメニュー項目。
 */
MenuItem& operator -- (MenuItem& menuItem, int)
{
    MenuItem prev = menuItem;
    --menuItem;
    return prev;
}
#endif
