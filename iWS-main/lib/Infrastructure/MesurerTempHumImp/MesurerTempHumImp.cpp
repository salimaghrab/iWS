#include "../lib/Infrastructure/MesurerTempHumImp/MesurerTempHumImp.hpp"



//def de capteur 

void MesurerTempHumImp::InitSensorTempHum() {
    
    dht.begin();
    if (isnan(dht.readTemperature())) {
        Serial.println("DHT22 connection failed.");
        while (1); // Infinite loop if the sensor is not detected
    } else {
        Serial.println("DHT22 sensor initialized successfully.");
    }
}

TemperatureHumidityData MesurerTempHumImp::measureTemperatureHumidity() {
    // Measure and return temperature and humidity data (pseudo-code)
    TemperatureHumidityData data;

    data.sensorModel = "DHT22 Sensor";
    data.temperatureCelsius = float(dht.readTemperature()) ;
    data.humidityPercentage = float(dht.readHumidity()) ;
    return data;
}