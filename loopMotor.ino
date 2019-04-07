int loopMotor(){   
  if (wifiTimedOut == 1){
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   digitalWrite(12, LOW);
   digitalWrite(13, LOW);
   digitalWrite(14, LOW);
   digitalWrite(16, LOW);
   delay(100);
   wifiTimedOut = wifiTimedOutTwo;   
   wifiTimedOutTwo = 2;
   Serial.println("loopMotor wifiTimedOut ");
   Serial.println(wifiTimedOut);
   }
  else if (wifiTimedOutTwo == 2){
   Serial.println("loopMotor wifiTimedOut 2");
   reset();  
   }
  else{
   counterClockwise = CCW();      // move forward, one CW, the other CCW, up/down OFF           
   counterClockwiseDown = CCWD(); // move forward, one CW, the other CCW, down ON 
   counterClockwiseUp = CCWU();   // move forward, one CW, the other CCW, up ON  
   clockwise = CW();              // move backward, one CW, the other CCW, up/down OFF
   clockwiseDown = CWD();
   clockwiseUp = CWU();
   right = R();
   rightUp = RU();
   rightDown = RD();
   left = L();
   leftUp = LU();
   leftDown = LD();
   down = D();                    // CCW and CW OFF, up off /down on 
   up = U();                      // CCW and CW OFF, up on /down off     
   off = O(); 
   }
}
