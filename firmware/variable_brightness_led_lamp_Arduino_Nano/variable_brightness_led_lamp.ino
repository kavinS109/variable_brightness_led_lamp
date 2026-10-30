const int bjtPin = 3;      // PWM output to BJT base
const int buttonPin = 2;   // Pushbutton input

// PWM values corresponding to 0%, 25%, 75%, and 100%
const int brightnessLevels[] = {0, 64, 191, 255};
const int numLevels = 4;

int currentLevel = 0;

// Button state tracking
int lastButtonState = HIGH;
int buttonState = HIGH;

// Debouncing
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(bjtPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Start with LED off
  analogWrite(bjtPin, brightnessLevels[currentLevel]);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Button input changed - restart debounce timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Only accept the change if it remains stable
  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      // Button has just been pressed
      if (buttonState == LOW) {
        currentLevel++;

        // Return to 0% after 100%
        if (currentLevel >= numLevels) {
          currentLevel = 0;
        }

        analogWrite(bjtPin, brightnessLevels[currentLevel]);
      }
    }
  }

  lastButtonState = reading;
}