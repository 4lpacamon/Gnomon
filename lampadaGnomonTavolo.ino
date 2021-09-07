 
/*
  Lampada Gnomon using rgba led
  or ws2812b  
  library used: Neopixel,Serial bluetooth

  how to use: download Serial Bluetooth Terminal 
  from Play Store and connect "ESP32_GnomonTavolo" 
  via bluetooth on your Android smartphone
        
  created 08 Jan 2021
  modified 13 Jan 2021
  by Kaori Hattori
*/

#include <Adafruit_NeoPixel.h>
#include "BluetoothSerial.h"

#define PIN  2
#define NUMPIXELS 30 //n LEDs in use
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
#define BRIGHTNESS 50 // Set brightness to about 1/5 (max 255) 
#define START NUMPIXELS-30// Setting up the led's position where you want to light

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable
/*
 * menu:
 * switch off 'a'
 * led 2500 turn on the 1st cluster @2500K 'b'
 * led 3400 turn on the 1st cluster @3400K 'c'
 * led 3500 turn on the 1st,2nd cluster @3500K 'd'
 * led 4400 turn on the 1st,2nd cluster @4400K 'e'
 * led 4500 turn on all clusters @4500K 'f'
 * led 5500 turn on all clusters @5500K 'g'
*/
const char turnOFF ='a';
const char turnON ='z';
const char turnON1_1 ='b';
const char turnON1_2 ='c';
const char turnON2_1 = 'd';
const char turnON2_2 ='e';
const char turnON3_1 = 'f';
const char turnON3_2 = 'g';

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_GnomonTavolo"); //Bluetooth device name
  
  pixels.begin();//inizialize LEDs
  pixels.clear();//LEDs are "flushed"
    
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println("To turn ON send: b");//print on serial monitor  
  Serial.println("To turn OFF send: a"); //print on serial monitor  
}

void loop() {
  pixels.clear();  
  receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());  
  }
  
  if (SerialBT.available()) {
    
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor    
    SerialBT.println(receivedChar);//print on the app    
    SerialBT.write(receivedChar); //print on serial monitor

    if(receivedChar == turnOFF)
    {
     SerialBT.println("\nLED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
     pixels.clear();// turn the LED off 
     for(int i=0; i<NUMPIXELS; i++) { 
     // pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // Here I'm not using any LED:
     pixels.setPixelColor(i, pixels.Color(0, 0, 0));
     }
     pixels.show();   
    }
    
    if(receivedChar == turnON1_1 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @2500K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a white warm color, RGB(255, 166, 69):
     for(int i=START; i<START+10; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 166, 69));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }    

    if(receivedChar == turnON1_2 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @3400K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly orange white warm color, RGB(255, 198, 130):
     for(int i=START; i<START+10; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 198, 130));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }    

    if(receivedChar == turnON2_1 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @3500K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly orange white warm color, RGB(255, 201, 135):
     for(int i=START; i<START+20; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 201, 135));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }
    
    if(receivedChar == turnON2_2 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @4400K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly yellowish white warm color, RGB(255, 221, 180):
     for(int i=START; i<START+20; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 221, 180));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }

    if(receivedChar == turnON3_1 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @4500K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly orange white warm color, RGB(255, 223, 184):
     for(int i=START; i<NUMPIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 223, 184));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }

if(receivedChar == turnON3_2 )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @5500K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly white warm color, RGB(255, 238, 222):
     for(int i=START; i<NUMPIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 238, 222));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }

if(receivedChar == turnON )
    {
     SerialBT.println("\nLED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     
     //initialize LEDs
     pixels.clear();// clean the settings
     //first cluster light on @5500K
     //pixels.color() takes RGB values, from 0,0,0 up to 255,255,255
     // I'm using a slightly white warm color, RGB(255, 51, 0):
     for(int i=START; i<NUMPIXELS; i++) { 
      pixels.setPixelColor(i, pixels.Color(255, 51, 0));
     }
     pixels.show();   // Send the updated pixel colors to the hardware.
     delay(DELAYVAL); // Pause before next pass through loop
     
    }
  delay(100);
  }
}
