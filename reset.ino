int reset() {
#include <ESP8266WiFi.h>
#include <elapsedMillis.h>
char ssid[] = "Linksys59517";             // SSID of home WiFi
char pass[] = "0000000000";
WiFiServer server(80);
IPAddress ip(192,168,1,213);              // name the IP address of the ESP
IPAddress gateway(192,168,1,1);           // gateway of your network netstat -nr | grep default
IPAddress subnet(255,255,255,0);          // subnet mask of your network
//  Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces fixed IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  while (WiFi.status() != WL_CONNECTED){
    Serial.println("x");
    delay(100);  
  }
server.begin();
request = " ";
loopWifi();
}   
