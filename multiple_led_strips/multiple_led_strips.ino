// Simple blink code for a multiple led strips

// Main idea:
// Blinks first led strip every 250 miliseconds
// and the second strip every 500 miliseconds

// library for led strip
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_1 6
#define PIN_2 5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10

// Object for defining led strip
// it takes number of pixels, led strip pin and the type of led strip as parameters
Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NUMPIXELS, PIN_1, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixels_2 = Adafruit_NeoPixel(NUMPIXELS, PIN_2, NEO_GRBW + NEO_KHZ800);

void setup() {
  pixels_1.begin(); // This initializes the NeoPixel library.
  pixels_2.begin(); // This initializes the NeoPixel library.

  pixels_1.clear(); // Set all leds in the first strip to off
  pixels_2.clear(); // Set all leds in the second strip to off
}

void loop() {
  pixels_1.setPixelColor(0, pixels_1.Color(100, 0, 0, 0)); // first led strip on
  pixels_1.show();

  delay(250);

  pixels_1.setPixelColor(0, pixels_1.Color(0, 0, 0, 0)); // first led strip off
  pixels_1.show();

  pixels_2.setPixelColor(0, pixels_2.Color(100, 0, 0, 0)); // second led strip on
  pixels_2.show();

  delay(250);

  pixels_1.setPixelColor(0, pixels_1.Color(100, 0, 0, 0)); // first led strip on
  pixels_1.show();

  delay(250);

  pixels_1.setPixelColor(0, pixels_1.Color(0, 0, 0, 0)); // first led strip off
  pixels_1.show();

  pixels_2.setPixelColor(0, pixels_2.Color(0, 0, 0, 0)); // second led strip off
  pixels_2.show();

  delay(250);
}
