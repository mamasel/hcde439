

//pin of red
const int redLED = 10;

//pin of yellow
const int yellowLED = 9;

//pin of green
const int greenLED = 11;

//pin of button
const int buttonPin = 2;

// curent state of the button
int buttonState = HIGH;

// previous state of the button
int lastButtonState = HIGH;

// controls the color for the if statement
int color = -1;

// controls the brightness for the fade
int brightness = 0;

// the amount of brightness to increment for the fade
int fadeAmount = 5;

void setup() {

  //initializing red
  pinMode(redLED, OUTPUT);
  
  //initializing yellow
  pinMode(yellowLED, OUTPUT);

   //initializing yellow
  pinMode(greenLED, OUTPUT);

  //initializing button
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the button
  buttonState = digitalRead(buttonPin);

  // Detect a new button press
  if (buttonState == LOW && lastButtonState == HIGH) {
    color = color + 1;

    // if the color becomes greater than 2, restart to 0
    if (color > 2) {
      color = 0;
    }

    // brightness inside loop to be incremented and restarted 
    brightness = 0;

    // fade amount inside loop to be incremented and restarted 
    fadeAmount = 5;
  }

  lastButtonState = buttonState;

  // Fade the selected LED
  if (brightness < 255) {
    brightness = brightness + fadeAmount;

    // brightness limit is 255
    if (brightness > 255) {
      brightness = 255;
    }
  }

  // Select the color
  if (color == 0) {
    analogWrite(redLED, 0);
    analogWrite(yellowLED, 0);
    analogWrite(greenLED, brightness);
  }
  else if (color == 1) {
    analogWrite(redLED, 0);
    analogWrite(yellowLED, brightness);
    analogWrite(greenLED, 0);
  }
  else if (color == 2) {
    analogWrite(redLED, brightness);
    analogWrite(yellowLED, 0);
    analogWrite(greenLED, 0);
  }
  else {
    analogWrite(redLED, 0);
    analogWrite(yellowLED, 0);
    analogWrite(greenLED, 0);
  }

  // controls the fading speed
  delay(30);
}
