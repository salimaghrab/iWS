#include "MesurerVenteImp.hpp"
#include <iostream>
#include <map>
#include <cmath>
#include <ctime>

// Constructeur avec les pins SDA et SCL
MesurerVenteImp::MesurerVenteImp(int sdaPin, int sclPin) : sdaPin(sdaPin), sclPin(sclPin) {}

// Initialisation du capteur MPU6050 uniquement
void MesurerVenteImp::InitSensorVente() {
   Serial.println("Initializing MPU6050 Sensor...");
    // Initialiser le MPU6050 avec les pins configurés
    Wire.begin(sdaPin, sclPin);
    
    if (!mpu.begin()) {
        Serial.println("MPU6050 connection failed.");
        while (1); // Boucle infinie si le capteur n'est pas détecté
    }
    
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    Serial.println("MPU6050 and PinAnenometre initialized successfully.");
}


// Mesurer la direction du vent en utilisant le capteur MPU6050
WindData MesurerVenteImp::measureWind() {
    WindData data;
        data.sensorModel = "Girouette";

    try {
        float angle = readAngleFromWindVane();
        data.windDirectionCompass = getCompassDirectionFromAngle(angle);
    } catch (const std::exception& e) {
        Serial.println(e.what());
    }
    return data;
}


// Fonction de lecture de l'angle depuis le capteur de vent
float MesurerVenteImp::readAngleFromWindVane() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Afficher les valeurs des capteurs pour le débogage
    // Calculer l'angle
    float angle = atan2(a.acceleration.y, a.acceleration.x) * (180.0 / M_PI);
    // Ajuster l'angle si nécessaire (s'il est négatif)
    if (angle < 0) angle += 360;

    // Vérification de l'angle
    if (angle < 0 || angle >= 360) {
        return -1;  // Erreur si l'angle est hors plage
    }

    return angle;
}

// Convertir l'angle en direction de boussole
std::string MesurerVenteImp::getCompassDirectionFromAngle(float angle) {
    std::map<int, std::string> compassDirections = {
        {0, "N"}, {45, "NE"}, {90, "E"}, {135, "SE"},
        {180, "S"}, {225, "SW"}, {270, "W"}, {315, "NW"}, {360, "N"}
    };
    int roundedAngle = static_cast<int>((angle + 22.5) / 45) * 45;
    roundedAngle = roundedAngle % 360;
    return compassDirections[roundedAngle];
}