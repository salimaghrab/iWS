
#include <string>   
#include <ctime>

struct RainfallData {

    std::string sensorModel;    // Modèle du capteur, ex: "Pluviomètre"
    float precipitationMillimeters;  // Précipitations en millimètres
    std::time_t timestamp;      // Date et heure de la dernière mesure
};

