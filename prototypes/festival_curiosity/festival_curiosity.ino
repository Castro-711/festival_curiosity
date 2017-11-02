
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__

#include <avr/power.h>

#endif

#define PIN 13

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_RGB + NEO_KHZ800);

uint16_t black = 0;

// pink rgb values
uint16_t pink_red = 255;
uint16_t pink_blue = 75;

// strips
uint32_t pinky;

// to represent an rgb_value
struct rgb_value {  
  uint16_t value; // a num between 0 and 255
};

// to represent a colour
struct colour {
  uint32_t red;
  uint32_t blue;
  uint32_t green;
};

void setup() {
  // put your setup code here, to run once:
  strip.begin();

  // set up pink
  colour pink;
  pink.red = 255;
  pink.green = 0;
  pink.blue = 75;

}

void loop() {

    // set up pink
  colour pink;
  pink.red = 255;
  pink.green = 0;
  pink.blue = 75;
  // put your main code here, to run repeatedly:
    pinky = strip.Color(0, 255, 75);
//    uint32_t white = strip.Color(255, 255, 255);
//    uint32_t black = strip.Color(0, 0, 0);
//
//    strip.setBrightness(3);

  for(uint16_t i = 1; i < 9; i++)
    strip.setPixelColor(pinky, i);

  delay(20000);


// no. 1
// chase around the body
for(uint16_t i = 1; i < 10; i++)
{
  if(i % 2 == 0) // move forward
    vardel_chase(pinky, 0, 150, i, 30 - i);
  else          // move back  
    vardel_chase_back(pinky, 0, 150, i, 30 - i);
}

//  for(int i = 0; i < 165; i++){
//    strip.setPixelColor(i, pinky);
//    strip.show();
//  }
//  delay(500);
//  fadeOut(20);
}

//void fadeOut(uint32_t speed){
//  for(uint32_t i = 0; i < 255; i++){
//    strip.setBrightness(255 - i);
//    strip.show();
//    delay(speed);
//  }
//}
//
//void changeColour(uint32_t c){
//  for(int i = 0; i < 17; i++){
//    strip.setPixelColor(i, c);
//  }
//}
//
//uint16_t isPositive(uint16_t count){
//  if(count > 0)
//    count--;
//}

// vardel = variable delay with the same features as fixed
// a chase around the garment,
// this function has 5 params to customize you preferred chase effect
void vardel_chase(uint32_t c, uint16_t start, 
    uint16_t finish, uint16_t trail, uint16_t wait)
{
    uint32_t black = strip.Color(0, 0, 0);
    while(start <= (finish + trail))
    {
      if(start <= finish)
        strip.setPixelColor(start, c);
        
      strip.setPixelColor(start - trail, black);
      strip.show(); // this needs to be outside the if above
      delay(wait);
      start++;
    } 
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

