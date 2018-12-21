/*  server blimp
*/
// battery monitor: https://arduino.stackexchange.com/questions/24450/esp8266-battery-monitor
// debug battery monitor

#include <ESP8266WiFi.h>
char ssid[] = "Linksys59517";             // SSID of home WiFi
char pass[] = "0000000000";
WiFiServer server(80);
WiFiClient client = server.available();

IPAddress ip(192,168,1,213);              // name the IP address of the ESP
IPAddress gateway(192,168,1,1);           // gateway of your network netstat -nr | grep default
IPAddress subnet(255,255,255,0);          // subnet mask of your network

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

void setup() {
  Serial.begin(115200);                   // only for debug
  WiFi.config(ip, gateway, subnet);       // forces fixed IP
  WiFi.begin(ssid, pass);                 // connects to the WiFi router
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(50);
  }  
  
  Serial.println("Connected to wifi");
 
  server.begin(); 
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);    
  pinMode(5, OUTPUT);    
  pinMode(12, OUTPUT);   
  pinMode(13, OUTPUT);   
  pinMode(14, OUTPUT);   
  pinMode(16, OUTPUT);   
  //digitalWrite(0,  HIGH); 
  //digitalWrite(2, HIGH);
  digitalWrite(4,  LOW); 
  digitalWrite(5,  LOW); 
  digitalWrite(12, LOW); 
  digitalWrite(13, LOW); 
  digitalWrite(14, LOW); 
  digitalWrite(16, LOW); 
}

void loop () {
  WiFiClient client = server.available();
  Serial.println("Not connected");  
//  batteryV = analogRead(A0);
//  Serial.print("battery value is: ");
//  Serial.println(batteryV);
  if (client) {
    server.begin();
    while (client.connected()){
       if (!client.connected()) {
        Serial.println();
        Serial.println("disconnecting.");
        client.stop();
        server.available();
        }
        
     if(client.available()){
        String request = client.readStringUntil('y');
        upDowna = request.charAt(0); //upDown
        upDownb = request.charAt(1);
        upDownc = request.charAt(2);
        upDownd = request.charAt(3);
        upDown = upDowna + upDownb + upDownc + upDownd;

        upDown2a = request.charAt(4); //upDown2
        upDown2b = request.charAt(5);
        upDown2c = request.charAt(6);
        upDown2d = request.charAt(7);
        upDown2 = upDown2a + upDown2b + upDown2c + upDown2d;
        
        val3a = request.charAt(8); //val3
        val3b = request.charAt(9);
        val3c = request.charAt(10);
        val3d = request.charAt(11);
        val3 = val3a + val3b + val3c + val3d;
        
        val4a = request.charAt(12); //val4
        val4b = request.charAt(13);
        val4c = request.charAt(14); 
        val4d = request.charAt(15);
        val4 = val4a + val4b + val4c + val4d;

        upDownInt = upDown.toInt();
        upDownInt2 = upDown2.toInt();
        val3Int = val3.toInt();
        val4Int = val4.toInt();
//        Serial.println("upDown is: " + upDown);
//        Serial.println("upDown2 is: " + upDown2);
//        Serial.println("val3 is: " + val3);  
//        Serial.println("val4 is: "+ val4);   

// ****************************************************CONDITIONS************************************************
//***************CCW CONDITIONS (3)**************************

         // move forward, both motors CCW, up/down OFF      
        if (val3Int > highBandLimit && val4Int < highBandLimit 
         && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
            digitalWrite(14, LOW);
            digitalWrite(16, LOW);
            Serial.println("CCW");
            //if(val3Int > highBandLimit && val3Int < slowStartLimit) { 
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 5){
                //motorValue = min(motorValue, 3000);
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          }     
          // move forward, both motors CCW, up ON down OFF 
          if (val3Int > highBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
            digitalWrite(14, HIGH);
            digitalWrite(16, LOW);
            Serial.println("CCW + up");
            //if(val3Int > highBandLimit && val3Int < slowStartLimit) { 
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 10){
                //motorValue = min(motorValue, 3000);
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          }            
          // move forward, both motors CCW, up OFF down ON 
          if (val3Int > highBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
            digitalWrite(14, LOW);
            digitalWrite(16, HIGH);
            Serial.println("CCW + down");
            //if(val3Int > highBandLimit && val3Int < slowStartLimit) { 
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 10){
                //motorValue = min(motorValue, 3000);
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          }  

//***************CW CONDITIONS (3)**************************          
          // move forward, both motors CW, up/down OFF
           else if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){     
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(13, LOW);
              digitalWrite(12, HIGH);
              digitalWrite(14, LOW);
              digitalWrite(16, LOW);
              Serial.println("CW");
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 10){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }
          // move forward, both motors CW, up ON down OFF
         else if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){     // move backward, both motors CW
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(13, LOW);
              digitalWrite(12, HIGH);
              digitalWrite(14, LOW);
              digitalWrite(16, HIGH);
              Serial.println("CW");
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 5){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }
          // move forward, both motors CW, up OFF down ON
         else if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){     // move backward, both motors CW
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(13, LOW);
              digitalWrite(12, HIGH);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("CW");
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 5){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }

//***************RIGHT CONDITIONS (3)**************************           
          // move right, one motor CW, up/down OFF 
          else if (val4Int < lowBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){  // move right, val4 only
              digitalWrite(12, HIGH);
              digitalWrite(13, LOW);
              digitalWrite(4, LOW);
              digitalWrite(5, LOW);
              digitalWrite(14, LOW);
              digitalWrite(16, LOW);
              Serial.println("right");
              analogWrite(0, (4095-motorValue)); 
              }
//***************LEFT CONDITIONS (3)**************************               
          // move left, one motor CCW, up/down OFF    
          else if (val4Int > highBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){  // move LEFT, val3 only
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(4, HIGH);
              digitalWrite(5, LOW);
              digitalWrite(14, LOW);
              digitalWrite(16, LOW);
              Serial.println("left");
              analogWrite(0, (4095-motorValue)); 
              }
//***************DOWN CONDITIONS (1)**************************         
// CCW and CW OFF, up off /down on  
          else if (val3Int > lowBandLimit && val3Int < highBandLimit && val4Int > lowBandLimit 
          && val4Int < highBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){  
              digitalWrite(5, LOW);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(16, HIGH);
              digitalWrite(14, LOW);
              Serial.println("down");
              }
//***************UP CONDITIONS (1)**************************    
// CCW and CW OFF, up on /down off            
          else if (val3Int > lowBandLimit && val3Int < highBandLimit && val4Int > lowBandLimit 
          && val4Int < highBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){ 
              digitalWrite(5, LOW);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("up");
              }

//***************OFF CONDITIONS (1)**************************           
          else if (upDownInt >= 2000 && val3Int > lowBandLimit && val3Int < highBandLimit 
          && val4Int > lowBandLimit && val4Int < highBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){
              digitalWrite(4, LOW);
              digitalWrite(5, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(14, LOW);
              digitalWrite(16, LOW);
              Serial.println("ALL OFF  ");
              }           
    }
  }
}
}        



