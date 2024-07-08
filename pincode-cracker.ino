#include "Keyboard.h"
#include "Mouse.h"

// Used the following examples:
// https://docs.arduino.cc/built-in-examples/usb/KeyboardMessage/
// https://docs.arduino.cc/built-in-examples/usb/KeyboardAndMouseControl/
// https://docs.arduino.cc/built-in-examples/basics/Blink/

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  Mouse.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Keyboard.print("This is a test...");
  Mouse.click(MOUSE_LEFT);
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);
}
