#define SENDER_ADDRESS 0xAA
#define RECEIVER_ADDRESS 0xBB


const int DHT_PIN = 25;     // DHT22 sensor pin
const int DHT_TYPE = DHT22;
const int ILS_PIN = 12;     // removed replaced 12
const int SDA_PIN = 21;    // I2C SDA pin for MPU6050
const int SCL_PIN = 22;    // I2C SCL pin for MPU6050
const float RAYON_ANEMOMETRE = 0.091;  // Anemometer radius in meters
const float FACTEUR_ETALONNAGE = 2.5;  // Calibration factor
//static unsigned long lastPrintTime = 0;
//const unsigned long PRINT_INTERVAL = 2000; // Print every 2 seconds
//const unsigned long SEND_INTERVAL = 4000; // Print every 2 seconds
// don't use those pin 16 4 15 5 18 19  14 27 26 