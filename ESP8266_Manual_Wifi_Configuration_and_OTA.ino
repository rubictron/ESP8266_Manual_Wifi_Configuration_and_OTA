/*************************
Auther : Asitha Sandakalum
*************************/

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ESP8266mDNS.h>

//Variables
int i = 0;
int statusCode;
const char* ssid = "";
const char* passphrase = "";
String st;
String content;
bool debug=true;
bool force_HotSpot=false;
int force_hotspot_pin = 4;
const char* DomainName = "rubictron";


//Function Decalration
bool testWifi(void);
void launchWeb(void);
void setupAP(void);
void setupOTA(void);
void setupWifi(void);
void dprint(String str);

//Establishing Local server at port 80 whenever required
ESP8266WebServer server(80);


void setup() {

  Serial.begin(115200); //Initialasing Serial
  EEPROM.begin(512); //Initialasing EEPROM
  delay(100);
  dprint("Booting...........................");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(force_hotspot_pin, INPUT_PULLUP);
  delay(10);
  ledon();

  ledoff();
  force_HotSpot = ( digitalRead(force_hotspot_pin) == LOW ) ? true : false ;

  setupWifi();
  setupOTA();

  ledoff();


}

void loop() {
  ArduinoOTA.handle();


  
}
