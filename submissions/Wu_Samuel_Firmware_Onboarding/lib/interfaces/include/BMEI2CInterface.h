#pragma once
#include "BMEConstants.h"
#include <Adafruit_BME280.h>
#include <etl/singleton.h>

class BMEI2CInterface {
    // allow ETL to call constructor
    friend class etl::singleton<BMEI2CInterface>;

    public:
        // prevent copying or cloning
        BMEI2CInterface(const BMEI2CInterface&) = delete;
        BMEI2CInterface& operator=(const BMEI2CInterface&) = delete;
        
        // one for setup, one for loop
        bool begin();
        float readTemp();


    private:
        // keep private; singleton behavior ensured
        BMEI2CInterface() = default;
        Adafruit_BME280 bme;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;