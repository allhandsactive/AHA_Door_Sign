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
int first_dio_pin = 0; // The lowest numbered digital IO pin to use
int last_dio_pin = 53; // The highest numbered digital IO pin to use
int led_pins_per_letter = 8; // The number of LED pins per letter block
// The pins that correspond to the LEDs of the first letter
int first_letter_leds[] = {0,1,2,3,4,5,6,7};
// The pins that correspond to the LEDs of the second letter
int second_letter_leds[] = {8,9,10,11,12,13,14,15};
// The pins that correspond to the LEDs of the third letter
int third_letter_leds[] = {16,17,18,19,20,21,22,23};

void 
setup()
{
  // Set all 
  for (int pin = first_dio_pin; pin < last_dio_pin + 1; pin++)
  {
    pinMode(pin, OUTPUT); 
  }
}

// The 'cascade' animation is a light up 'down & up' animation.
// @param int delay_amt the amount in ms to delay between successive LEDs
void
animation_cascade(int delay_amt)
{
  // Animate the LED's down
  for (int pin = first_dio_pin; pin < last_dio_pin + 1; pin++)
  {
    digitalWrite(pin, HIGH);
    delay(delay_amt);
    digitalWrite(pin, LOW);
  }
  
  // Animate the LEDs up
  for (int pin = last_dio_pin; pin >= first_dio_pin; pin--)
  {
    digitalWrite(pin, HIGH);
    delay(delay_amt);
    digitalWrite(pin, LOW); 
  }
}

// The 'block' animation is a letter-by-letter lighting of the sign
// The LEDs that make up each letter are defined as global variables
// @param int delay_amt the amount in ms to delay between successive LEDs
void
animation_block(int delay_amt)
{
  // Light the first letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(first_letter_leds[pin], HIGH); 
  }
  
  delay(delay_amt);
  
  // Light the second letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(second_letter_leds[pin], HIGH); 
  }
  
  delay(delay_amt);
  
  // Light the third letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(third_letter_leds[pin], HIGH);
  }
  
  delay(delay_amt);
  
  // Turn off the first letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(first_letter_leds[pin], LOW); 
  }
  
  delay(delay_amt);
  
  // Turn off the second letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(second_letter_leds[pin], LOW); 
  }
  
  delay(delay_amt);
  
  // Turn off the third letter's LEDs
  for (int pin = 0; pin <= led_pins_per_letter; pin++)
  {
     digitalWrite(third_letter_leds[pin], LOW);
  }
}

void 
loop()
{
  // Do the 'cascade' animation with delayAmt of 500ms
  animation_cascade(500);
  delay(timer);
  animation_block(1000);
  delay(timer);
}


