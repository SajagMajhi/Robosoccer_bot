//This Arduino code is developed by I Lab
//Hit the SUBSCRIBE button for following our tutorial on arduino.
//You Tube Channel ID: https://www.youtube.com/c/IngenieroLab?sub_confirmation=1.
//Follow our facebook page: https://www.facebook.com/ingenierorobotico

//BTS7960 motor driver sketch 

int R_PWM = 11;
int L_PWM = 10;

void setup() {
  // put your setup code here, to run once:
 pinMode(R_PWM, OUTPUT);
 pinMode(L_PWM, OUTPUT);
}

void loop() {
  int i;
  for(i = 0; i <= 255; i= i+10){ //clockwise rotation
   analogWrite(R_PWM, i);
   analogWrite(L_PWM, 0);
   delay(100);
  }
 // delay(500);
  for(i = 0; i <= 255; i= i+10){ //counter clockwise rotation
   analogWrite(R_PWM, 0);
   analogWrite(L_PWM, i);
   delay(100);
  }
   // delay(500);
}
