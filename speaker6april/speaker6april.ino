#include "pitches.h"

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(48, 6, NEO_GRB + NEO_KHZ800);

uint32_t purple = strip.Color(128, 0, 128);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t green = strip.Color(0, 128, 0);
uint32_t red = strip.Color(255, 0, 0);

int fsrAnalogPin = A0;
int fsrReading;
int farve = 1;
bool mag = false;
bool knap1 = false;
bool knap2 = false;
bool knap3 = false;
bool boolTimer =true;
int buttonPin = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int points = 0;
unsigned long startTime;
unsigned long tid;
const int hallPin = 5;



int buttonState = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int hallState = 0;



/*NOTE_E4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_G4, NOTE_D4,   0,     NOTE_E4,
  NOTE_G4, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_D4,    0,    NOTE_E4, NOTE_G4,
  NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4,
  NOTE_D4,    0,    NOTE_E4, NOTE_G4, NOTE_D5,
  NOTE_C5, NOTE_G4*/

/*2,4,2,8,8,                                                          //                                                 2 = 4 beats (whole note)
  2,4,2,4,2,                                                          //                                                 4 = 2 beats (half note)
  4,2,4,2,8,                                                          //                                                 8 = 1 beats (quarter note)
  8,2,4,2,4,
  2,8,8,2,4,
  2,4,2,4,2,
  4,1 */
/*int noteDurations[] = {
                                               //Define the note durations, 1 to 1 with melody    1 = 8 beats
  };*/



void setup() {

  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(hallPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  digitalWrite(buttonPin2, HIGH);
  digitalWrite(buttonPin3, HIGH);


  strip.begin();
  strip.show();
}

void loop() {
  delay(100);


  while (digitalRead(buttonPin) == LOW)     // If button 1 pressed
  {
    knap1 = true;
    knap2 = false;
    knap3 = false;
    Serial.println("Button 1 pressed"); // Print "Button 1 pressed" on Serial Monitor
  }
  while (digitalRead(buttonPin2) == LOW)     // If button 2 pressed
  {
    knap1 = false;
    knap2 = true;
    knap3 = false;
    points = 0;                           // reset point i legen
    mag = false;                          // reset levende
    Serial.println("Button 2 pressed"); // Print "Button 2 pressed" on Serial Monitor
  }
  while (digitalRead(buttonPin3) == LOW)     // If button 3 pressed
  {
    knap1 = false;
    knap2 = false;
    knap3 = true;
    Serial.println("Button 3 pressed"); // Print "Button 3 pressed" on Serial Monitor
  }
  while (knap1 == true) {
    //Serial.println("leg1 kaldt");
    leg1();
    if (digitalRead(buttonPin2) == LOW) {
      knap1 = false;
      knap2 = true;
    }
    if (digitalRead(buttonPin3) == LOW) {
      knap1 = false;
      knap3 = true;
    }


  }
  while (knap2 == true) {
    leg2();
    //  Serial.println("leg2 kaldt");
    if (digitalRead(buttonPin) == LOW) {
      knap2 = false;
      knap1 = true;
    }
    if (digitalRead(buttonPin3) == LOW) {
      knap2 = false;
      knap3 = true;
    }
  }
  while (knap3 == true) {
    //leg3();
    //  Serial.println("leg3 kaldt");
    if (digitalRead(buttonPin) == LOW) {
      knap3 = false;
      knap1 = true;
    }
    if (digitalRead(buttonPin2) == LOW) {
      knap3 = false;
      knap2 = true;
    }

  }
}




void gul() {
  int noteDurations[] = {
    2, 4, 8, 8
  };

  // notes in the melody:
  int melody[] = {
    //NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4
    //NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4
    NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7
    //NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6
    //NOTE_C8, NOTE_C8, NOTE_C8,NOTE_C8
    //Define the melody as being the notes following using those defined in pitches.h
  };
  for (int thisNote = 0; thisNote < 4; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }


}

void lilla() {
  int noteDurations[] = {
    2, 4, 8, 8
  };

  // notes in the melody:
  int melody[] = {
    //NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4
    //NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4
    //NOTE_C7,NOTE_C7,NOTE_C7,NOTE_C7
    //NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6
    NOTE_C8, NOTE_C8, NOTE_C8, NOTE_C8
    //Define the melody as being the notes following using those defined in pitches.h
  };
  //melody[thisNote]!=-1
  for (int thisNote = 0; thisNote < 4 ; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }


}
void blaa() {
  int noteDurations[] = {
    2, 4, 8, 8
  };

  // notes in the melody:
  int melody[] = {
    //NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4
    //NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4
    //NOTE_C7,NOTE_C7,NOTE_C7,NOTE_C7
    NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6
    //NOTE_C8, NOTE_C8, NOTE_C8,NOTE_C8
    //Define the melody as being the notes following using those defined in pitches.h
  };
  //melody[thisNote]!=-1
  for (int thisNote = 0; thisNote < 4 ; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }


}

void leg1() {
  // no need to repeat the melody.
  fsrReading = analogRead(fsrAnalogPin);
  Serial.println("Tryk = ");
  Serial.print(fsrReading);

  if (fsrReading > 400)
  {


    if (farve == 1) {
      strip.fill(purple);
      strip.show();
      lilla();
    }
    else if (farve == 2) {
      strip.fill(yellow);
      strip.show();
      gul();
    }
    /*   else if (farve == 3){


        strip.fill(blue);
        strip.show();
        blaa();
       }
    */

    delay(5000);
    if (farve >= 2) {
      farve = 0;
    }

    farve++;
  }
  if (hallState == HIGH) {
    strip.fill(blue);
    strip.show();
    Serial.println("blaa");
  }
}
void leg2() {

  // no need to repeat the melody.
  fsrReading = analogRead(fsrAnalogPin);
  // Serial.println("Tryk = ");
  Serial.print(fsrReading);
  delay(500);
  strip.fill(blue, 0, points);              // stift alle led'er pånær 1 point til grøn
  strip.fill(green, 1, 48);
  strip.show();
  hallState = digitalRead(hallPin);

  if (fsrReading > 200)
  {
    if (mag == false) {
      strip.fill(red);
      strip.show();
      Serial.print("dead");
      mag = true;
    }
  }
  if (hallState == HIGH && mag == true) {
    strip.fill(blue, 0, points);        // stift alle led'er pånær sine point til grøn
    strip.fill(green, points + 1, 48);  // blå er point farve
    strip.show();
    gul();                              // genopliv musik
    Serial.println("alive");
    mag = false;
  }
  else if (hallState == HIGH && mag == false) {
    points ++;
    strip.fill(blue, 0, points);        // skift en led til blå
    strip.fill(green, points + 1, 48);
    strip.show();
    Serial.println("pointUp");
  }
}

void leg3()
{
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print(fsrReading);
  if (boolTimer== true)'
    {
    startTime = (millis()/1000);
  boolTimer= false;
    }
  
  }
