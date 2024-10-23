#include <Adafruit_NeoPixel.h>

// Define pins for inputs and outputs
#define LeftSig 2  // PWM input from receiver for left motor
#define RightSig 3 // PWM input from receiver for right motor
#define LeftMotor 9  // PWM output to ESC for left motor
#define RightMotor 10 // PWM output to ESC for right motor
#define NeopixelSig 11 // Neopixel signal pin

// Setup Neopixel (1 LED at pin NeopixelSig)
Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(1, NeopixelSig, NEO_GRB + NEO_KHZ800);

void setup() {
  // Set input pins for receiver signals
  pinMode(LeftSig, INPUT);
  pinMode(RightSig, INPUT);
  
  // Set output pins for motors
  pinMode(LeftMotor, OUTPUT);
  pinMode(RightMotor, OUTPUT);
  
  // Initialize Neopixel
  neopixel.begin();
  neopixel.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Example: Read PWM signals from receiver
  int leftInput = pulseIn(LeftSig, HIGH);
  int rightInput = pulseIn(RightSig, HIGH);
  
  // Map input signals to ESC-compatible PWM output
  int leftMotorOutput = map(leftInput, 1000, 2000, 0, 255); // Adjust ranges as needed
  int rightMotorOutput = map(rightInput, 1000, 2000, 0, 255);

  // Send PWM signal to motors
  analogWrite(LeftMotor, leftMotorOutput);
  analogWrite(RightMotor, rightMotorOutput);
  
  // Example of controlling the Neopixel (set to red color)
  neopixel.setPixelColor(0, neopixel.Color(255, 0, 0));  // Red color
  neopixel.show();
}
