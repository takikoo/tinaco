/*
  Tinaco
 */

// constants won't change. They're used here to
// set pin numbers:
const int ledPins[] = {
  2, 3, 4, 5, 6
};       // an array of pin numbers to which LEDs are attached
const int btnLed = 13;
const int levelPins[] = {
  7, 8, 9, 10
};       // an array of pin numbers to which LEDs are attached
const int pushBtn = 11;
const int relayPin = 12;
const int pinCount = 5;           // the number of pins (i.e. the length of the array)

// variables will change:
int waterLevelState = 0;         // variable for reading the pushbutton status
int buttonState = 0;
int currentWaterLevel;

void setup() {
  // initialize the LED pins as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  pinMode(btnLed, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(levelPins[thisPin], INPUT);
  }
  pinMode(pushBtn, INPUT);
}

void loop() {
  currentWaterLevel = 0;
  for (int currentSet = 0; currentSet < 4; currentSet++) {
    waterLevelState = digitalRead(levelPins[currentSet]);
    if (waterLevelState == HIGH) {
    // turn LED on:
      digitalWrite(ledPins[currentSet + 1], HIGH);
      currentWaterLevel = currentSet + 1;
    } else {
    // turn LED off:
      digitalWrite(ledPins[currentSet + 1], LOW);
    }
  }
  if (currentWaterLevel == 0) {
    digitalWrite(ledPins[0], HIGH);
  } else {
    digitalWrite(ledPins[0], LOW);
  }
  
  buttonState = digitalRead(pushBtn);
  if (buttonState == HIGH && currentWaterLevel < 4) {
    digitalWrite(relayPin, LOW);
    digitalWrite(btnLed, HIGH);

    for (int currentLoading = currentWaterLevel; currentLoading < pinCount; currentLoading++) {
      digitalWrite(ledPins[currentLoading], HIGH);
      delay(200);
    }
  } else {
    digitalWrite(relayPin, HIGH);
    digitalWrite(btnLed, LOW);
  }
}
