#pragma once
#include "BMEConstants.h"
#include <etl/singleton.h>
#include <math.h>

class LEDController {
    public:
        // built in led, no need to check begin
        void begin();

        void setBlinkInterval(float temperature);
        unsigned long getBlinkInterval() const; // ensure getting only

        // run every loop, contains own millis() count
        void updateLED(unsigned long currentMillis);

    private:
        unsigned long previousMillis;
        unsigned long currentBlinkInterval = BMEConstants::MAX_BLINK_TIME;
};

using LEDControllerInstance = etl::singleton<LEDController>;