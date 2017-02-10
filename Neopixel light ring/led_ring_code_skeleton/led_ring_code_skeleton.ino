#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

int digitalVal; //HIGH when nothing is in the pin, LOW when something is
int ledPin = 4;

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  Serial.begin(100);     // opens serial port, sets data rate to 9600 bps (Idk what bps should be)  
  strip.begin();
  strip.show(); //initialize all pixels to 'off'
  //Serial.print("setting up");

  pinMode(ledPin, INPUT_PULLUP); //sets the digital pin as input with pullup resistor
}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(strip.Color(0, 255, 30)); //Green
  Serial.print("color");
}

void setColor(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  
  strip.show();
}
