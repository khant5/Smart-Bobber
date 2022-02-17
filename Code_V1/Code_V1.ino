
#include<Servo.h>
Servo Myservo;
#define sw1_pin 2
#define sw2_pin 4
#define sw3_pin 7
int pos=0;
const int LED = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(sw1_pin,INPUT);
pinMode(sw2_pin,INPUT);
pinMode(sw3_pin,INPUT);
Myservo.attach(10);
Myservo.write(180);
}

void loop() {
  /// put your main code here, to run repeatedly:
  //   digitalWrite(LED,HIGH);
  if(digitalRead(sw1_pin)==HIGH)
  {
    Myservo.write(180);
    //digitalWrite(LED,HIGH);
    delay(1000);
    
  }

  else if(digitalRead(sw2_pin)==HIGH)
  {
    Myservo.write(90);
    delay(1000);
  
  }

   else if(digitalRead(sw3_pin)==HIGH)
  {
    Myservo.write(0);
    delay(1000);
  
  }

}
