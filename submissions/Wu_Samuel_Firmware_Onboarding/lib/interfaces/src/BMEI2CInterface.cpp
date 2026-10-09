#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin() {
    // Adafruit BME280 address is typically 0x77, but some boards use 0x76
    return bme.begin(BME280_ADDRESS) || bme.begin(BME280_ADDRESS_ALTERNATE);
}

float BMEI2CInterface::readTemp() {
    // no need to use getEvent(), only use that for larger projects w interchangable parts
    return bme.readTemperature();
}
