#include<Servo.h>

int R_PWM1 = 9;
int L_PWM1 = 5;

int R_PWM2 = 11;
int L_PWM2 = 10;

int ch1 = 8;
int ch2 = 7;

int t = 100;

#define CH1 8
#define CH2 7
#define CH5 6

Servo myservo;

int n1,n2;

int ch1Value;
int ch2Value;
int ch5Value;

void setup() {
  Serial.begin(9600);
  myservo.attach(4);
  pinMode(R_PWM1,OUTPUT);
  pinMode(L_PWM1,OUTPUT);

  pinMode(L_PWM2,OUTPUT);
  pinMode(R_PWM2,OUTPUT);

  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH5, INPUT);

}

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}

void loop() {
    ch1Value = readChannel(CH1, -230, 255, 0);
    ch2Value = readChannel(CH2, -235, 255, 0);
    ch5Value = readSwitch(CH5, false);

    Serial.print("Ch1: ");
    Serial.print(ch1Value);
    Serial.print(" | Ch2: ");
    Serial.print(ch2Value);
    Serial.print(" | Ch5: ");
    Serial.println(ch5Value);

/*
    n1 = ch1Value + 10;
    n2 = ch2Value + 10;
*/
/*
    if(ch5Value == 1)
    {
      myservo.attach
      myservo.write(80);
    }
    else if(ch5Value == 0)
    {
      myservo.detach();
    }*/
/*
    if(ch1Value > 0)
    {
    if(ch1Value > 220)
        ch1Value = 255;
     analogWrite(9,ch1Value);
     analogWrite(5,0); 
    }
    
    if(ch1Value < 0)
    {
      ch1Value = ch1Value*-1;
      if(ch1Value > 230)
        ch1Value = 255;
      analogWrite(9,0);
      analogWrite(5,ch1Value);
    }
*/
    
    if(ch2Value > 0)
    {
      //if(ch1Value > 230)
        //ch1Value = 255;
      analogWrite(10,0);
      analogWrite(11,230);
    }

    if(ch2Value < 0)
    {
      //ch2Value = ch2Value*-1;

      //if(ch2Value > 230)
        //ch2Value = 255;
      analogWrite(10,230);
      analogWrite(11,0);
    }
  
    /*
    if(Serial.available()>0)
    {
      char x = Serial.read();
      switch(x)
      {
        case 'w': forward();
        break;
        case 'a': left();
        break;
        case 'd': right();
        break;
        case 's': backward();
        break;
        case 'j': stop();
        break;
      }
    }*/

}

void forward()
{
  digitalWrite(R_PWM1,HIGH);
  digitalWrite(L_PWM1,LOW);
  delay(t);
  digitalWrite(R_PWM2,HIGH);
  digitalWrite(L_PWM2,LOW);
}

void backward()
{
  digitalWrite(R_PWM1,LOW);
  digitalWrite(L_PWM1,HIGH);
  delay(t);
  digitalWrite(R_PWM2,LOW);
  digitalWrite(L_PWM2,HIGH);
}

void left()
{
   digitalWrite(R_PWM2,LOW);
  digitalWrite(L_PWM2,HIGH);
  delay(t);
  digitalWrite(R_PWM1,HIGH);
  digitalWrite(L_PWM1,LOW);
}

void right()
{
  digitalWrite(R_PWM1,LOW);
  digitalWrite(L_PWM1,HIGH);
  delay(t);
  digitalWrite(R_PWM2,HIGH);
  digitalWrite(L_PWM2,LOW);
}


void stop()
{
  digitalWrite(R_PWM1,LOW);
  digitalWrite(L_PWM1,LOW);
  delay(t);
  digitalWrite(R_PWM2,LOW);
  digitalWrite(L_PWM2,LOW);
}

int customFunction(int inputValue) {
  if (inputValue == 0) {
    return 0;
  } else if (inputValue == 20) {
    return 40;
  } else if (inputValue == 30) {
    return 60;
  } else if (inputValue == 50) {
    return 80;
  } else if (inputValue == 80) {
    return 100;
  } else if (inputValue == 100) {
    return 120;
  } else {
    // Linear scaling for values in between
    if (inputValue > 0 && inputValue < 20) {
      return (2 * inputValue);
    } else if (inputValue > 20 && inputValue < 30) {
      return (2 * (inputValue - 20) + 40);
    } else if (inputValue > 30 && inputValue < 50) {
      return (4 * (inputValue - 30) + 60);
    } else if (inputValue > 50 && inputValue < 80) {
      return (2 * (inputValue - 50) + 80);
    } else if (inputValue > 80 && inputValue < 100) {
      return (2 * (inputValue - 80) + 100);
    } else {
      // For values greater than 100
      return inputValue;
    }
  }
}
