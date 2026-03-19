#include <SoftwareSerial.h>
#define INTERVAL 5000
unsigned long lastMillis = 0;
int keyPin = 5;
struct weatherData {
  int humidity;
  float temperature;
  bool rain;
};
weatherData currentWeather = { 0, 0.0, false };
SoftwareSerial hc14(10,11);
void setup() {
  pinMode(keyPin, INPUT);
  Serial.begin(9600);
  hc14.begin(9600);
}
void loop() { // run over and over
  if(hc14.available()){ 
    hc14.readBytes((byte*)&currentWeather, sizeof(currentWeather));
    Serial.print("Humidity [%]: ");
    Serial.println(currentWeather.humidity);
    Serial.print("Temperature [°C]: ");
    Serial.println(currentWeather.temperature, 1);
    if(currentWeather.rain){
      Serial.println("It's raining.");
    }
    else{
      Serial.println("It doesn't rain.");
    }
    Serial.println();
  } 
}