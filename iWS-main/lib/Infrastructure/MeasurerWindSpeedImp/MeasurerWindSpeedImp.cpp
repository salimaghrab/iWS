#include "MeasurerWindSpeedImp.hpp"

#define MEASURE_INTERVAL 2000   
#define MAGNETS_PER_ROTATION 2  

MeasurerWindSpeedImp* MeasurerWindSpeedImp::instance = nullptr;

MeasurerWindSpeedImp::MeasurerWindSpeedImp(int pin, float rayon, float calibrationFactor)
    : pinILS(pin)
    , rayonDesBras(rayon)
    , facteurEtalonnage(calibrationFactor)
    , nombreDAimant(0)
    , previousTime(0)
    , currentSpeed(0.0)
{
    instance = this;
}

void IRAM_ATTR MeasurerWindSpeedImp::handleInterrupt() {
    if (instance) {
        instance->incrementCount();
    }
}

void MeasurerWindSpeedImp::incrementCount() {
    nombreDAimant++;
}

void MeasurerWindSpeedImp::InitSensorWindSpeed() {
    pinMode(pinILS, INPUT_PULLUP);      // Use pull-up for reed switch
    attachInterrupt(digitalPinToInterrupt(pinILS), handleInterrupt, FALLING);
    previousTime = millis();
    Serial.printf("Anemometer initialized on pin %d\n", pinILS);
}

WindSpeed MeasurerWindSpeedImp::measureWindSpeed() {
    unsigned long currentTime = millis();
    
    // Calculate speed every MEASURE_INTERVAL
    if (currentTime - previousTime >= MEASURE_INTERVAL) {
        noInterrupts(); // Disable interrupts while reading the count
        unsigned long pulseCount = nombreDAimant;
        nombreDAimant = 0;
        interrupts(); // Re-enable interrupts
        
        // Calculate rotations and frequency
        float timeSeconds = (float)(currentTime - previousTime) / 1000.0;
        float rotations = (float)pulseCount / MAGNETS_PER_ROTATION;
        float frequence = rotations / timeSeconds;
        
        // Calculate wind speed (m/s to km/h)
        float vitesseVentms = 2.0 * PI * rayonDesBras * frequence * facteurEtalonnage;
        currentSpeed = vitesseVentms * 3.6;
        
        // Debug output
        //Serial.printf("Anemometer Debug - Pulses: %lu, Rotations: %.2f, Freq: %.2f Hz, Speed: %.2f km/h\n", pulseCount, rotations, frequence, currentSpeed);
        
        previousTime = currentTime;
    }

    return { "Anémomètre", currentSpeed };
}