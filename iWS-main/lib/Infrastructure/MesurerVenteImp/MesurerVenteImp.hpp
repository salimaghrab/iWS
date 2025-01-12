#include "../lib/Domain/Services/ImesurerVente.hpp"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class MesurerVenteImp : public ImeasurerVente {
public:
    MesurerVenteImp(int sdaPin, int sclPin);   ;// Constructeur pour les pins
    void InitSensorVente() override;
    WindData measureWind();
private:
    Adafruit_MPU6050 mpu;
    int sdaPin, sclPin ; // Pins pour I2C
    std::string getCompassDirectionFromAngle(float angle);
    float readAngleFromWindVane();


};