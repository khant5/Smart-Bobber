#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (8, 9);
byte addresses[][6] = {"0"};
#define sw1_pin 2
#define sw2_pin 3
#define sw3_pin 4
const int LED2=5;
int sendmes[1]={000};
int first=0;

void setup()
{
 
  myRadio.begin();
   myRadio.openWritingPipe( addresses[0]);
   myRadio.setPALevel(RF24_PA_MIN);
   myRadio.stopListening ();
  pinMode(sw1_pin, INPUT);
  pinMode(sw2_pin, INPUT);
  pinMode(sw3_pin, INPUT);


}

void loop()
{
const char text[] =("");
////////////////////////////////////////
// For First Switch
if(digitalRead(sw1_pin)==HIGH)
{
char text[] =("1");
 myRadio.write(&text, sizeof(text)); 

// delay(1000);
}
if(digitalRead(sw1_pin)==LOW)
{
char text[] =("2");
myRadio.write(&text, sizeof(text)); 
//delay(1000);
  
  
}
////////////////////////////////////////
// For Second Switch

if(digitalRead(sw2_pin)==HIGH)
{
char text[] =("3");
 myRadio.write(&text, sizeof(text)); 

// delay(1000);
}
if(digitalRead(sw2_pin)==LOW)
{
char text[] =("4");
myRadio.write(&text, sizeof(text)); 
//delay(1000);
  
  
}

///////////////////////////////////
// For Third switch

if(digitalRead(sw3_pin)==HIGH)
{
char text[] =("5");
 myRadio.write(&text, sizeof(text)); 

// delay(1000);
}
if(digitalRead(sw3_pin)==LOW)
{
char text[] =("6");
myRadio.write(&text, sizeof(text)); 
//delay(1000);
  
  
}

  }
