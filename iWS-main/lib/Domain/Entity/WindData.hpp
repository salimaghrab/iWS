#include <string>   
#include <ctime>
#pragma once

struct WindData {
    std::string sensorModel;    // Modèle du capteur, ex: "Anémomètre"
    std::string windDirectionCompass;  // Direction du vent (ex: "NW", "SE")
};