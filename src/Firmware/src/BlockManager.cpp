#include "BlockManager.h"

// 遅延の状態を管理する構造体
struct DelayState {
    unsigned long lastRunTime;
    unsigned long interval;
};

// 初期化関数（初期状態を設定）
DelayState initDelay(unsigned long interval) {
    DelayState state;
    state.lastRunTime = millis();
    state.interval = interval;
    return state;
}

// 非同期のブロッキング処理を行う関数
bool isElapsed(DelayState &state) {
    if (millis() - state.lastRunTime >= state.interval) {
        state.lastRunTime = millis();  // 実行されたら時間を更新
        return true;
    }
    return false;
}
