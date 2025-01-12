#pragma once

#include "../lib/Domain/Entity/WindData.hpp" 

class ImeasurerVente {
public:
    virtual void InitSensorVente()=0;  // initialisation de capteur 
    virtual WindData measureWind() = 0;  // Measure and return wind data
};

