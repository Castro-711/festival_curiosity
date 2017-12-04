#include <Adafruit_NeoPixel.h>

#ifdef __AVR__

#include <avr/power.h>

#endif

#define PIN 13

#define LEDS 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ400);

uint32_t silver;
uint32_t pink;
uint32_t black;
uint32_t torquise;
uint32_t magenta;
uint32_t indigo;

uint16_t evenArray[] = {0, 14, 2, 12, 4, 10, 6, 8};
uint16_t oddArray[] = {15, 1, 13, 3, 11, 5, 9, 7};

void setup() {

  // set up colors
  silver = strip.Color(192, 192, 192);
  pink = strip.Color(255, 0, 127);
  black = strip.Color(0, 0, 0);
  torquise = strip.Color(64, 224, 208);
  magenta = strip.Color(255, 0, 255);
  indigo = strip.Color(75, 0, 130);
  
  strip.begin();
  strip.show();

}

void loop() {

//  pulseFlagColors(400);
//  setBlockColor(black, 0, 9);
//  pulseFlag(1000);
//  setBlockColor(black, 0, 9);  
//  flag(1000);
//  setBlockColor(black, 0, 9);
//  pulseFlagColors(400);
//  setBlockColor(black, 0, 9);
//  flag(1000);
//  setBlockColor(black, 0, 9);
//  slideRight();
//  setBlockColor(black, 0, 9);

//  fadeOut(silver, 10, 0, 16);
//  fadeOut(pink, 10, 0, 16);
//  fadeOut(magenta, 75, 0, 16);
//  fadeOut(indigo, 75, 0, 16);
//  fadeOut(torquise, 75, 0, 16);

  intermitten(silver, torquise, 100);
  delay(750);
  setBlockColor(black, 0, 9);
  delay(500);
  intermitten(torquise, indigo, 100);
  delay(750);
  setBlockColor(black, 0, 9);
  delay(500);
  
  fadeInPink(1.5, 0, 16);
  slideColoursRight();
  delay(1000);
  invertedColourSlide();
  revInvertedColourSlide();
  slideColoursLeft();
  delay(1000);
  fadeOutPink(1.5, 0, 16);
  setBlockColor(black, 0, 9);
  delay(1000);

  intermitten(pink, silver, 100);
  delay(750);
  setBlockColor(black, 0, 9);
  delay(500);
  intermitten(torquise, magenta, 100);
  delay(750);
  setBlockColor(black, 0, 9);
  delay(500);

  fadeInPink(1.5, 0, 16);
  slideColoursRight();
  delay(1000);
  invertedColourSlide();
  revInvertedColourSlide();
  slideColoursLeft();
  fadeOutPink(1.5, 0, 16);
  setBlockColor(black, 0, 9);
  delay(1000);

  evenIntermitten(silver, 100);
  oddIntermitten(magenta, 100);
  delay(1000);
  setBlockColor(black, 0, 9);
  delay(1000);

  fadeInPink(1.5, 0, 16);
  slideColoursRight();
  delay(1000);
  invertedColourSlide();
  revInvertedColourSlide();
  slideColoursLeft();
  delay(1000);
  fadeOutPink(1.5, 0, 16);
  setBlockColor(black, 0, 9);
  delay(1000);

  strip.show();
} // loop

void intermitten(uint32_t cEven, uint32_t cOdd, uint16_t wait){
  evenIntermitten(cEven, wait);
  oddIntermitten(cOdd, wait);
}

void evenIntermitten(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 8; i++){
    strip.setPixelColor(evenArray[i], c);
    strip.show();
    delay(wait);
  }
}

void oddIntermitten(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 8; i++){
    strip.setPixelColor(oddArray[i], c);
    strip.show();
    delay(wait);
  }
}

void slideRight(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 9; i++){
    strip.setPixelColor(i, c);
    strip.setPixelColor(16 - i, c);
    strip.show();
    delay(wait); 
  } 
}

void slideLeft(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 9; i++){
    strip.setPixelColor(8 - i, c);
    strip.setPixelColor(9 + i, c);
    strip.show();
    delay(wait); 
  } 
}

void invertedSlide(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 9; i++){
    strip.setPixelColor(i, c);
    strip.setPixelColor(i + 8, c);
    strip.show();
    delay(wait); 
  } 
}

void revInvertedSlide(uint32_t c, uint16_t wait){
  for(uint16_t i = 0; i < 9; i++){
    strip.setPixelColor(8 - i, c);
    strip.setPixelColor(16 - i, c);
    strip.show();
    delay(wait); 
  } 
}

void slideColoursRight(){
  slideRight(pink, 75);
  slideRight(silver, 75);
  slideRight(indigo,75);
  slideRight(silver, 75);
  slideRight(torquise,75);
}

void slideColoursLeft(){
  slideLeft(torquise,75);
  slideLeft(silver, 75);
  slideLeft(indigo,75);
  slideLeft(silver, 75);
  slideLeft(pink, 75);
}

void invertedColourSlide(){
  invertedSlide(torquise,75);
  invertedSlide(silver, 75);
  invertedSlide(indigo, 75);
  invertedSlide(silver,75);
  invertedSlide(pink, 75);
  invertedSlide(silver, 75);;
}

void revInvertedColourSlide(){
  revInvertedSlide(torquise,75);
  revInvertedSlide(silver, 75);
  revInvertedSlide(indigo, 75);
  revInvertedSlide(silver,75);
  revInvertedSlide(pink, 75);
  revInvertedSlide(silver, 75);;
}

void setBlockColor(uint32_t c, uint16_t start, uint16_t finish){
  for(uint16_t i = start; i < finish; i++){
    strip.setPixelColor(i, c);
    strip.setPixelColor(15 - i, c);
  } 
    strip.show();
}

void fadeOutPink(uint16_t wait, uint16_t start, uint16_t fin){
  for(int y = 0; y < 127; y++){
    for(int x = 0; x < fin; x++){
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

void fadeInPink(uint16_t wait, uint16_t start, uint16_t fin){
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

/* notes:
 * changing the speed of the nerve cycle - was 300
 * 
 */
