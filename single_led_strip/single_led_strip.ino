// Simple blink code for a single led strip

// library for led strip
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10

// Object for defining led strip
// it takes number of pixels, led strip pin and the type of led strip as parameters
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

  pixels.clear(); // Set all leds in the strip to off
}

void loop() {
  // set the first led on the strip to red
  // function takes:
  //     led number (from 0 to NUMPIXELS - 1),
  //     RGB values (from 0,0,0 to 255,255,255),
  //     white led intensity (from 0 to 255)
  pixels.setPixelColor(0, pixels.Color(100, 0, 0, 0));

  // send the color values to the led strip
  pixels.show();

  // wait for 500 miliseconds
  delay(500);

  // set the first led color to black
  pixels.setPixelColor(0, pixels.Color(0, 0, 0, 0));

  // send the color values to the led strip
  pixels.show();

  // wait for 500 miliseconds
  delay(500);
}
