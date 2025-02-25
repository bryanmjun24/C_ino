#include <Arduino.h>
#ifdef ESP32
    #include <WiFi.h>
#else
    #include <ESP8266WiFi.h>
#endif
#include "fauxmoESP.h"

// Rename the credentials.sample.h file to credentials.h and 
// edit it according to your router configuration

#define WIFI_SSID "NETLIFE-MOSQUERA"
#define WIFI_PASS "66801566"
#define SERIAL_BAUDRATE 115200

// DEVICES 
#define LED_1 5
#define ID_1 "Foco 1"
#define LED_2 4
#define ID_2 "Foco 2"
//#define LED_3 0
//#define ID_3 "Foco 3"

fauxmoESP fauxmo;
// -----------------------------------------------------------------------------
// Wifi
// -----------------------------------------------------------------------------

void wifiSetup() {

    // Set WIFI module to STA mode
    WiFi.mode(WIFI_STA);

    // Connect
    Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Wait
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();

    // Connected!
    Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());

}

void setup() {

    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);

    // LEDs
    pinMode(LED_1, OUTPUT);
    digitalWrite(LED_1, LOW);
    pinMode(LED_2, OUTPUT);
    digitalWrite(LED_2, LOW);
    //pinMode(LED_3, OUTPUT);
    //digitalWrite(LED_3, LOW);

    // Wifi
    wifiSetup();
    
    fauxmo.createServer(true); // not needed, this is the default value
    fauxmo.setPort(80); // This is required for gen3 devices
    fauxmo.enable(true);
    // Add virtual devices
    fauxmo.addDevice(ID_1);
    fauxmo.addDevice(ID_2);
    //fauxmo.addDevice(ID_3);
    fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
        
        Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);

        if (strcmp(device_name, ID_1)==0) {
            digitalWrite(LED_1, state ? HIGH : LOW);
        }else if (strcmp(device_name, ID_2)==0) {
            digitalWrite(LED_2, state ? HIGH : LOW);
       /* }else if (strcmp(device_name, ID_3)==0) {
            digitalWrite(LED_3, state ? HIGH : LOW);*/
        }

    });

}

void loop() {
    fauxmo.handle();

}
