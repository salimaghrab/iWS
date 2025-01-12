
#include <Arduino.h>
#include "../lib/Business/MesurerTemperatureHumidite/MesurerTemperatureHumidite.hpp"
#include "../lib/Infrastructure/MesurerTempHumImp/MesurerTempHumImp.hpp"
#include "../lib/Business/MesurerVente/MesurerVente.hpp"
#include "../lib/Infrastructure/MesurerVenteImp/MesurerVenteImp.hpp"
#include "../include/bsp.h"
#include "../lib/Business/MesureSpeedWind/MesurerWindSpeed.hpp"
#include "../lib/Infrastructure/MeasurerWindSpeedImp/MeasurerWindSpeedImp.hpp"
#include "../lib/Infrastructure/CommunicationImp/CommunicationImp.hpp"
#include "../lib/Business/GererCommunication/GererCommunication.hpp"
#define BAND 868E6

// Global objects
MesurerTempHumImp tempHumSensor(DHT_PIN, DHT_TYPE);
MesurerVenteImp ventSensor(SDA_PIN, SCL_PIN);
MeasurerWindSpeedImp windSpeedSensor(ILS_PIN, RAYON_ANEMOMETRE, FACTEUR_ETALONNAGE);

// Communication objects
CommunicationImp commImp(BAND, SENDER_ADDRESS, RECEIVER_ADDRESS);
GererCommunication gererComm(&commImp);

// Business layer objects
MesurerTemperatureHumidite tempHumManager(&tempHumSensor);
MesurerVente ventManager(&ventSensor);
MesurerWindSpeed windSpeedManager(&windSpeedSensor);

void debugAnemometer()
{
    static unsigned long lastDebugTime = 0;
    static int lastPinState = -1;
    int currentPinState = digitalRead(ILS_PIN);

    if (currentPinState != lastPinState)
    {
        Serial.printf("Anemometer pin changed: %d\n", currentPinState);
        lastPinState = currentPinState;
    }

    if (millis() - lastDebugTime >= 1000)
    {
        lastDebugTime = millis();
    }
}

unsigned long lastPrintTime = 0;
unsigned long lastSendTime = 0;
const unsigned long PRINT_INTERVAL = 4000; // 1 second
const unsigned long SEND_INTERVAL = 10000;  // 5 seconds
//#define configTICK_RATE_HZ 1000


// Task to read weather data and print it
void TaskWeatherData(void *pvParameters)
{
    while (1)
    {
        // Get weather data
        TemperatureHumidityData tempHumData = tempHumManager.getTemperatureHumidityData();
        WindData windData = ventManager.getWindData();
        WindSpeed windSpeedData = windSpeedManager.getWindSpeedData();

        // Print the data (optional)
        Serial.printf("Temperature: %.1f°C, Humidity: %.1f%%\n", tempHumData.temperatureCelsius, tempHumData.humidityPercentage);
        Serial.printf("Wind Direction: %s\n", windData.windDirectionCompass.c_str());
        Serial.printf("Wind Speed: %.1f km/h\n", windSpeedData.vitesseVentkmh);
        Serial.println("------------------------");

        // Delay for the next print cycle
        vTaskDelay(PRINT_INTERVAL / portTICK_PERIOD_MS);
    }
}

// Task to send weather data
void TaskSendData(void *pvParameters)
{
    while (1)
    {
        // Gather real sensor data
        TemperatureHumidityData tempHumData = tempHumManager.getTemperatureHumidityData();
        WindData windData = ventManager.getWindData();
        WindSpeed windSpeedData = windSpeedManager.getWindSpeedData();

        // Fill in the WeatherStationData struct with real sensor data
        WeatherStationData data;
        data.temperatureHumidityData.sensorModel = tempHumData.sensorModel;
        data.temperatureHumidityData.temperatureCelsius = tempHumData.temperatureCelsius;
        data.temperatureHumidityData.humidityPercentage = tempHumData.humidityPercentage;

        data.windspeed.sensorModel = windSpeedData.sensorModel;
        data.windspeed.vitesseVentkmh = windSpeedData.vitesseVentkmh;

        data.windData.sensorModel = windData.sensorModel;
        data.windData.windDirectionCompass = windData.windDirectionCompass;
        //diplay data 

          /*  Heltec.display->clear();
            Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
            Heltec.display->setFont(ArialMT_Plain_10);
            Heltec.display->drawString(0, 0, "Sender: 0x" );
            Heltec.display->drawString(0, 12, "Temp: " + String(data.temperatureHumidityData.temperatureCelsius) + " C");
            Heltec.display->drawString(0, 24, "Humidity: " + String(data.temperatureHumidityData.humidityPercentage) + " %");
            Heltec.display->display(); */

        // Send the weather data via GererCommunication
        gererComm.sendWeatherData(data);

        // Delay for the next send cycle
        
        vTaskDelay(SEND_INTERVAL / portTICK_PERIOD_MS);

    }
}

void setup()
{
    // Initialize Serial communication
    Serial.begin(115200);
    while (!Serial)
        delay(100);
    Serial.println("Weather Station Initializing...");

    // Initialize I2C
    Wire.begin(SDA_PIN, SCL_PIN);

    // Initialize sensors
    tempHumManager.InitSensor();
    ventManager.InitSensor();
    windSpeedManager.InitSensor();
    gererComm.initializeCommunication();

    xTaskCreate(TaskWeatherData, "WeatherDataTask", 2048, NULL, 2, NULL); // Weather Data task
    xTaskCreate(TaskSendData, "SendDataTask", 2048, NULL, 1, NULL);       // Send Data task

    Serial.println("Weather Station Initialized Successfully!");
}

void loop()
{
}
