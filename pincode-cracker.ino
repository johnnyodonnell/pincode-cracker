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

  // signal that loop is about to start
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void attempt_passcode(char* passcode) {
  Keyboard.println(passcode);
  // Mouse.click();
}

void attempt_passcodes(char* passcode, int index, int length) {
  if (index >= length) {
    attempt_passcode(passcode);
  } else {
    for (int i = 0; i < 10; ++i) {
      passcode[index] = '0' + i;
      attempt_passcodes(passcode, index + 1, length);
    }
  }
}

void loop() {
  int max_length = 10;
  char passcode[max_length] = "";

  for (int i = 0; i < max_length; ++i) {
    attempt_passcodes(passcode, 0, i + 1);
  }
}
