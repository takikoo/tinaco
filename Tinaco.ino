/*
  Tinaco
 */

// constants won't change. They're used here to
// set pin numbers:
const int ledPins[] = {
  2, 3, 4, 5, 6
};       // an array of pin numbers to which LEDs are attached
const int levelPins[] = {
  7, 8, 9, 10
};       // an array of pin numbers to which LEDs are attached
const int pushBtn = 11;
const int relayPin = 12;
int pinCount = 5;           // the number of pins (i.e. the length of the array)

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pins as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  pinMode(relayPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(levelPins[thisPin], INPUT);
  }
  pinMode(pushBtn, INPUT);
}

void loop() {
  for (int currentSet = 0; currentSet < pinCount; currentSet++) {
    buttonState = digitalRead(levelPins[currentSet]);
    if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPins[currentSet + 1], HIGH);
    } else {
    // turn LED off:
    digitalWrite(ledPins[currentSet + 1], LOW);
    }
  }
  buttonState = digitalRead(pushBtn);
  if (buttonState == HIGH) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
}
