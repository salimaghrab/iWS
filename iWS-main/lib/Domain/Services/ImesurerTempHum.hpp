
#pragma once

#include "../lib/Domain/Entity/TemperatureHumidityData.hpp" 
class ImeasurerTempHum 
{
public:
    virtual void InitSensorTempHum()=0;  // initialisation de capteur 
    virtual TemperatureHumidityData measureTemperatureHumidity() = 0;  // Measure and return temp/humidity data
};

   


   