#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Don't use PIN 13, it's for the onboard LED
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

uint8_t pixels;

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

    reset();

    buildUp();
       reset();
      teamNumber();
       reset();
       for(int i=0;i<5;i++){
    colorShoot(55,10);
       }
       reset();
       //broken, stops loop
    bounce();
    reset();
    redBlue();
   reset();
   //broken, stops loop
    bounceBall();
    reset();
    
    pixels = strip.getPixels();
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
//  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

//  rainbow(20);
//  rainbowCycle(20);
//  theaterChaseRainbow(50);
    loop();
}
void reset(){
//  for(uint16_t i=0; i<strip.numPixels(); i++) {
//     strip.setPixelColor(i,40); 
//  }
//  strip.show();  
//  
//  delay(200);
   for(uint16_t i=0; i<strip.numPixels(); i++) {
     strip.setPixelColor(i,0); 
  }
   strip.show();
//   delay(200);
}

//straight up
void buildUp(){
      
     int foo [90] = {74, 99, 244, 111, 238, 254, 163, 198, 112, 85, 201, 88, 235, 137, 164, 232, 97, 135, 81, 35, 44, 210, 217, 102, 204, 247, 152, 30, 166, 28, 124, 31, 86, 8, 138, 0, 190, 22, 7, 67, 161, 79, 36, 197, 75, 61, 121, 159, 246, 250, 24, 181, 123, 127, 77, 189, 3, 82, 69, 143, 55, 162, 237, 5, 25, 125, 84, 211, 141, 222, 249, 20, 23, 17, 228, 41, 130, 175, 187, 184, 229, 242, 54, 13, 216, 19, 215, 145, 146, 46}; 
     for(uint16_t i=0; i<strip.numPixels()/2; i++) {
       strip.setPixelColor(i,foo[i*3+0],foo[i*3+1],foo[i*3+2]);
        strip.setPixelColor(59-i,foo[i*3+0],foo[i*3+1],foo[i*3+2]);
        strip.show();
        delay(200);
     }
}
void bounceBall(){
  //go up
   for(uint16_t i=0; i<strip.numPixels()/2; i++) {
        strip.setPixelColor(i,150,0,0);
        strip.setPixelColor(59-i,150,0,0);
        if(i!=0){
         strip.setPixelColor(i-1,0);
        strip.setPixelColor(59-(i-1),0);
        }
        
        strip.show();
        delay(50*(i*.12));
   }

   //go down
    for(uint16_t i=strip.numPixels()/2-1; i>0; i--) {
        strip.setPixelColor(i,0,0,150);
        strip.setPixelColor(59-i,0,0,150);
        
        if(i!=29){
         strip.setPixelColor(i+1,0);
          strip.setPixelColor(59-(i+1),0);
        }
        
        strip.show();
       
        delay(50*(i*.12));
   }
    
}
void redBlue(){
  for(uint16_t i=0; i<strip.numPixels()/2; i++) {
    strip.setPixelColor(i,150,0,0);
    strip.setPixelColor(59-i,150,0,0);
    strip.show();
     delay(50);
  }
  delay(100);
  
  for(uint16_t i=0; i<strip.numPixels()/2; i++) {
    strip.setPixelColor(i,0,0,150);
    strip.setPixelColor(59-i,0,0,150);
    strip.show();
     delay(50);
  }
  delay(100);
}
void teamNumber(){
    delay(1000);
    int r1 = 255;
    int r2 = 0;
    int r3 = 0;
    strip.setPixelColor(29,r1,r2,r3);
    strip.setPixelColor(30,r1,r2,r3);
     strip.setPixelColor(28,r1,r2,r3);
    strip.setPixelColor(31,r1,r2,r3);
     strip.setPixelColor(27,r1,r2,r3);
    strip.setPixelColor(32,r1,r2,r3);
     strip.setPixelColor(26,r1,r2,r3);
    strip.setPixelColor(33,r1,r2,r3);
     strip.setPixelColor(25,r1,r2,r3);
    strip.setPixelColor(34,r1,r2,r3);
    strip.show();
    delay(1000);

    r1 = 0;
    r2 = 0;
    r3 = 255;
     strip.setPixelColor(20,r1,r2,r3);
    strip.setPixelColor(39,r1,r2,r3);
     strip.setPixelColor(19,r1,r2,r3);
    strip.setPixelColor(40,r1,r2,r3);
     strip.setPixelColor(18,r1,r2,r3);
    strip.setPixelColor(41,r1,r2,r3);
     strip.setPixelColor(17,r1,r2,r3);
    strip.setPixelColor(42,r1,r2,r3);
    strip.show();
    delay(1000);

     r1 = 255;
    r2 = 0;
    r3 = 0;
     strip.setPixelColor(12,r1,r2,r3);
    strip.setPixelColor(47,r1,r2,r3);
     strip.setPixelColor(11,r1,r2,r3);
    strip.setPixelColor(48,r1,r2,r3);
    strip.show();
    delay(1000);

    r1 = 0;
    r2 = 0;
    r3 = 255;
    strip.setPixelColor(6,r1,r2,r3);
    strip.setPixelColor(53,r1,r2,r3);
     strip.setPixelColor(5,r1,r2,r3);
    strip.setPixelColor(54,r1,r2,r3);
     strip.setPixelColor(4,r1,r2,r3);
    strip.setPixelColor(55,r1,r2,r3);
     strip.setPixelColor(3,r1,r2,r3);
    strip.setPixelColor(56,r1,r2,r3);
     strip.setPixelColor(2,r1,r2,r3);
    strip.setPixelColor(57,r1,r2,r3);
     strip.setPixelColor(1,r1,r2,r3);
    strip.setPixelColor(58,r1,r2,r3);
       strip.setPixelColor(0,r1,r2,r3);
    strip.setPixelColor(59,r1,r2,r3);
      strip.show();
    delay(3000);
    
}
void colorShoot(uint32_t c, uint8_t wait) {
    // less than 30th pixel
   for(uint16_t i=0; i<strip.numPixels()/2; i++) {
      c=c+1;
       strip.setPixelColor(i, 0,0,c);
      strip.setPixelColor(59-i,0,0,c);
       strip.show();
      delay(wait);
      //turn prev pixel off
      if(i!=0){
        strip.setPixelColor(i-1, 0);
        strip.setPixelColor(59-(i-1),0);
      }
      strip.show();
      delay(wait);
   }
   //set the top two pixels to 0
   strip.setPixelColor(29, 0);
   strip.setPixelColor(30,0);
}
void bounce(){
   for(uint16_t i=4; i<strip.numPixels(); i++){
         for(uint16_t i1=0; i1<strip.numPixels(); i1++) {
            strip.setPixelColor(i1,70,0,0);
         }
        strip.setPixelColor(i,0,0,255);
        strip.setPixelColor(i-1,0,0,255);
        strip.setPixelColor(i-2,0,0,255);
        strip.setPixelColor(i-3,0,0,255);
        strip.setPixelColor(i-4,0,0,255);
        strip.show();
        
        delay(50);
   }
   for(uint16_t i=55; i>0; i--){ 
      for(uint16_t i1=0; i1<strip.numPixels(); i1++) {
            strip.setPixelColor(i1,70,0,0);
         }
        strip.setPixelColor(i,0,0,255);
        strip.setPixelColor(i+1,0,0,255);
        strip.setPixelColor(i+2,0,0,255);
        strip.setPixelColor(i+3,0,0,255);
        strip.setPixelColor(i+4,0,0,255);
        strip.show();

        delay(50);  
   }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
