#include "..\lib\Infrastructure\CommunicationImp\CommunicationImp.hpp"
#include <iostream>




CommunicationImp::CommunicationImp(long frequency, uint8_t senderAddress, uint8_t receiverAddress)
    : _frequency(frequency), _senderAddress(senderAddress), _receiverAddress(receiverAddress) {}

void CommunicationImp::initialize() {
    Heltec.begin(true, true, true, true, _frequency);
    Serial.println(" initialize sender ");
}

void CommunicationImp::sendData(const WeatherStationData& data) {

    // Crée le message à envoyer en utilisant les données du WeatherStationData
    String message = String(_receiverAddress, HEX) + "," +
                     String(_senderAddress, HEX) + "," +
                     String(data.temperatureHumidityData.temperatureCelsius, 1) + "," +
                     String(data.temperatureHumidityData.humidityPercentage, 1) + "," +
                     String(data.windspeed.vitesseVentkmh, 1) + "," +
                     data.windData.windDirectionCompass.c_str();

    // Envoie le message via LoRa
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();

    Serial.println("Sent: " + message);
}



/*bool CommunicationImp::isConnected() {
    // Check if connected to LoRa (pseudo-code)
    std::cout << "Checking connection status..." << std::endl;
    // Return the actual connection status
    return true; // Placeholder
}
*/