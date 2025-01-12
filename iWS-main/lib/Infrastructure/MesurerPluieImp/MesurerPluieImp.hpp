#include "../lib/Domain/Services/ImesurerPluie.hpp"
class MesurerPluieImp : public ImeasurerPluie
{
public:
    void InitSensorPluie() override;
    RainfallData measureRainfall() override;

private:
};