#include <SPI.h>  
#include "RF24.h" 

RF24 myRadio (7,8); 
//RF24 myRadio (7, 8); 

byte addresses[][6] = {"0"}; 

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
  
  Serial.begin(9600);
   myRadio.begin(); 
   myRadio.openReadingPipe(0, addresses[0]);
   myRadio.setPALevel(RF24_PA_MIN);
   myRadio.startListening ();
}


void loop()  
{


    while (myRadio.available() ) 
  {
   

    char text[32] = "";
    
      myRadio.read( &text, sizeof(text) );
      Serial.println(text);
 
    
  }

}
