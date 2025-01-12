#include "../lib/Domain/Services/ImesurerTempHum.hpp"
class MesurerTemperatureHumidite
{
private:
    ImeasurerTempHum* tempHumSensor; // Interface for temperature and humidity sensor

public:
    MesurerTemperatureHumidite(ImeasurerTempHum* sensor) : tempHumSensor(sensor) {}

    void InitSensor();


    TemperatureHumidityData getTemperatureHumidityData();
 
};
