#pragma once
#include "BMEConstants.h"
#include <Adafruit_BME280.h>
#include <etl/singleton.h>

class BMESPIInterface {
    friend class etl::singleton<BMESPIInterface>;
    public:
        // prevent copying or cloning
        BMESPIInterface(const BMESPIInterface&) = delete;
        BMESPIInterface& operator=(const BMESPIInterface&) = delete;
        
        bool begin();
        float readTemp();
    
    private:
        BMESPIInterface() = default;
        Adafruit_BME280 bme;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;