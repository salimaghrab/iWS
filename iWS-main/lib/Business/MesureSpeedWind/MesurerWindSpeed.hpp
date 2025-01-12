#include "../lib/Domain/Services/ImeasurerWindSpeed.hpp"

class MesurerWindSpeed
{
private:
    ImeasurerWindSpeed* windSpeedSensor; // Interface for the wind speed sensor

public:
    MesurerWindSpeed(ImeasurerWindSpeed* sensor) : windSpeedSensor(sensor) {}

    void InitSensor(); // Initialize the sensor
    WindSpeed getWindSpeedData(); // Retrieve wind speed data
};
