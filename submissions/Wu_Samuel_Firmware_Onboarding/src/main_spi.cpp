#include "BMEConstants.h"
#include "BMESPIInterface.h"
#include "LEDController.h"

// millis implementation; start at 0
unsigned long previousMillis = 0;

void setup() {
    // init communication at 115200 bits per second; monitor rate from platformio.ini
    Serial.begin(115200);

    LEDControllerInstance::create();
    LEDControllerInstance::instance().begin();

    BMESPIInterfaceInstance::create();
    if (!BMESPIInterfaceInstance::instance().begin()) {
        Serial.println(F("main_spi.cpp | [ERROR] BME280 not found, check wiring"));
        while (true) {}
    }

    Serial.println(F("main_spi.cpp | [READY] LED and BME280 ready"));
}

void loop() {
    unsigned long currentMillis = millis();

    // if a second passes, run the code within
    if (currentMillis - previousMillis >= BMEConstants::BME280_INTERVAL) {
        previousMillis = currentMillis;

        // get temp and set blink interval every second
        const float temperature = BMESPIInterfaceInstance::instance().readTemp();
        LEDControllerInstance::instance().setBlinkInterval(temperature);

        // print temp in c
        Serial.print(F("Temperature = "));
        Serial.print(temperature);
        Serial.println(" *C");

        // print blink interval in ms
        Serial.print(F("Blink Interval = "));
        Serial.print(LEDControllerInstance::instance().getBlinkInterval());
        Serial.println(" ms");
    }

    // attempt every loop to update LED
    LEDControllerInstance::instance().updateLED(currentMillis);
}