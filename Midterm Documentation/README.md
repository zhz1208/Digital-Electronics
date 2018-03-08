# Documentation of The Midterm Project
CCA 2018 Spring - Huizhong Zhu

### Concept

The capacitive-touch Arduino piano has letters displayed on each keyboard. One person plays the piano based on the spelling of another person’s name. Therefore, they will hear a unique melody based on the name. 

### Code

```C++
#include <CapacitiveSensor.h>
#include "pitches.h"

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define BUZZER_PIN      A4   // The output pin for the piezo buzzer
#define NUM_OF_SAMPLES  10   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   80  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS     7    // Number of keys that are on the keyboard

// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)

// Each key corresponds to a note, which are defined here. Uncomment the scale that you want to use:
int notes[]={NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5}; // C-Major scale

//int notes[]={NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5}; // A-Minor scale
//int notes[]={NOTE_C4,NOTE_DS4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_AS4,NOTE_C5,NOTE_DS5}; // C Blues scale

// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9)};

void setup() { 
    // Turn off autocalibrate on all channels:
    for(int i=0; i<8; ++i) {
        keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
    }
    // Set the buzzer as an output:
    pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {
    unsigned int keysPlaying = 0;
    // Loop through each key:
    for (int i = 0; i < NUM_OF_KEYS; ++i) {
        // If the capacitance reading is greater than the threshold, play a note:
        int c = keys[i].capacitiveSensor(NUM_OF_SAMPLES);
        if(c > CAP_THRESHOLD) {
            tone(BUZZER_PIN, notes[i]); // Plays the note corresponding to the key pressed
            keysPlaying++;
        }
    }

    if (keysPlaying == 0) {
        noTone(BUZZER_PIN);
    }
}
```

### Schematic
![](https://github.com/zhz1208/Digital-Electronics/blob/master/Midterm%20Documentation/circuit.jpg)

### Concept Proposal for The Final Project

This device is designed for two people. A plays the role of performer and B plays the role of audience.
First, A asks for B’s name. 
Then A plays a melody based on B’s name. Meanwhile, B writes down a wish for A on the wish card and paste it on the hand.
Finally, the speaker will replay the unique melody. As soon as it finishes, the hand lifts up with the wish card which can be seen by A.

### Challenges

Currently, my biggest challenge is combining all parts (the piano and the hand) together. I can figure out each part separately. But, I have no idea about combining them into one on both circuit sketching or coding.


