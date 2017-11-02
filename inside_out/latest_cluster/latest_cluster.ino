#include <Adafruit_NeoPixel.h>

#ifdef __AVR__

#include <avr/power.h>

#endif

#define PIN 26
#define LEDS 8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_RGB + NEO_KHZ800);

uint32_t greenish;
uint32_t black;
uint32_t white;
uint32_t ice_blue;

void setup() {
  strip.begin();
  strip.show();

}

void loop() {
  // setup colours
  greenish = strip.Color(255, 0, 127);
  ice_blue = strip.Color(0, 0, 127);
  black = strip.Color(0, 0, 0);
  white = strip.Color(255, 255, 255);

  // sequence 1
  // fade in then out then into different colour
  for(int i = 0; i < 3; i++){
    
    fadeInGreenish(1, 0, 16);
    // now dim cluster R
    fadeOutGreenish(1, 0, 16);
  
    fadeInWhite(1, 0, 16);
    fadeOutWhite(1, 0, 16);
    
    fadeInIceB(1, 0, 16);
    fadeOutIceB(1, 0, 16);
  } // i

  // sequence 2
  // colour wipe cycle
  for(int i = 0; i < 6; i++){
    colorWipe(greenish, 50);
    colorWipe(white, 50);
    colorWipe(ice_blue, 50);

    delay(200);
    
    colorWipeRev(greenish, 50);
    colorWipeRev(white, 50);
    colorWipeRev(ice_blue, 50);
  } /// i

  // sequence 3
  // a combination of 1 and 2
  for(int i = 0; i < 3; i++){

    fadeInGreenish(1, 0, 16);
    fadeOutGreenish(1, 0, 16);

    // now do a cycle
    colorWipe(ice_blue, 50);
    colorWipeRev(white, 50);
    colorWipe(greenish, 50);
    
    fadeInWhite(1, 0, 16);
    fadeOutWhite(1, 0, 16);

    // now do a cycle
    colorWipe(greenish, 50);
    colorWipeRev(ice_blue, 50);
    colorWipe(white, 50);

    fadeInIceB(1, 0, 16);
    fadeOutIceB(1, 0, 16);

    // now do a cycle
    colorWipe(white, 50);
    colorWipeRev(greenish, 50);
    colorWipe(ice_blue, 50);
    
  } // i
} // loop


void fadeOutGreenish(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = 0; x < 8; x++){
      strip.setPixelColor(x, strip.Color(255 - 2 * y, 0, 127 - y));
      strip.show();
    }
    if(y < 66)
      delay(wait * 10);
    else if(y < 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void fadeInGreenish(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = start; x < fin; x++){
      strip.setPixelColor(x, strip.Color(y * 2, 0, y));
      strip.show();
    }
    if(y > 66)
      delay(wait * 10);
    else if(y > 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void fadeOutIceB(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = 0; x < 8; x++){
      strip.setPixelColor(x, strip.Color(0, 0, 127 - y));
      strip.show();
    }
    if(y < 66)
      delay(wait * 10);
    else if(y < 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void fadeInIceB(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = start; x < fin; x++){
      strip.setPixelColor(x, strip.Color(0, 0, y));
      strip.show();
    }
    if(y > 66)
      delay(wait * 10);
    else if(y > 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void fadeOutWhite(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = 0; x < 8; x++){
      strip.setPixelColor(x, strip.Color(255 - 2 * y, 255 - 2 * y, 255 - 2 * y));
      strip.show();
    }
    if(y < 66)
      delay(wait * 10);
    else if(y < 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void fadeInWhite(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = start; x < fin; x++){
      strip.setPixelColor(x, strip.Color(y * 2, y * 2, y * 2));
      strip.show();
    }
    if(y > 66)
      delay(wait * 10);
    else if(y > 99)
      delay(wait * 5);
    else 
      delay(wait);
 }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < 8; i++) {
     strip.setPixelColor(i, c);
     strip.setPixelColor(i + 8, c);
     strip.show();
     delay(wait);
   }
}

void colorWipeRev(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < 8; i++) {
     strip.setPixelColor(7 - i, c);
     strip.setPixelColor(15 - i, c);
     strip.show();
     delay(wait);
   }
}

// unused functions:

// nerve trails that flow pixels
// from one cluster to the next,
// this function has 5 params to customize you preferred trail effect
void nerve_cycle(uint32_t c, uint16_t start, 
    uint16_t finish, uint16_t trail, uint16_t wait){
      
    while(start <= (finish + trail)){
      if(start % 3 == 1)
        c = greenish;
      else if(start % 3 == 0) 
        c = white;
      else 
        c = ice_blue;
      
      if(start <= finish){
        strip.setPixelColor(start, c);
        strip.setPixelColor(start + 8, c);
      }
        
        
      strip.show(); // this needs to be outside the if above
      delay(wait);
      start++;
    } // while
}

// this function performs the opposite as vardel_chase
// in that it goes the opposite direction starting from the end
void nerve_cycle_rev(uint32_t c, uint16_t start, 
  uint16_t finish, uint16_t trail, uint16_t wait){
    
  while(finish + trail > start){
    if(finish > start){
        strip.setPixelColor(finish, c);
        strip.setPixelColor(finish + 8, c);
    }
      
    strip.show(); // this needs to be outside the if above
    delay(wait);
    finish--;
  } // while
}

/* notes:
 * changing the speed of the nerve cycle - was 300
 * 
 */
