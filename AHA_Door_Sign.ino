// AHA Vertical Door Sign
// Copyright 2013 ZachWick <zach@zachwick.xxx>
// Licensed under the GNU GPLv3 or later
//
// This program animates the door sign's LEDs and increments
// a binary counter of the number of times that the door has
// been opened.
//
// This program is intended for use on an Arduino Mega 2560
// Other Arduino variants are untested.

// Global Variables
int timer = 500; // A higher value => slower animations
int firstDIOPin = 0; // The lowest numbered digital IO pin to use
int lastDIOPin = 53; // The highest numbered digital IO pin to use

void 
setup()
{
  // Set all 
  for (int pin = firstDIOPin; pin < lastDIOPin + 1; pin++)
  {
    pinMode(pin, OUTPUT); 
  }
}

// The 'cascade' animation is a light up 'down & up' animation.
// @param int delayAmt the amount in ms to delay between successive LEDs
void
animation_cascade(int delayAmt)
{
  // Animate the LED's down
  for (int pin = firstDIOPin; pin < lastDIOPin + 1; pin++)
  {
    digitalWrite(pin, HIGH);
    delay(delayAmt);
    digitalWrite(pin, LOW);
  }
  
  // Animate the LEDs up
  for (int pin = lastDIOPin; pin >= 0; pin--)
  {
    digitalWrite(pin, HIGH);
    delay(delayAmt);
    digitalWrite(pin, LOW); 
  }
}

void 
loop()
{
  // Do the 'cascade' animation with delayAmt of 500ms
  animation_cascade(500);
  delay(timer);
}


