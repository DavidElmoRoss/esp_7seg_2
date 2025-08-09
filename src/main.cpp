/*
  Title:  This program scrolls a message on the 4 digit display
  Author: David Elmo Ross
  Date:   July 24th, 2025
  Description: This program uses the setSegments() function to scroll
               text characters across the 4 digit display.
               The hex values for these characters are in a char array.
               The array contains patterns for "Start Count" which it
               scrolls forever.
*/

//INCLUDE SECTION
#include <Arduino.h>
#include <TM1637Display.h>

//DEFINE SECTION
#define CLK  33                // The ESP32 pin GPIO33 connected to CLK
#define DIO  32                // The ESP32 pin GPIO32 connected to DIO
#define Colon_On 0x40          // mask value to turn ON Colon on display
#define Colon_Off 0x00         // mask value to turn OFF Colon on display

//HARDWARE DEFINITION SECTION
TM1637Display segment = TM1637Display(CLK, DIO);

// Global Variables
uint8_t index_value;          // index_value defined as having 8 bit data values

unsigned char SEG_DONE[] =    // This has the scrolling message
{
0x00,0x00,0x00,0x00,          // 4 leading blanks
 0x6d,0x78,0x77,0x50,0x78,    // StArt
 0,0x39,0x5c,0x1c,0x54,0x78,  // Count
 0x00,0x00,0x00,0x00          // 4 trailing blanks
};

void setup()
{
 segment.setBrightness(4);    // set the brightness to 4 in range (0:dimmest, 7:brightest)
 segment.clear();             // clear the 4 digit display
}

void loop() 
{
  for(index_value=0;index_value<16;++index_value)             // bob is used to send message to 4 digit display
  {
     segment.setSegments(SEG_DONE+index_value);  // setSegments will set display segments to values in SEG_DONE
     delay(500);                         // we are scrolling the message every 0.5 seconds
   }
  
}
