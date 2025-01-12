#include "..\lib\Business\GererCommunication\GererCommunication.hpp"
//#include " GererCommunication.hpp"

// Constructor is already defined in the header file, so we don't need to implement it here.

// Initializes the communication module
void GererCommunication::initializeCommunication()
{
    communication->initialize(); // Call the initialize method from the communication interface
}

// Sends weather data via communication
void GererCommunication::sendWeatherData(const WeatherStationData& data)
{
    communication->sendData(data); // Call the sendData method from the communication interface
}

// Checks the connection status of the communication module
/*bool GererCommunication::checkConnection()
{
    return communication->isConnected(); // Call the isConnected method from the communication interface
}
*/