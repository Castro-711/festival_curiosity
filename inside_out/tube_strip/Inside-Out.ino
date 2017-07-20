#include <Adafruit_NeoPixel.h>

#ifdef __AVR__

#include <avr/power.h>

#endif

#define PIN 10
#define LEDS 176

// strip layout
// 168 -- total end
// 111 -> 168 last strip

// 110 -- mid end
// 59 -> 110

// 58 -- first end
// minus 13 for the strip to the arduino...
// 13 - 58

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t greenish;
uint32_t black;
uint32_t white;
uint32_t pink;

void setup() {
  strip.begin();
  strip.show();
}

void loop() { 
  // set up colours
  greenish = strip.Color(0, 255, 127);
  black = strip.Color(0, 0, 0);
  white = strip.Color(255, 255, 255);
  pink = strip.Color(255, 0, 75);

  for(int i = 0; i < 4; i++){
      // full circle 
    vardel_chase_back(pink, 111, 168, 5, 75);
    vardel_chase_back(pink, 13, 58, 5, 75);
    vardel_chase_back(pink, 59, 110, 5, 75);
  }

    simpleWave(1, 2, 120);
    colorWipe(black, 1);
}


// this function performs the opposite as vardel_chase
// in that it goes the opposite direction starting from the end
void vardel_chase_back(uint32_t c, uint16_t start, 
  uint16_t finish, uint16_t trail, uint16_t wait)
{
  uint32_t black = strip.Color(0, 0, 0);
  while(finish + trail > start)
  {
    if(finish > start)
      strip.setPixelColor(finish, c);
      
    strip.setPixelColor(finish + trail, black);
    strip.show(); // this needs to be outside the if above
    delay(wait);
    finish--;
  } 
}

// lindys code -->
void simpleWave(float rate, int cycles, int wait) {
  float pos = 0.0;
  // cycle through x times
  for (int x = 13; x < (60*cycles); x++)
  {
    pos = pos + rate;
    for (int i = 13; i < 60; i++) {
      // sine wave, 3 offset waves make a rainbow!
      float level = sin(i + pos) * 127 + 128;
      // set color level
      strip.setPixelColor(i, (int)level/(i*-1), 0, (int)level / i+10);
    }
    strip.show();
    delay(wait);
  }
}  

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
 }
}
