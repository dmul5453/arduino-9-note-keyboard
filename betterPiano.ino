/*
   Expanded Music Keyboard to include more notes
   @author Dustin Mullins
   last updated 8/29/2022
*/
#include <Keypad.h>
#include "pitches.h"
const int MAX_NOTES = 9; // max number of notes allowed for recording

// keypad setup
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

//LED setup
int redPin = 52;
int greenPin = 53;
int Rpin = 22;
int Gpin = 24;
int Bpin = 23;
int rvalue;
int gvalue;
int bvalue;

// pitches setup
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_G6, NOTE_A6
}; // 10 different notes - more in pitches .h file
int duration = 500; // duration of notes (500 ms)
int record[MAX_NOTES]; // array used for storing notes in recording
void setup() {
  // put your setup code here, to run once:
  // led output setup
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // gets key press from pad
  char customKey = customKeypad.getKey();

  // keys 1-9 play notes in melody[0:8]
  if (customKey == '1') {
    tone(12, melody[0], duration);
    digitalWrite(Rpin, HIGH);
    delay(duration);
    digitalWrite(Rpin, LOW);
  } else if (customKey == '2') {
    tone(12, melody[1], duration);
    digitalWrite(Rpin, HIGH);
    delay(duration);
    digitalWrite(Rpin, LOW);
  } else if (customKey == '3') {
    tone(12, melody[2], duration);
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, HIGH);
    delay(duration);
    digitalWrite(Gpin, LOW);
    digitalWrite(Rpin, LOW);
  } else if (customKey == '4') {
    tone(12, melody[3], duration);
    digitalWrite(Rpin, HIGH);
    digitalWrite(Gpin, HIGH);
    delay(duration);
    digitalWrite(Gpin, LOW);
    digitalWrite(Rpin, LOW);
  } else if (customKey == '5') {
    tone(12, melody[4], duration);
    digitalWrite(Gpin, HIGH);
    delay(duration);
    digitalWrite(Gpin, LOW);
  } else if (customKey == '6') {
    tone(12, melody[5], duration);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
    delay(duration);
    digitalWrite(Gpin, LOW);
    digitalWrite(Bpin, LOW);
  } else if (customKey == '7') {
    tone(12, melody[6], duration);
    digitalWrite(Bpin, HIGH);
    digitalWrite(Gpin, HIGH);
    delay(duration);
    digitalWrite(Gpin, LOW);
    digitalWrite(Bpin, LOW);
  } else if (customKey == '8') {
    tone(12, melody[7], duration);
    digitalWrite(Bpin, HIGH);
    delay(duration);
    digitalWrite(Bpin, LOW);
  } else if (customKey == '9') {
    tone(12, melody[8], duration);
    digitalWrite(Bpin, HIGH);
    delay(duration);
    digitalWrite(Bpin, LOW);
  }

  if (customKey == 'A') { // Recording button
    int i = 0;
    digitalWrite(redPin, HIGH);
    while (i < MAX_NOTES) { // runs until recording has reached MAX_NOTES number of notes
      customKey = customKeypad.getKey();
      if (customKey == '1') {
        tone(12, melody[0], duration);
        digitalWrite(Rpin, HIGH);
        delay(duration);
        digitalWrite(Rpin, LOW);
        record[i] = 0;
        i++;
      } else if (customKey == '2') {
        tone(12, melody[1], duration);
        digitalWrite(Rpin, HIGH);
        delay(duration);
        digitalWrite(Rpin, LOW);
        record[i] = 1;
        i++;
      } else if (customKey == '3') {
        tone(12, melody[2], duration);
        digitalWrite(Rpin, HIGH);
        digitalWrite(Gpin, HIGH);
        delay(duration);
        digitalWrite(Gpin, LOW);
        digitalWrite(Rpin, LOW);
        record[i] = 2;
        i++;
      } else if (customKey == '4') {
        tone(12, melody[3], duration);
        digitalWrite(Rpin, HIGH);
        digitalWrite(Gpin, HIGH);
        delay(duration);
        digitalWrite(Gpin, LOW);
        digitalWrite(Rpin, LOW);
        record[i] = 3;
        i++;
      } else if (customKey == '5') {
        tone(12, melody[4], duration);
        digitalWrite(Gpin, HIGH);
        delay(duration);
        digitalWrite(Gpin, LOW);
        record[i] = 4;
        i++;
      } else if (customKey == '6') {
        tone(12, melody[5], duration);
        digitalWrite(Bpin, HIGH);
        digitalWrite(Gpin, HIGH);
        delay(duration);
        digitalWrite(Gpin, LOW);
        digitalWrite(Bpin, LOW);
        record[i] = 5;
        i++;
      } else if (customKey == '7') {
        tone(12, melody[6], duration);
        digitalWrite(Bpin, HIGH);
        digitalWrite(Gpin, HIGH);
        delay(duration);
        digitalWrite(Gpin, LOW);
        digitalWrite(Bpin, LOW);
        record[i] = 6;
        i++;
      } else if (customKey == '8') {
        tone(12, melody[7], duration);
        digitalWrite(Bpin, HIGH);
        delay(duration);
        digitalWrite(Bpin, LOW);
        record[i] = 7;
        i++;
      } else if (customKey == '9') {
        tone(12, melody[7], duration);
        digitalWrite(Bpin, HIGH);
        delay(duration);
        digitalWrite(Bpin, LOW);
        record[i] = 8;
        i++;
      }
    }
    digitalWrite(redPin, LOW);
    int note;
    digitalWrite(greenPin, HIGH);
    delay(duration * 2);
    for (int i = 0; i < MAX_NOTES; i++) {
      note = record[i];
      tone(12, melody[note], duration);
      switch (note) {
        case 0:
          digitalWrite(Rpin, HIGH);
          delay(duration);
          digitalWrite(Rpin, LOW);
          break;
        case 1:
          digitalWrite(Rpin, HIGH);
          delay(duration);
          digitalWrite(Rpin, LOW);
          break;
        case 2:
          digitalWrite(Rpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Rpin, LOW);
          break;
        case 3:
          digitalWrite(Rpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Rpin, LOW);
          break;
        case 4:
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          break;
        case 5:
          digitalWrite(Bpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
        case 6:
          digitalWrite(Bpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
        case 7:
          digitalWrite(Bpin, HIGH);
          delay(duration);
          digitalWrite(Bpin, LOW);
          break;
        case 8:
          digitalWrite(Bpin, HIGH);
          delay(duration);
          digitalWrite(Bpin, LOW);
          break;
        default:
          digitalWrite(Rpin, LOW);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
      }
    }
    digitalWrite(greenPin, LOW);
    digitalWrite(Rpin, LOW);
    digitalWrite(Gpin, LOW);
    digitalWrite(Bpin, LOW);
  }

  if (customKey == 'B') {
    int pNote;
    digitalWrite(greenPin, HIGH);
    delay(duration * 2);
    for (int i = 0; i < MAX_NOTES; i++) {

      pNote = record[i];
      tone(12, melody[pNote], duration);
      switch (pNote) {
        case 0:
          digitalWrite(Rpin, HIGH);
          delay(duration);
          digitalWrite(Rpin, LOW);
          break;
        case 1:
          digitalWrite(Rpin, HIGH);
          delay(duration);
          digitalWrite(Rpin, LOW);
          break;
        case 2:
          digitalWrite(Rpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Rpin, LOW);
          break;
        case 3:
          digitalWrite(Rpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Rpin, LOW);
          break;
        case 4:
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          break;
        case 5:
          digitalWrite(Bpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
        case 6:
          digitalWrite(Bpin, HIGH);
          digitalWrite(Gpin, HIGH);
          delay(duration);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
        case 7:
          digitalWrite(Bpin, HIGH);
          delay(duration);
          digitalWrite(Bpin, LOW);
          break;
        case 8:
          digitalWrite(Bpin, HIGH);
          delay(duration);
          digitalWrite(Bpin, LOW);
          break;
        default:
          digitalWrite(Rpin, LOW);
          digitalWrite(Gpin, LOW);
          digitalWrite(Bpin, LOW);
          break;
      }
    }
    digitalWrite(greenPin, LOW);
  }
}
