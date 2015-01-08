#include <Adafruit_NeoPixel.h>

// Parameter 1 = number of pixels in strip
#define PIXEL 1
// Parameter 2 = Arduino pin number (most are valid)
#define PIN 0
// Parameter 3 = pixel type flags, add together as needed:
// NEO_KHZ800 800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
// NEO_KHZ400 400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
// NEO_GRB Pixels are wired for GRB bitstream (most NeoPixel products)
// NEO_RGB Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL, PIN, NEO_GRB + NEO_KHZ800);

#define COLOR_MAX 255
#define COLOR_STEP 15
uint32_t red = strip.Color(COLOR_MAX, 0, 0);
uint32_t green = strip.Color(0, COLOR_MAX, 0);
uint32_t blue = strip.Color(0, 0, COLOR_MAX);
uint32_t white = strip.Color(COLOR_MAX, COLOR_MAX, COLOR_MAX);
uint32_t dark = strip.Color(0, 0, 0);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  rainbow();
  fadeIn();
  setColor(white, 60*7);
  rainbow();
  setColor(blue, 60);
  rainbow();
  setColor(white, 60*7);
  fadeOut();
  rainbow();
  setColor(dark, 60*8);
}

void setColor(uint32_t color, uint32_t waitingPeriodMin) {
  for(uint8_t pos=0; pos<strip.numPixels(); pos++) {
    strip.setPixelColor(pos, color);
    strip.show();
    waitMin(waitingPeriodMin);
  }
}

void waitMin(uint32_t min) {
  for(uint32_t m=0; m<min; m++) {
    for(uint8_t sec=0; sec<60; sec++) {
      delay(1000);
    }
  }
}

void fadeIn() {
  for(uint8_t i=0; i<=COLOR_MAX/COLOR_STEP; i++) {
    setColor(strip.Color(i*COLOR_STEP, 0, 0), 1);
  }
}

void fadeOut() {
  for(uint8_t i=0; i<=COLOR_MAX/COLOR_STEP; i++) {
    setColor(strip.Color(COLOR_MAX-(i*COLOR_STEP), 0, 0), 1);
  }
}

void rainbow() {
  for(uint16_t j=0; j<256; j++) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(10);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

