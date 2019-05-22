#include "pitches.h"

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(42, 6, NEO_GRB + NEO_KHZ800);



uint32_t blue = strip.Color(0, 0, 255);
uint32_t green = strip.Color(0, 128, 0);
uint32_t red = strip.Color(255, 0, 0);

int fsrAnalogPin = A0;
int fsrReading;
int farve = 1;
bool mag = false;
bool dead = false;
bool knap1 = false;
bool knap2 = false;
bool knap3 = false;
bool boolTimer =true;
bool startLeg = true;
bool startup = true;
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
int hallState = 1;



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

  if(startup == true){
    StartupFunction();
    startup = false;
  }

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
    leg3();
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


  void deadSound() {
    int noteDurations[] = {
      2.5f, 2, 1
    };

    
    int melody[] = {
      NOTE_C7, NOTE_G6, NOTE_C6 
      
    };
    for (int thisNote = 0; thisNote < 3; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }


  }

void pointUp() {
    int noteDurations[] = {
      8, 2
    };

    int melody[] = {
      NOTE_C6, NOTE_G7
    };
    for (int thisNote = 0; thisNote < 3; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }


  }

void genopliv() {
    int noteDurations[] = {
      2, 4, 8, 1 
    };

    int melody[] = {
      NOTE_A6, NOTE_B6, NOTE_B6, NOTE_E7 
    };
    for (int thisNote = 0; thisNote < 4; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }


  }

  void vundet() {
    int noteDurations[] = {
      1, 4, 4, 4, 1, 4, 4, 4, 1 
    };

    int melody[] = {
      NOTE_C6, NOTE_C6, NOTE_G5, NOTE_C6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_G6 
    };
    for (int thisNote = 0; thisNote < 9; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }


  }


void ramtSound2() {
  int noteDurations[] = {
    2, 4, 8, 8
  };
  int melody[] = {
    NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7
  };
  for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }


}

void ramtSound1() {
  int noteDurations[] = {
    2, 4, 8, 8
  };


  int melody[] = {
    NOTE_C8, NOTE_C8, NOTE_C8, NOTE_C8
  };
  for (int thisNote = 0; thisNote < 4 ; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }


}


void magnetSound() {
  int noteDurations[] = {
    2, 4, 8, 8
  };


  int melody[] = {
    NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6
  };
  for (int thisNote = 0; thisNote < 4 ; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }


}

void StartupFunction() {
  
  int noteDurations[] = {
    4, 4, 4, 4, 4, 4, 1
  };
  int melody[] = {
    NOTE_C6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_G6
  };
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
  
  for(int i = 0; i <= 42; i++)
  {
    strip.setPixelColor(i, green);
    strip.show();
    delay(50);
  }
}

void leg1() {
  delay(100);
  fsrReading = analogRead(fsrAnalogPin);
  hallState = digitalRead(hallPin);
  Serial.println(hallState);
  Serial.println(fsrReading);

  if (fsrReading > 420)
  {
   hallState = 1;


    if (farve == 1) {
      strip.fill(red);
      strip.show();
      ramtSound1();
    }
    else if (farve == 2) {
      strip.fill(green);
      strip.show();
      ramtSound2();
      strip.fill(green);
      strip.show();
    }

    delay(2000);
    if (farve >= 2) {
      farve = 0;
    }

    farve++;
  }
  if (hallState == LOW) {
    strip.fill(blue);
    strip.show();
    magnetSound();
    strip.fill(blue);
    strip.show();
    
  }
}


void leg2() {

strip.fill(green);  // man bliver genoplivet med 0 pionts 
strip.show();
while (knap2 == true){
   fsrReading = analogRead(fsrAnalogPin);
  // Serial.println("Tryk = ");
  Serial.print(fsrReading);
  delay(100);
  hallState = digitalRead(hallPin);
  if (fsrReading > 420 && mag == false)
  {
     strip.fill(red);
     strip.show();
     Serial.print("dead");
     deadSound();
     mag = true;
  }
  if (hallState == LOW && mag == true) {
    
    strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    genopliv();
    strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    mag = false;
   
    }
  else if (hallState == LOW && mag == false) {
    
    points ++;
     strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    pointUp(); 
    strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    
    Serial.println("pointUp");
  }
  if (digitalRead(buttonPin) == LOW) {
      knap2 = false;
      knap1 = true;
    }
  if (digitalRead(buttonPin3) == LOW) {
      knap2 = false;
      knap3 = true;
    }
}
}
void leg3()
{
  
 if (startLeg==true){
  strip.fill(green,0, 6);
  strip.fill(blue, 6, points);
  strip.fill(green, points + 6, 42);
  strip.show();
  strip.fill(green,0, 6);
  strip.fill(blue, 6, points);
  strip.fill(green, points + 6, 42);
  strip.show();
  startLeg = false;
 
  }
  
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print(fsrReading);
  
 
  hallState = digitalRead(hallPin);
  
    
  
 // nedstående er for hvis en bliver ramt
  if (fsrReading > 420 && dead == false)
  {
      deadSound();
      strip.fill(red);
      strip.show();
      Serial.print("dead");
      dead = true;
    
  }
  
  if (hallState == LOW && dead == true) // resetter vesten
  {
    strip.fill(green, 0, 42);
    strip.show();
    genopliv();                             // genopliv musik
    strip.fill(green, 0, 42);
    strip.show();
    dead = false;
    points=0;
    
  } else if (hallState == LOW && dead == false) {
    points++;
    strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    pointUp(); 
    strip.fill(green,0, 6);
    strip.fill(blue, 6, points);        // skift en led til blå
    strip.fill(green, points + 6, 42);
    strip.show();
    Serial.println("pointUp");
  }
  
  }
