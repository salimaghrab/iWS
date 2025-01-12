#include "..\lib\Business\MesurerTemperatureHumidite\MesurerTemperatureHumidite.hpp"

void MesurerTemperatureHumidite::InitSensor()
{
    // Initialize the temperature and humidity sensor
    tempHumSensor->InitSensorTempHum();
}

TemperatureHumidityData MesurerTemperatureHumidite::getTemperatureHumidityData()
{
    // Retrieve the temperature and humidity data from the sensor
    return tempHumSensor->measureTemperatureHumidity();
}
