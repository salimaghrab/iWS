#pragma once
#include "../Domain/Entity/WindSpeed.hpp"
#include "../Domain/Services/ImeasurerWindSpeed.hpp"
#include <Arduino.h>

class MeasurerWindSpeedImp : public ImeasurerWindSpeed {
private:
    const int pinILS;                 
    const float rayonDesBras;            
    const float facteurEtalonnage;       
    volatile unsigned long nombreDAimant; 
    unsigned long previousTime;          
    float currentSpeed;                  

    static MeasurerWindSpeedImp* instance;  // Singleton instance for ISR
    static void IRAM_ATTR handleInterrupt();

public:
    MeasurerWindSpeedImp(int pin, float rayon, float calibrationFactor);
    void InitSensorWindSpeed() override;
    WindSpeed measureWindSpeed() override;
    void incrementCount(); 
};