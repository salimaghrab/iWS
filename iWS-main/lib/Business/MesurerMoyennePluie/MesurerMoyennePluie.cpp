#include "..\lib\Business\MesurerMoyennePluie\MesurerMoyennePluie.hpp"

void MesurerPluie::InitSensor()
{
    // Initialize the rainfall sensor
    pluieSensor->InitSensorPluie();
}

RainfallData MesurerPluie::getRainfallData()
{
    // Retrieve the rainfall data from the sensor
    return pluieSensor->measureRainfall();
}
