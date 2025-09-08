// Purposely broken code which you need to fix

// What should happen:
// led strip on pin 6 should blink every second
// you need to add an extra line which was removed

// library for led strip
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_1 6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10

// Object for defining led strip
// it takes number of pixels, led strip pin and the type of led strip as parameters
Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NUMPIXELS, PIN_1, NEO_GRBW + NEO_KHZ800);


// keep track if led strip is currently on or off
int ledState_1 = 0;

// keep track of the last time led strip state was changed
unsigned long previousMillis_1 = 0;

// blinking intervals for led strips
int interval_1 = 1000; // 1000 milliseconds = 1 second

void setup() {
  pixels_1.begin(); // This initializes the NeoPixel library.

  pixels_1.clear(); // Set all leds in the first strip to off
}

void loop() {
  // millis() function returns how much time passed from the start of the code

  if (millis() - previousMillis_1 >= interval_1) { // checks whether enough time passed from last change
    // if led was turned off then turn it on and other way round
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
}


// -------------------HINT 1---------------------
// start by checking if code in if statement ever runs
// ----------------------------------------------


// -------------------HINT 2---------------------
// check if previous time is properly tracked
// ----------------------------------------------
