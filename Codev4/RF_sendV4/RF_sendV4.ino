#include <SPI.h>  
#include "RF24.h"

 

RF24 myRadio (8, 9);

byte addresses[][6] = {"0"};
#define sw1_pin 2
#define sw3_pin 3
#define sw2_pin 4
#define sw4_pin 5
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
  pinMode(sw4_pin, INPUT);

}

void loop()
{
const char text[] =("");

const char text2[] =("");
////////////////////////////////////////
// For First Switch
if(digitalRead(sw1_pin)==HIGH  && digitalRead(sw2_pin)==LOW  )
{

 
char text[] =("1");
 myRadio.write(&text, sizeof(text)); 
 delay(0);
  


}

/*if(digitalRead(sw1_pin)==LOW    )
{

  while(digitalRead(sw1_pin)==HIGH  && digitalRead(sw2_pin)==LOW)
  {
char text[] =("2");
 myRadio.write(&text, sizeof(text)); 
 delay(0);
  }


}*/

////////////////////////////////////////
// For Second Switch

while (digitalRead(sw3_pin)==HIGH  && digitalRead(sw1_pin)==LOW )
{

char text2[] =("3");
 myRadio.write(&text2, sizeof(text2)); 
 delay(0);
  


}

if(digitalRead(sw2_pin)==HIGH  )
{

 
char text[] =("2");
 myRadio.write(&text, sizeof(text)); 
 delay(0);
  


}

else if(digitalRead(sw4_pin)==HIGH  )
{

 
char text[] =("4");
 myRadio.write(&text, sizeof(text)); 
 delay(0);
  


}


///////////////////////////////////
// For Third switch

/*else if(digitalRead(sw3_pin)==HIGH)
{
char text[] =("5");
 myRadio.write(&text, sizeof(text)); 

}*/


  }
