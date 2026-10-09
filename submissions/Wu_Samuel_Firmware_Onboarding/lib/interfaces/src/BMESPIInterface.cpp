#include "BMESPIInterface.h"

bool BMESPIInterface::begin() {
    return bme.begin();
}

float BMESPIInterface::readTemp() {
    return bme.readTemperature();
}