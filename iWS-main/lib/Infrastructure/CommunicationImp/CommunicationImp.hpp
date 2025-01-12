#include "../lib/Domain/Services/Icommunication.hpp"
#include <heltec.h>

class CommunicationImp : public Icommunication
{
public:
    CommunicationImp(long frequency, uint8_t senderAddress, uint8_t receiverAddress);

    void initialize() override;
    void sendData(const WeatherStationData &data) override;
    // bool isConnected() override;

private:
    long _frequency;
    uint8_t _senderAddress;
    uint8_t _receiverAddress;
};