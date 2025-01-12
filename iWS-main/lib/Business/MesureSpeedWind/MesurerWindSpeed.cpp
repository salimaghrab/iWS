#include "..\lib\Business\MesureSpeedWind\MesurerWindSpeed.hpp"

void MesurerWindSpeed::InitSensor()
{
    // Initialize the wind speed sensor
    windSpeedSensor->InitSensorWindSpeed();
}

WindSpeed MesurerWindSpeed::getWindSpeedData()
{
    // Retrieve the wind speed data from the sensor
    return windSpeedSensor->measureWindSpeed();
}
