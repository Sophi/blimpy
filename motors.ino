//CCW
int CCW(){ // move forward, both motors rotate out, one CW, the other CCW, up/down OFF 
          if (val3Int > highBandLimit && val4Int < highBandLimit 
         && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(14, LOW);
            digitalWrite(16, LOW);
            Serial.println("CCW");
            Serial.println(wifiTimedOut);
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 5){
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          }  
}

int CCWU(){
       if (val3Int > highBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(14, HIGH);
            digitalWrite(16, LOW);
            Serial.println("CCW + up");
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 10){
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          }            
}

int CCWD(){ // move forward, both motors rotate out, one CW, the other CCW, down ON          
          if (val3Int > highBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){       
            digitalWrite(5, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
            digitalWrite(14, LOW);
            digitalWrite(16, HIGH);
            Serial.println("CCW + down");
              for(int motorValue = highBandLimit ; motorValue <= slowStartLimit; motorValue += 10){
                analogWrite(0, motorValue); 
                analogWrite(2, motorValue); 
                }
          } 
}    
//CW
int CW(){ // move backward, both motors rotate in, one CW, the other CCW, up/down OFF           
           if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt >= 2000){     
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, HIGH);
              digitalWrite(14, LOW);
              digitalWrite(16, LOW);
              Serial.println("CW");
              Serial.println(wifiTimedOut);
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 10){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }
}

int CWU(){ // move backward, both motors rotate in, one CW, the other CCW, up ON         
         if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){     // move backward, both motors CW
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, HIGH);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("CW + up");
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 5){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }
}

int CWD(){ // move backward, both motors rotate in, one CW, the other CCW, down ON         
         if (val3Int < lowBandLimit && val4Int < highBandLimit && val4Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){     // move backward, both motors CW
              digitalWrite(5, HIGH);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, HIGH);
              digitalWrite(14, LOW);
              digitalWrite(16, HIGH);
              Serial.println("CW + down");
             // if(val3Int > slowStopLimit && val3Int < lowBandLimit) {
                for(motorValue = lowBandLimit; motorValue >= 10; motorValue -= 5){
                  analogWrite(0, (4095-motorValue)); 
                  analogWrite(2, (4095-motorValue));              
                  }
           }
}

 //RIGHT LEFT UP DOWN
 //****************************MOTOR CONDITION FUNCTIONS*******************************************************
int R(){  // move right, one motor CW, up OFF down ON 
          if (val4Int < lowBandLimit && val3Int < highBandLimit 
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
}

int RU(){ //move right, one motor CW, up ON down OFF           
          if (val4Int < lowBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){  
              digitalWrite(12, HIGH);
              digitalWrite(13, LOW);
              digitalWrite(4, LOW);
              digitalWrite(5, LOW);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("right + up");
              analogWrite(0, (4095-motorValue)); 
              }
}

int RD(){ // move right, one motor CW, up OFF down ON               
          if (val4Int < lowBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){  
              digitalWrite(12, HIGH);
              digitalWrite(13, LOW);
              digitalWrite(4, LOW);
              digitalWrite(5, LOW);
              digitalWrite(14, LOW);
              digitalWrite(16, HIGH);
              Serial.println("right + down");
              analogWrite(0, (4095-motorValue)); 
              }
}

//***************LEFT CONDITIONS (3)**************************               
int L(){
          // move left, one motor CCW, up/down OFF    
          if (val4Int > highBandLimit && val3Int < highBandLimit 
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
}

int LU(){ // move left, one motor CCW, up ON down OFF                  
          if (val4Int > highBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){  // move LEFT, val3 only
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(4, HIGH);
              digitalWrite(5, LOW);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("left + up");
              analogWrite(0, (4095-motorValue)); 
              }
}

int LD(){ // move left, one motor CCW, up OFF down ON                 
           if (val4Int > highBandLimit && val3Int < highBandLimit 
           && val3Int > lowBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){  // move LEFT, val3 only
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(4, HIGH);
              digitalWrite(5, LOW);
              digitalWrite(14, LOW);
              digitalWrite(16, HIGH);
              Serial.println("left + down");
              analogWrite(0, (4095-motorValue)); 
              }
}

//***************DOWN CONDITIONS (1)**************************         
int D(){ // CCW and CW OFF, up off /down on  
          if (val3Int > lowBandLimit && val3Int < highBandLimit && val4Int > lowBandLimit 
          && val4Int < highBandLimit && upDownInt2 >= 2000 && upDownInt < 2000){  
              digitalWrite(5, LOW);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(16, HIGH);
              digitalWrite(14, LOW);
              Serial.println("down");
              Serial.println(wifiTimedOut);
              }
}
//***************UP CONDITIONS (1)**************************    
int U(){ // CCW and CW OFF, up on /down off            
          if (val3Int > lowBandLimit && val3Int < highBandLimit && val4Int > lowBandLimit 
          && val4Int < highBandLimit && upDownInt2 < 2000 && upDownInt >= 2000){ 
              digitalWrite(5, LOW);
              digitalWrite(4, LOW);
              digitalWrite(12, LOW);
              digitalWrite(13, LOW);
              digitalWrite(14, HIGH);
              digitalWrite(16, LOW);
              Serial.println("up");
              Serial.println(wifiTimedOut);
              }
}
//***************OFF CONDITIONS (1)**************************  
int O(){         
          if (upDownInt >= 2000 && val3Int > lowBandLimit && val3Int < highBandLimit 
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
