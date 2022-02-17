 #include <SPI.h>  
#include "RF24.h" 

RF24 myRadio (8, 9); 


byte addresses[][6] = {"0"}; 
const int LED2 = 2; // choose the pin for each of the LEDs
const int LED3 = 3;
const int LED4 = 4;
//const int thirdLedPin = 6;
void setup() 
{

  pinMode(LED2, OUTPUT); // declare LED pins as output
  pinMode(LED3, OUTPUT); // declare LED pins as output
  pinMode(LED4, OUTPUT); // declare LED pins as output
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
if((strcmp(text, "1") ==0))
{

 digitalWrite(LED2, HIGH);
      Serial.println(text);
      
}
if((strcmp(text, "2") ==0))
{
digitalWrite(LED2, LOW);
Serial.println(text);
}
//////////////////////////////
// Second Output
if((strcmp(text, "3") ==0))
{

 digitalWrite(LED3, HIGH);
      Serial.println(text);
      
}
if((strcmp(text, "4") ==0))
{
digitalWrite(LED3, LOW);
Serial.println(text);
}

//////////////////////////////
// Third Output
if((strcmp(text, "5") ==0))
{

 digitalWrite(LED4, HIGH);
      Serial.println(text);
      
}
if((strcmp(text, "6") ==0))
{
digitalWrite(LED4, LOW);
Serial.println(text);
}

    
    
  }

}
