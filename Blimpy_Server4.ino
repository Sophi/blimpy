/*  server blimp
*/
// battery monitor: https://arduino.stackexchange.com/questions/24450/esp8266-battery-monitor
// debug battery monitor

#include <ESP8266WiFi.h>
#include <elapsedMillis.h>
char ssid[] = "Linksys59517";             // SSID of home WiFi
char pass[] = "0000000000";
WiFiServer server(80);
IPAddress ip(192,168,1,213);              // name the IP address of the ESP
IPAddress gateway(192,168,1,1);           // gateway of your network netstat -nr | grep default
IPAddress subnet(255,255,255,0);          // subnet mask of your network
elapsedMillis wifiTimeoutEllapsedMillis;
unsigned wifiTimeoutMs = 3000;
bool wifiTimedOut = 0;
int wifiTimedOutTwo = 0;
bool commandUpdated = 0;
String command;
String request;
int requestLength = request.length();
int counterClockwise;
int counterClockwiseDown; 
int counterClockwiseUp; 
int clockwise; 
int clockwiseDown;
int clockwiseUp;
int right;
int rightUp;
int rightDown;
int left;
int leftUp;
int leftDown;
int down;
int up;
int off;
float batteryV;
int highBandLimit = 2500;
int lowBandLimit = 1400;
int slowStartLimit = 3600;
int slowStopLimit = 500;
int upDownInt;
int upDownInt2;
int val3Int;
int val4Int;
int motorValue;
int pwmVal0;
int pwmVal2;
String start;
String upDown;
String upDowna;
String upDownb;
String upDownc;
String upDownd;
String upDown2;
String upDown2a;
String upDown2b;
String upDown2c;
String upDown2d;
String val3;
String val3a;
String val3b;
String val3c;
String val3d;
String val4;
String val4a;
String val4b;
String val4c;
String val4d;
String mac;

void setup() {
 // Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces fixed IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(50);
  }   
  Serial.println("Connected to wifi");
  delay(50);
  mac = WiFi.macAddress();
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);    
  pinMode(5, OUTPUT);    
  pinMode(12, OUTPUT);   
  pinMode(13, OUTPUT);   
  pinMode(14, OUTPUT);   
  pinMode(16, OUTPUT);   
  digitalWrite(0,  HIGH); 
  digitalWrite(2, HIGH);
  digitalWrite(4,  LOW); 
  digitalWrite(5,  LOW); 
  digitalWrite(12, LOW); 
  digitalWrite(13, LOW); 
  digitalWrite(14, LOW); 
  digitalWrite(16, LOW); 
  server.begin(); 
}

void loop () {
  Serial.println("loop");
  loopMotor();
  loopWifi();  
}








