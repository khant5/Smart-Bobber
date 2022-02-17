 #include <SPI.h>  
#include "RF24.h" 
 #include<Servo.h>
 
Servo Myservo;
RF24 myRadio (8, 9); 


byte addresses[][6] = {"0"}; 
const int LED2 = 2; // choose the pin for each of the LEDs
const int LED3 = 3;
const int LED4 = 4;

const int leftForward = 6;
const int leftBackward = 5;
//const int thirdLedPin = 6;
void setup() 
{

 /* Serial.begin(115200);
  delay(1000);

  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();*/

    pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(LED2, OUTPUT); // declare LED pins as output
  pinMode(LED3, OUTPUT); // declare LED pins as output
  pinMode(LED4, OUTPUT); // declare LED pins as output
  Myservo.attach(7);
 // Myservo.write(180);
  
  Serial.begin(9600);
   myRadio.begin(); 
   myRadio.openReadingPipe(0, addresses[0]);
   myRadio.setPALevel(RF24_PA_MIN);
   myRadio.startListening ();
}


void loop()  
{

    while( myRadio.available()) 
  {


    char text[32] = "";
    
   myRadio.read( &text, sizeof(text) ); 
     
// First output


if((strcmp(text, "1") ==0) && (strcmp(text, "3") !=0))
{

Myservo.write(180);
// Go on turning for the right duration
delay(15);
// Stop turning
Myservo.write(90);
      Serial.println(text);
  

    
}
 
/*if((strcmp(text, "2") ==0))
{
//Myservo.write(90);
// Go on turning for the right duration
//delay(15);
// Stop turning
//Myservo.write(90);
      Serial.println(text);
  }*/

//////////////////////////////
// Second Output*/
else if((strcmp(text, "3") ==0) && (strcmp(text, "1") !=0))
{
  

  
  
Myservo.write(0);
// Go on turning for the right duration
delay(15);

 digitalWrite(LED3, HIGH);
    Myservo.write(90);
      Serial.println(text);

    


}



else if((strcmp(text, "2") ==0) )
{

  if((strcmp(text, "2") !=0) )
  {

     digitalWrite(leftForward , LOW);
   digitalWrite(leftBackward , LOW);
  }

 digitalWrite(leftForward , HIGH);
   digitalWrite(leftBackward , LOW);
      Serial.println(text);
      delay(15);
   digitalWrite(leftForward , LOW);
   digitalWrite(leftBackward , LOW);

    
}

else if((strcmp(text, "4") ==0) )
{

  if((strcmp(text, "4") !=0) )
  {

     digitalWrite(leftForward , LOW);
   digitalWrite(leftBackward , LOW);
  }

 digitalWrite(leftBackward , HIGH);
  digitalWrite(leftForward , LOW);
      Serial.println(text);
            delay(15);
   digitalWrite(leftForward , LOW);
   digitalWrite(leftBackward , LOW);
  

    
}

 

// Second Output*/


//////////////////////////////
// Third Output
/*else if((strcmp(text, "5") ==0))
{

 digitalWrite(LED4, HIGH);
 Myservo.write(0);
 Serial.println(text);
      


    
    
  }*/

}


}
