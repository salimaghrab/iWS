#include "..\lib\Business\MesurerVente\MesurerVente.hpp"

void MesurerVente::InitSensor()
{
    // Initialize the wind sensor
    ventSensor->InitSensorVente();
}

WindData MesurerVente::getWindData()
{
    // Retrieve the wind data from the sensor
    return ventSensor->measureWind();
}
