
int loopWifi(){
  Serial.println("loopWifi");
  Serial.println(wifiTimedOut);
  if (wifiTimedOutTwo = 2){
  WiFiClient client = server.available();
  off = O(); 
  if (client)
   while (client.connected()){  
    request = " "; 
    server.begin();
    if(client.available()){
      Serial.println("client available");
        request = client.readStringUntil('y');
        if (request.length() == 16){                         // if data is 16 characters
          wifiTimedOut = 0;                   // then we didn't time out
          wifiTimeoutEllapsedMillis = 0;      // reset timeout flag, ellapsedMillis
          command = request;                  // 16 characters
          wifiTimedOutTwo = 0;
         }
         else if (request.length() < 16){
          Serial.println("wifi Timed Out Length");
          wifiTimedOut = 1; // then we timed out
          Serial.flush();
          request = " ";
          loopMotor();
            while(Serial.available()){
              Serial.read();
            }
         }
         else if (wifiTimeoutEllapsedMillis >= wifiTimeoutMs){ // if ellapsedMillis > 3000
          Serial.print("wifi Timed Out Time");
          wifiTimedOut = 1; // then we timed out
          Serial.flush();
          request = " ";
          loopMotor();
            while(Serial.available()){
              Serial.read();
            }
          }

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
   }
   loopMotor();
}
}
}



