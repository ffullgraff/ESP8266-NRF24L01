

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";


char ssid[] = "your wifi";
char pass[] = "your pasword";



void setup()
{
 
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
  
}
