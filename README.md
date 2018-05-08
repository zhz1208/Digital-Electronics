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



#### Required Parts

1. Arduino UNO board
2. seven 1 KΩ resistors
3. seven 470 Ω resistors
4. seven buttons
5. A speaker
6. A servo motor
7. A breadboard

#### Schematic

![](https://github.com/zhz1208/Digital-Electronics/blob/master/the%20decider.jpg)

#### Code

