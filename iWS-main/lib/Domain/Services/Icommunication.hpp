#pragma once

#include <string>
#include "../lib/Domain/Entity/WeatherStationData.hpp"
#include "heltec.h"

class Icommunication {
public:

    // Initialize LoRa communication
    virtual void initialize() = 0;
    // Send data via LoRa to a remote server or storage
    virtual void sendData(const WeatherStationData& data) = 0;
    // Optional: Check the connection status of the LoRa module
    //virtual bool isConnected() = 0;


};

