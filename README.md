# Digital-Electronics
CCA 2018 Spring - Huizhong Zhu

## Homework for Week 2

### An Interesting Arduino Project

Project Name: Issey Miyake Bao Bao Bag Concept

Author: Kimbab

Links:

1. [https://www.hackster.io/kimbab-studio/issey-miyake-bao-bao-bag-concept-by-kimbab-d84eaf](https://www.hackster.io/kimbab-studio/issey-miyake-bao-bao-bag-concept-by-kimbab-d84eaf)
1. [https://kimbab.me/portfolio/issey-miyake-baobao-bag-conceptual-by-kimbab/](https://kimbab.me/portfolio/issey-miyake-baobao-bag-conceptual-by-kimbab/)

Publish Date: December 19, 2017

I find this wearable Arduino-driven electronic fashion bag extremely interesting. The idea of the project is inspired by the design of [Bao Bao bag](https://www.isseymiyake.com/en/brands/baobao) by a Japanese fashion designer Issey Miyake, who is famous for his technology-driven clothing designs. The original Bao Bao bag is flashy with its material, shape and pattern. Kimbab uses colorful LEDs in triangle shapes to make the surface of the newly remodeled smart Bao Bao bag. Controlled by an Arduino UNO, the surface can show customized patterns and animations. In his [demo video](https://youtu.be/EZ4qKqp91Pk), the light effect of the bag is glorious. It will definitely be an eye-catcher when walking on the street with it.

### 3 Sensors

[PIR Motion Sensors](https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/) are inexpensive solutions for detecting human-beings or animals moving around a certain area. They can be used by the machines to interact with humans. Once a human gets into a certain area, the machine can give corrsponding responses. It's a location-based response. For example, an automatica door will be opened when it detects someone arrives. The PIR sensors may be hacked for more advanced usage, for example, detecting the distance between the sensor and the target.

[Photocells](https://learn.adafruit.com/photocells) are cheap and inaccurate. They can tell the qualitative lightness or darkness, but cannot read the accruate quantitative values. The variations among different photocells are usually large (more than 50%), so when using multiple photocells, we need to be aware that their readings may be quite different. Also, they may interfere with each other to cause inconsistent results. Photocells can be used by projects which needs to respond to environmental light changes.

[Temperature Sensors](https://learn.adafruit.com/tmp36-temperature-sensor) are a little bit more expensive than photocells but still much cheaper than PIR sensors. It can read temperatures to 0.1 degree precision, ranging from -40 to 150, which already covers the most common temperature range. Unlike thermocouples, these semiconductor sensors only work on a relatively narrower temperature range, but it's enough for measuring ambient air temperature. They can be used to show the current temperature or set an alert when the temperature goes crazy.


## Homework for Week 3

### Mandarin Piano

#### Sketching
![](https://github.com/zhz1208/Digital-Electronics/blob/master/PNG%20image-321ADD91BD44-1.png)

#### Description

The Mandarin Piano is a keyboard instrument. Each mandarin is a key to play. The led bulb on the mandarin will light up when touching the mandarin. Thus the player can see the visual music he/she is playing in dark.

#### Required Parts/Materials

1. Arduino UNO board
2. 5 mandarins
3. 5 resistors (?Ω)
4. Jumper wires
5. A piezo buzzer
6. A breadboard

## Final Project

### The Boring Decider

#### Description

#### Sketching

#### Required Parts

#### Schematic

#### Code

`
#include <Servo.h>

#define speaker 13
#define record_button 7
#define play_button 6
#define record_led 5
#define play_led 3

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

int maxNumber = 800;
int time = 10;

int randNumber;
int check = 0;

int buttons[] = {8, 9, 10, 11, 12};
unsigned int sounds[] = {262, 294, 330, 392, 440, 0};
int saveSounds[800];
int saveNumber = 0;

void Random()
{
  randNumber = random(5);
}


void freePlay()
{
  if (digitalRead(buttons[0]) == HIGH)
  {
    tone(speaker, sounds[0]);
    delay(time);
  }

  else if (digitalRead(buttons[1]) == HIGH)
  {
    tone(speaker, sounds[1]);
    delay(time);
  }

  else if (digitalRead(buttons[2]) == HIGH)
  {
    tone(speaker, sounds[2]);
    delay(time);
  }

  else if (digitalRead(buttons[3]) == HIGH)
  {
    tone(speaker, sounds[3]);
    delay(time);
  }

  else if (digitalRead(buttons[4]) == HIGH)
  {
    tone(speaker, sounds[4]);
    delay(time);
  }
  else
  {
    noTone(speaker);
    delay(time);
  }
}

void setup()
{
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
  for (int i = 0; i < 5; i++)
  {
    pinMode(buttons[i], INPUT);
  }

  pinMode(record_button, INPUT);
  pinMode(play_button, INPUT);

  pinMode(speaker, OUTPUT);
  pinMode(record_led, OUTPUT);
  pinMode(play_led, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  freePlay();

  if (digitalRead(record_button) == HIGH)
  {
    Serial.println("on");
    digitalWrite(record_led, HIGH);

    for (int i = 0; i < maxNumber; i++)
    {
      if (digitalRead(buttons[0]) == HIGH)
      {
        tone(speaker, sounds[0]);
        delay(time);

        saveSounds[saveNumber] = 0;
        saveNumber++;
      }

      else if (digitalRead(buttons[1]) == HIGH)
      {
        tone(speaker, sounds[1]);
        delay(time);

        saveSounds[saveNumber] = 1;
        saveNumber++;
      }

      else if (digitalRead(buttons[2]) == HIGH)
      {
        tone(speaker, sounds[2]);
        delay(time);

        saveSounds[saveNumber] = 2;
        saveNumber++;
      }

      else if (digitalRead(buttons[3]) == HIGH)
      {
        tone(speaker, sounds[3]);
        delay(time);

        saveSounds[saveNumber] = 3;
        saveNumber++;
      }

      else if (digitalRead(buttons[4]) == HIGH)
      {
        tone(speaker, sounds[4]);
        delay(time);

        saveSounds[saveNumber] = 4;
        saveNumber++;
      }
      else
      {
        noTone(speaker);
        delay(time);
        saveSounds[saveNumber] = 5;
        saveNumber++;
      }
    }
    digitalWrite(record_led, LOW);
    //    digitalWrite(record_button, LOW);
    tone(speaker, 700);
    delay(400);
    noTone(speaker);
    check++;
  } else {
    Serial.println("off");
  }

  if (check >= 1)
  {
    //while (0 == 0)
    {
      freePlay();

      if (digitalRead(play_button) == HIGH)
      {
        digitalWrite(play_led, HIGH);

        int maxN;
        for (maxN = maxNumber - 1; maxN >= 0; maxN--) {
          if (sounds[saveSounds[maxN]] != 0)
            break;
        }

        for (int i = 0; i < maxN; i++) {
          // Servo
          pos = (pos + 1) % 360;
          myservo.write(180 - abs(pos - 180));

          if (sounds[saveSounds[i]] != 0)
          {
            tone(speaker, sounds[saveSounds[i]]);
            delay(8);
          }
          else
          {
            noTone(speaker);
            delay(8);
          }

        }
        noTone(speaker);
        digitalWrite(play_led, LOW);
        //        digitalWrite(play_button, LOW);
        freePlay();
      }
    }
  }
}

`




