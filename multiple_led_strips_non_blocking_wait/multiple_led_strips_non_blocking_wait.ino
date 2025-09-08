// Non blocking delay blink code for a multiple led strips

// Main idea:
// Blinks first led strip every 200 miliseconds
// and the second strip every 900 miliseconds

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


// keep track if led strip is currently on or off
int ledState_1 = 0;
int ledState_2 = 0;

// keep track of the last time led strip state was changed
unsigned long previousMillis_1 = 0;
unsigned long previousMillis_2 = 0;

// blinking intervals for led strips
int interval_1 = 200;
int interval_2 = 900;

void setup() {
  pixels_1.begin(); // This initializes the NeoPixel library.
  pixels_2.begin(); // This initializes the NeoPixel library.

  pixels_1.clear(); // Set all leds in the first strip to off
  pixels_2.clear(); // Set all leds in the second strip to off
}

void loop() {
  // millis() function returns how much time passed from the start of the code

  // CONTROL FIRST LED STRIP
  if (millis() - previousMillis_1 >= interval_1) { // checks whether enough time passed from last change
    // save the last time then led state changed which is now
    previousMillis_1 = millis();

    if (ledState_1 == 0) {
      pixels_1.setPixelColor(0, pixels_1.Color(100, 0, 0, 0)); // first led strip on

      // keep track of current led state
      ledState_1 = 1;
    } else {
      pixels_1.setPixelColor(0, pixels_1.Color(0, 0, 0, 0)); // first led strip off

      // keep track of current led state
      ledState_1 = 0;
    }

    // commands above only store the color value with the
    // show() function we send it to the led strip
    pixels_1.show();
  }

  // CONTROL SECOND LED STRIP
  if (millis() - previousMillis_2 >= interval_2) { // checks whether enough time passed from last change
    // save the last time then led state changed which is now
    previousMillis_2 = millis();

    if (ledState_2 == 0) {
      pixels_2.setPixelColor(0, pixels_2.Color(100, 0, 0, 0)); // second led strip on

      // keep track of current led state
      ledState_2 = 1;
    } else {
      pixels_2.setPixelColor(0, pixels_2.Color(0, 0, 0, 0)); // second led strip off

      // keep track of current led state
      ledState_2 = 0;
    }

    // commands above only store the color value with the
    // show() function we send it to the led strip
    pixels_2.show();
  }
}
