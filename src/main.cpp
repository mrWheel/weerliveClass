#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESP8266HTTPClient.h>              // http web access library
#include <ArduinoJson.h>                    // JSON decoding library

#include "WeerliveClass.h"

const char *ssid = "YOUR_WIFI_SSID";
const char *password = "YOUR_WIFI_PASSWORD";

const char *AUTHKEY = "1234567";
const char *CITY = "Amsterdam";

WiFiClient weerliveClient;
Weerlive weerlive(weerliveClient);

char tickerText[500];

void setup() 
{
  Serial.begin(115200);
  while (!Serial) { delay(1); }
  Serial.println();
  Serial.print("Connecting.");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);               // access Wi-FI point
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("connected\r\n");
  Serial.flush();

  weerlive.setup(AUTHKEY, CITY);

}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED)   // Check WiFi connection status
  {      
    const char* weatherInfo = weerlive.request();
    Serial.println(weatherInfo);
  }

  Serial.print("Enter a key ");
  while (!Serial.available()) 
  { 
     delay(10);
  }
  // Read the incoming byte.
  char incomingByte = Serial.read();
  
  // Print the received byte.
  Serial.print("You pressed: ");
  Serial.println(incomingByte);
  
  // Do something after the keypress.
  Serial.println("Continuing execution...");
  
}
