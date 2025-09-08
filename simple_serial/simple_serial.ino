// Simple example for serial debuging

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // wait until Serial is set up properly
  if (Serial.available()) {
    delay(10);
  }
  
  // println() function prints a provided parameter
  // and moves a cursor to a new line (adds '\n' character to the end)
  Serial.println("Hello world!");

  // print() just prints and doesn't move the cursor to the new line
  Serial.print("Hello");
  Serial.print(" world!");
  Serial.println();
  
  // Repeat 10 times
  for (int i = 0; i < 10; i++) {
    // Serial printing is perfect for keeping track of variable values
    Serial.print("Variable i = ");
    Serial.println(i);
  }

}

void loop() {
  delay(1);
}
