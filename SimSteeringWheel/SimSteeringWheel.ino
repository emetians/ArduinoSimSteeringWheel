#include "Joystick.h"

// PIN SETUP
#define PIN_STEERING_AXIS A0
#define PIN_THROTTLE_AXIS A1
#define PIN_BRAKE_AXIS A3
#define PIN_CLUTCH_AXIS A2
#define PIN_BUTTON 8

int steeringOldValue = 0;
int throttleOldValue = 0;
int brakeOldValue = 0;
int clutchOldValue = 0;

// Create the Joystick
Joystick_ Joystick;

void setup() {
  pinMode(PIN_STEERING_AXIS, INPUT);
  pinMode(PIN_THROTTLE_AXIS, INPUT);
  pinMode(PIN_BRAKE_AXIS, INPUT);
  pinMode(PIN_CLUTCH_AXIS, INPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);
  Joystick.setRxAxisRange(0, 1023);
  Joystick.begin();
}

void loop() {
  int steeringValue = 1023 - analogRead(PIN_STEERING_AXIS); // 1023 - readed value means revering axis
  int throttleValue = 1023 - analogRead(PIN_THROTTLE_AXIS);
  int brakeValue = 1023 - analogRead(PIN_BRAKE_AXIS);
  int clutchValue = 1023 - analogRead(PIN_CLUTCH_AXIS);
  
  if (steeringValue != steeringOldValue) {
    steeringOldValue = steeringValue;
    Joystick.setXAxis(steeringValue);
  }

  if (throttleValue != throttleOldValue) {
    throttleOldValue = throttleValue;
    Joystick.setYAxis(throttleValue);
  }

  if (brakeValue != brakeOldValue) {
    brakeOldValue = brakeValue;
    Joystick.setZAxis(brakeValue);
  }

  if (clutchValue != clutchOldValue) {
    clutchOldValue = clutchValue;
    Joystick.setRxAxis(clutchValue);
  }

  int buttonState = digitalRead(PIN_BUTTON);
  Joystick.setButton(0, !buttonState);
  delay(50);
}
