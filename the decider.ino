
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

