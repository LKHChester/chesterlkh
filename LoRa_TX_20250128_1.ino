#include <SoftwareSerial.h>
#define INTERVAL 5000
const int keyPin = 5;
struct weatherData {
  int a;
  float b;
  bool c;
};
weatherData currentWeather = { 32, 25.0, false };
SoftwareSerial hc14(10,11);
void setup() {
  pinMode(keyPin, INPUT);
  Serial.begin(9600);
  hc14.begin(9600);
}
void loop() {  
  hc14.write((byte*)&currentWeather, sizeof(currentWeather));
  Serial.println("Data sent");
  delay(5000);
}
