#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <ESP8266WiFi.h>

#define REPORTING_PERIOD_MS 1000

char ssid[] = "Yashrastogi7";                                     // Your WiFi credentials.
char pass[] = "air@8299504583";
 
// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
 

 
void onBeatDetected()
{
    Serial.println("Beat Detected!");
}
 
void setup()
{
    Serial.begin(115200);
    
    
    pinMode(16, OUTPUT);
    
 
    Serial.print("Initializing Pulse Oximeter..");
 
    if (!pox.begin(PULSEOXIMETER_DEBUGGINGMODE_PULSEDETECT))
    {
         Serial.println("FAILED");
         for(;;);
    }
    else
    {
         Serial.println("SUCCESS");
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
    // pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
}
 
void loop()
{
    pox.update();
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" bpm / SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");
        tsLastReport = millis();
    }
}
