#include <Arduino.h>
#include <unity.h>
#include "Button.h"
#include "Joystick.h"
#include "Neopixel.h"
#include "RGBColor.h"

// テスト用のピン設定（仮）
#define TEST_PIN_BUTTON 7
#define TEST_PIN_JOYSTICK_X A2
#define TEST_PIN_JOYSTICK_Y A3
#define TEST_PIN_LED 15

// Arrange: テスト対象となるボタン、ジョイスティック、RGB色の変数を定義
Button testButton;
Joystick testJoystick;
RGBColor testColor = {255, 0, 0};  // 赤色

// ボタンのピン設定をテスト
void test_button_pin_init() {
    // Arrange
    initButton(testButton, TEST_PIN_BUTTON);

    // Act
    int actualPin = testButton.pin;

    // Assert
    TEST_ASSERT_EQUAL(TEST_PIN_BUTTON, actualPin);  // Assert: ピン番号が正しく設定されているか
}

// ボタンの初期状態をテスト
void test_button_initial_state() {
    // Arrange
    initButton(testButton, TEST_PIN_BUTTON);

    // Act
    bool isPressed = testButton.isPressed;

    // Assert
    TEST_ASSERT_FALSE(isPressed);  // Assert: 初期状態では押されていないこと
}

// ジョイスティックのX軸ピン設定をテスト
void test_joystick_x_pin_init() {
    // Arrange
    initJoystick(testJoystick, TEST_PIN_JOYSTICK_X, TEST_PIN_JOYSTICK_Y);

    // Act
    int actualPinX = testJoystick.xPin;

    // Assert
    TEST_ASSERT_EQUAL(TEST_PIN_JOYSTICK_X, actualPinX);
}

// ジョイスティックのY軸ピン設定をテスト
void test_joystick_y_pin_init() {
    // Arrange
    initJoystick(testJoystick, TEST_PIN_JOYSTICK_X, TEST_PIN_JOYSTICK_Y);

    // Act
    int actualPinY = testJoystick.yPin;

    // Assert
    TEST_ASSERT_EQUAL(TEST_PIN_JOYSTICK_Y, actualPinY);
}

// ジョイスティックのX軸値が範囲内かテスト
void test_joystick_x_value() {
    // Arrange
    initJoystick(testJoystick, TEST_PIN_JOYSTICK_X, TEST_PIN_JOYSTICK_Y);
    
    // Act
    updateJoystick(testJoystick);
    int xValue = testJoystick.xValue;

    // Assert
    TEST_ASSERT_GREATER_OR_EQUAL(0, xValue);  // X軸の値が0以上であること
    TEST_ASSERT_LESS_OR_EQUAL(1023, xValue);  // X軸の値が1023以下であること
}

// RGBColorの赤色変換をテスト
void test_rgbcolor_red_toColor() {
    // Arrange
    RGBColor redColor = {255, 0, 0};  // 赤色

    // Act
    uint32_t resultColor = redColor.toColor();

    // Assert
    TEST_ASSERT_EQUAL_HEX32(0xFF0000, resultColor);  // 赤色は0xFF0000であること
}

// NeoPixelの色設定が呼び出されるかテスト
void test_neopixel_color_set() {
    // Arrange
    initNeoPixel();
    
    // Act
    setNeoPixelColor(0, testColor);
    showNeoPixel();

    // Assert
    TEST_PASS_MESSAGE("NeoPixelの色が設定されました。目視で確認してください。");
}

// テストのセットアップ
void setup() {
    UNITY_BEGIN();  // Unityの初期化

    // 各テストケースを実行する
    RUN_TEST(test_button_pin_init);
    RUN_TEST(test_button_initial_state);
    RUN_TEST(test_joystick_x_pin_init);
    RUN_TEST(test_joystick_y_pin_init);
    RUN_TEST(test_joystick_x_value);
    RUN_TEST(test_rgbcolor_red_toColor);
    RUN_TEST(test_neopixel_color_set);

    UNITY_END();    // Unityの終了
}

void loop() {
    // ループは不要
}
