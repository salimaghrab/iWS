#include "..\lib\Infrastructure\MesurerPluieImp\MesurerPluieImp.hpp"
#include <iostream>

void MesurerPluieImp::InitSensorPluie() {
    // Initialize the rainfall sensor (pseudo-code)
    std::cout << "Initializing Rainfall Sensor..." << std::endl;
    // Your sensor initialization logic goes here
}

RainfallData MesurerPluieImp::measureRainfall() {
    // Measure and return rainfall data (pseudo-code)
    RainfallData data;
    data.sensorModel = "Pluviomètre";
    data.precipitationMillimeters = 10.5; // Example value
    data.timestamp = std::time(nullptr);
    return data;
}
