#pragma once

#include "../lib/Domain/Entity/WindSpeed.hpp"

class ImeasurerWindSpeed {
public:
    virtual void InitSensorWindSpeed() = 0; // Initialize the wind speed sensor
    virtual WindSpeed measureWindSpeed() = 0; // Measure and return wind speed data
};
