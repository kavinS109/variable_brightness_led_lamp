#include <Arduino.h>

// Rotary encoder pins
constexpr uint8_t ENCODER_BUTTON_PIN = 32;
constexpr uint8_t ENCODER_A_PIN = 14;
constexpr uint8_t ENCODER_B_PIN = 13;

// BJT PWM output
constexpr uint8_t PWM_PIN = 16;
constexpr uint32_t PWM_FREQUENCY = 1000;
constexpr uint8_t PWM_RESOLUTION = 8;

// 16 detents move from minimum to maximum.
constexpr int BRIGHTNESS_STEPS = 16;
constexpr int MIN_PWM = 3;    // Approximately 1% with 8-bit PWM
constexpr int MAX_PWM = 255;  // 100%

// Reversed to match your encoder wiring.
constexpr int ENCODER_DIRECTION = -1;
constexpr int TRANSITIONS_PER_CLICK = 4;

constexpr unsigned long DEBOUNCE_MS = 30;

// Start off, with brightness set to minimum.
bool lampOn = false;
int brightnessPosition = 0; // Range: 0–16
int currentPWM = 0;

// Button debounce
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChange = 0;

// Encoder tracking
uint8_t previousEncoderState;
int encoderMovement = 0;

// Quadrature transition lookup table
const int8_t encoderTable[16] = {
   0, -1,  1,  0,
   1,  0,  0, -1,
  -1,  0,  0,  1,
   0,  1, -1,  0
};

uint8_t readEncoder() {
  return (digitalRead(ENCODER_A_PIN) << 1) |
          digitalRead(ENCODER_B_PIN);
}

void setup() {
  pinMode(ENCODER_BUTTON_PIN, INPUT_PULLUP);
  pinMode(ENCODER_A_PIN, INPUT_PULLUP);
  pinMode(ENCODER_B_PIN, INPUT_PULLUP);

  previousEncoderState = readEncoder();

  ledcAttach(PWM_PIN, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcWrite(PWM_PIN, 0);
}

void loop() {
  unsigned long now = millis();

  // Read the rotary encoder.
  uint8_t encoderState = readEncoder();

  if (encoderState != previousEncoderState) {
    uint8_t transition = (previousEncoderState << 2) |
                         encoderState;

    // Discard invalid transitions where both bits change.
    if ((previousEncoderState ^ encoderState) == 3) {
      encoderMovement = 0;
    } else {
      encoderMovement += encoderTable[transition] *
                         ENCODER_DIRECTION;
    }

    previousEncoderState = encoderState;

    // Clockwise: increase one step.
    if (encoderMovement >= TRANSITIONS_PER_CLICK) {
      if (brightnessPosition < BRIGHTNESS_STEPS) {
        brightnessPosition++;
      }
      encoderMovement = 0;
    }
    // Counterclockwise: decrease one step.
    else if (encoderMovement <= -TRANSITIONS_PER_CLICK) {
      if (brightnessPosition > 0) {
        brightnessPosition--;
      }
      encoderMovement = 0;
    }
  }

  // Debounce the encoder button.
  bool buttonReading = digitalRead(ENCODER_BUTTON_PIN);

  if (buttonReading != lastButtonReading) {
    lastButtonChange = now;
    lastButtonReading = buttonReading;
  }

  if (now - lastButtonChange >= DEBOUNCE_MS &&
      buttonReading != stableButtonState) {
    stableButtonState = buttonReading;

    if (stableButtonState == LOW) {
      lampOn = !lampOn;
    }
  }

  // Convert position to PWM, rounding to the nearest value.
  int brightnessPWM = MIN_PWM +
    ((MAX_PWM - MIN_PWM) * brightnessPosition +
     BRIGHTNESS_STEPS / 2) / BRIGHTNESS_STEPS;

  // Apply brightness immediately.
  int targetPWM = lampOn ? brightnessPWM : 0;

  if (currentPWM != targetPWM) {
    currentPWM = targetPWM;
    ledcWrite(PWM_PIN, currentPWM);
  }
}