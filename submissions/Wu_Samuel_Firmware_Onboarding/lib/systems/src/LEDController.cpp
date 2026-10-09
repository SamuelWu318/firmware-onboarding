#include "LEDController.h"

void LEDController::begin() {
    // connect LED to output
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    previousMillis = millis();
    // set at max for default cuz why not
    currentBlinkInterval = BMEConstants::MAX_BLINK_TIME;
}

// tip: set method info to consts so they will never change
void LEDController::setBlinkInterval(float temperature) {
    if (isnanf(temperature)) { return; }

    const float tempConstrained = constrain(temperature, BMEConstants::MIN_TEMP, BMEConstants::MAX_TEMP);
    // convert to an interval between 0 and 1
    const float ratio = (tempConstrained - BMEConstants::MIN_TEMP) / (BMEConstants::MAX_TEMP - BMEConstants::MIN_TEMP);
    
    currentBlinkInterval = float(BMEConstants::MIN_BLINK_TIME) + ratio * (float(BMEConstants::MAX_BLINK_TIME) - float(BMEConstants::MIN_BLINK_TIME));
}

unsigned long LEDController::getBlinkInterval() const {
    return currentBlinkInterval;
}

// update LED only when the time is right
void LEDController::updateLED(const unsigned long currentMillis) {
    if (currentMillis - previousMillis  >= currentBlinkInterval) {
        previousMillis = currentMillis;
        
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
}