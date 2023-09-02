#include "pitches.h"
#define ACTIVATED LOW


const int PIEZO = 11;
const int LED = 13;

int buttonSong = 8;
const int BUTTON_G7 = 7;
const int BUTTON_C7 = 3;
const int BUTTON_E7 = 2;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_G7, INPUT);
  digitalWrite(BUTTON_G7,HIGH);
  pinMode(BUTTON_C7, INPUT);
  digitalWrite(BUTTON_C7,HIGH);
  pinMode(BUTTON_E7, INPUT);
  digitalWrite(BUTTON_E7,HIGH);
  pinMode (buttonSong, INPUT);
  digitalWrite(buttonSong, HIGH);
  
  digitalWrite(LED,LOW);
}

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

void loop() {
  while(digitalRead(BUTTON_G7) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G7);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(BUTTON_C7) == ACTIVATED)
  {
    tone(PIEZO,NOTE_C7);
    digitalWrite(LED,HIGH);
  }
  
  while(digitalRead(BUTTON_E7) == ACTIVATED)
  {
    tone(PIEZO,NOTE_E7);
    digitalWrite(LED,HIGH);
  }
  
  if(digitalRead(buttonSong) == ACTIVATED) {
    int size =sizeof(melody) / sizeof(int);
    for (int thisNote=0; thisNote <size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];
      tone(11, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(11);
    }
    
  }

  noTone(PIEZO);
  digitalWrite(LED,LOW);

}
