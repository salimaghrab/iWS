
#include "../lib/Domain/Entity/RainfallData.hpp" 

class ImeasurerPluie {
public:
    virtual void InitSensorPluie()=0;  // initialisation de capteur 
    virtual RainfallData measureRainfall() = 0;  // Measure and return rainfall data
};

