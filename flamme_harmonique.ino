// Flamme Harmonique - Sound-Reactive LED & Motor System
// This Arduino project controls vibration motors and an RGB LED strip based on sound intensity.
// It uses a sound sensor, a capacitor for signal stability, and colored salts for visual effects.
// Developed as a school demonstration combining electronics, physics, and design principles.

// Required Libraries
#include <Wire.h>                 // For I2C communication
#include <LiquidCrystal_I2C.h>    // For I2C LCD screen
#include <FastLED.h>              // For controlling the RGB LED strip

// Basic RGB Color
int r = 152;
int g = 0;
int b = 10;

// LED Definitions
#define LED_PIN     5
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];             // LED strip array for FastLED

// Vibration Motor Pins
#define MOTOR_PIN_1 9
#define MOTOR_PIN_2 10
#define MOTOR_PIN_3 11

// Sound Variables
int s = 0;            // Current sound value
float l = 2.0;        // Sound amplification factor
int minsound;       // Minimum observed sound
int maxsouhd;       // Maximum observed sound

// Threshold array for LED intensity (not used directly here but can be expanded)
int sinir[] = {1355, 1346, 1336, 1327, 1318, 1308, 1299, 1289, 1285};

// LCD Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  // Pin setup
  pinMode(A0, INPUT);            // Sound sensor input
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PIN_3, OUTPUT);

  // Initialize min/max tracking
  minsound = 1024; 
  maxsouhd = 0;

  // LCD Setup
  lcd.init();      
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("Sound Project");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000); 
  lcd.clear(); 

  // LED Setup
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(80); 

  // Initial LED Animation (symmetric lighting)
  for (int i = NUM_LEDS / 2; i >= 0; i--) {
    if (i < NUM_LEDS) { leds[i] = CRGB(r, g, b); }
    if ((NUM_LEDS - 1 - i) >= 0 && (NUM_LEDS - 1 - i) < NUM_LEDS) {
        leds[NUM_LEDS - 1 - i] = CRGB(r, g, b);
    }
    FastLED.show();
    delay(40);
  }

  delay(50);
  Serial.println("Setup complete.");
}

void loop() {
  // Read and scale sound input
  s = analogRead(A0);
  s = (int)(s * l);

  // Track min/max sound values
  if (s < minsound) { minsound = s; }
  if (s > maxsouhd) { maxsouhd = s; }

  // Display values on LCD
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("S:"); lcd.print(s); 
  
  lcd.setCursor(0, 1); 
  lcd.print("Mn:"); lcd.print(minsound);
  lcd.setCursor(8, 1); 
  lcd.print("Mx:"); lcd.print(maxsouhd);

  // Motor control based on sound
  int min_s = 1280;  // Minimum sound value to activate motors
  int max_s = 1355;  // Maximum sound value for full vibration
  int enginespeed = map(s, min_s, max_s, 70, 255);  // Map sound to PWM

  // Apply motor vibration
  analogWrite(MOTOR_PIN_1, motorHizi);
  analogWrite(MOTOR_PIN_2, motorHizi);
  analogWrite(MOTOR_PIN_3, motorHizi);
}
