#include <SPI.h>  
#include "RF24.h"

RF24 myRadio (8, 9);
byte addresses[][6] = {"0"};
#define switch 7
int sendmes[1]={000};


void setup()
{
 
  myRadio.begin();
   myRadio.openWritingPipe( addresses[0]);
   myRadio.setPALevel(RF24_PA_MIN);
   myRadio.stopListening ();

}

void loop()
{

const char text[] =("he");
 myRadio.write(&text, sizeof(text)); 
 //myRadio.write(&text1, sizeof(text)); 
// delay(1000);
  }
