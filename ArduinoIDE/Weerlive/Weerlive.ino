#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESP8266HTTPClient.h>              // http web access library
#include <ArduinoJson.h>                    // JSON decoding library

#include "WeerliveClass.h"
#include "myCredentials.h"

WiFiClient weerliveClient;
Weerlive weerlive(weerliveClient);

char tickerText[500];

void setup() 
{
  Serial.begin(115200);
  while (!Serial) { delay(1); }
  Serial.println();
  Serial.print("Connecting.");

  //-- Acess Wi-FI point
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);               
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("connected\r\n");
  Serial.flush();

  weerlive.setup(AUTHKEY, YOURCITY);

}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED)   // Check WiFi connection status
  {      
    const char* weatherInfo = weerlive.request();
    Serial.println(weatherInfo);
  }

  Serial.print("\nEnter a key ");
  while (!Serial.available()) 
  { 
     delay(10);
  }
  // Read the incoming byte.
  char incomingByte = Serial.read();
  
  // Print the received byte.
  if (incomingByte == '\r')  Serial.println("\nYou pressed: [<cr>]\r\n");
  else if (incomingByte == '\n')  Serial.println("\nYou pressed: [<nl>]\r\n");
  else if (incomingByte == '\n')  Serial.printf("\nYou pressed: [%c]\r\n\n", incomingByte);
  while(Serial.available() > 0)  Serial.read();

  // Do something after the keypress.
  Serial.println("Continuing execution...");
  
}
