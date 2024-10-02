/**
 * @file BlockManager.h
 * @brief 非同期的な遅延処理のためのヘッダファイルです。
 * @details このファイルでは、非同期ブロッキングを実現するために遅延状態を管理し、経過時間を確認するための関数を定義しています。
 */

#ifndef BLOACKMANAGER_H
#define BLOACKMANAGER_H

#include <Arduino.h>

/**
 * @brief 遅延の状態を管理する構造体です。
 * @details この構造体では、前回の実行時刻と遅延の間隔を管理します。
 * 
 * @param lastRunTime : 最後に実行された時刻を記録します。
 * @param interval : 遅延間隔（ミリ秒）を指定します。
 */
struct DelayState {
    unsigned long lastRunTime;
    unsigned long interval;
};

/**
 * @brief 遅延の初期化を行います。
 * @details 指定された遅延時間を設定し、初期状態として最後の実行時間を現在時刻で初期化します。
 * 
 * @param interval : 遅延間隔（ミリ秒）を指定します。
 * @return DelayState : 初期化された遅延状態構造体を返します。
 */
DelayState initDelay(unsigned long interval);

/**
 * @brief 指定された遅延時間が経過したかを確認します。
 * @details 現在の時間と最後に実行された時刻を比較し、指定された遅延間隔が経過していれば `true` を返し、次の実行時刻を更新します。
 * 
 * @param state : 遅延状態を保持する構造体。
 * @return bool : 遅延時間が経過した場合は `true`、そうでない場合は `false` を返します。
 */
bool isElapsed(DelayState &state);

#endif