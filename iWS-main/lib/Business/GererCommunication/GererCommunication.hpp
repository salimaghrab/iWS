
#include "../lib/Domain/Services/Icommunication.hpp"
#include "../lib/Domain/Entity/WeatherStationData.hpp"

class GererCommunication
{
private:
    Icommunication* communication; // Pointer to communication interface

public:
    GererCommunication(Icommunication* comm) : communication(comm) {}

    void initializeCommunication();
 

    void sendWeatherData(const WeatherStationData& data);


   // bool checkConnection();
  
};

