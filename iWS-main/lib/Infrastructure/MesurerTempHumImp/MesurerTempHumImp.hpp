#include "../lib/Domain/Services/ImesurerTempHum.hpp"
#include <iostream>
#include <DHT.h>
#include <chrono>
#include <ctime>
class MesurerTempHumImp : public ImeasurerTempHum
{
public:
   MesurerTempHumImp(uint8_t dhtPin, uint8_t dhtType) : dht(dhtPin, dhtType) {}

    void InitSensorTempHum() override;
    TemperatureHumidityData measureTemperatureHumidity() override;

private:

    DHT dht;  // DHT sensor object
    uint8_t dhtPin;  // Pin for the DHT sensor
    uint8_t dhtType;
 
};