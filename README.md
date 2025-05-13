# flamme-harmonique
An Arduino-based system where vibration motors and LEDs react to sound intensity in real-time.
# Flamme Harmonique

This project is an Arduino-based sound-reactive system that combines vibration motors and RGB LEDs to simulate a visual flame effect. The system reacts to sound intensity and demonstrates how physical components can respond dynamically to audio input.

## Project Overview

The setup converts sound intensity into both light and movement:
- Vibration motors simulate flame motion.
- RGB LEDs produce colored light in response to the audio signal.
- The goal is to visualize the energy of sound waves.

## Components Used

- Arduino UNO
- Sound sensor module
- 3 vibration motors
- 6-segment RGB LED strip
- Capacitor (used to separate positive and negative signals)
- Female-to-male jumper wires
- 3 transparent containers
- Colored salts for visual effect:
  - Copper(II) sulfate (blue)
  - Potassium chlorate (violet)
  - Sodium chloride (orange)

## Circuit Connections

| Component            | Arduino Pin |
|---------------------|-------------|
| Sound sensor (OUT)  | A0          |
| Motor 1             | D3          |
| Motor 2             | D5          |
| Motor 3             | D6          |
| RGB LED strip       | D9          |
| GND                 | GND         |
| VCC                 | 5V          |

## How It Works

1. The sound sensor detects ambient sound intensity.
2. The Arduino reads this analog signal and processes it.
3. As the sound gets louder, the motors vibrate more strongly and more LEDs light up.
4. The capacitor ensures stable signal input by isolating noise and voltage spikes.
5. Colored salts in containers create a flame-like appearance when light passes through them.

## Video

Watch a short demonstration here:  
https://youtu.be/7GKQaMt67wk

## Notes

- The project was developed as part of a school demonstration.
- Electrical connections were completed by students with basic guidance.
- The aim was both educational and visual, combining physics, electronics, and art.
