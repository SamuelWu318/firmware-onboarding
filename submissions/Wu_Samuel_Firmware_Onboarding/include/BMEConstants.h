#pragma once
#include <Arduino.h>

namespace BMEConstants {
    constexpr unsigned long BME280_INTERVAL = 1000;

    // highest and lowest times between blink
    constexpr uint16_t MAX_BLINK_TIME = 1000;
    constexpr uint16_t MIN_BLINK_TIME = 67;

    // temp boundaries to prevent neg temp calculations
    constexpr float MIN_TEMP = 0.0f;
    constexpr float MAX_TEMP = 65.0f;

    // pins and stuff (SPI 10 default)
    constexpr uint8_t CS_PIN = 10;
}