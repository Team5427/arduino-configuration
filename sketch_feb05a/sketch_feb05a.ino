#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

int digitalVal; //HIGH when nothing is in the pin, LOW when something is
int ledPin = 4;

#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_RGB + NEO_KHZ400);

void setup() {
  // put your setup code here, to run once:
   #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  uint16_t i=0;
  uint32_t c= (255, 255, 255);
  strip.begin();
  strip.setPixelColor(i,c);
    digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  //strip.show();
}


void loop() {
  // put your main code here, to run repeatedly:

}
