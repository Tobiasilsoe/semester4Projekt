#include "pitches.h"



void setup() {

  Serial.begin(9600);

}

void loop() {
 // dead();
 //pointUp();
 //genopliv();
 vundet();
  }

  void dead() {
    int noteDurations[] = {
      2.5f, 2, 1
    };

    // notes in the melody:
    int melody[] = {
      NOTE_C7, NOTE_G6, NOTE_C6 
      //Define the melody as being the notes following using those defined in pitches.h
    };
    for (int thisNote = 0; thisNote < 3; thisNote++) {

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

void pointUp() {
    int noteDurations[] = {
      8, 2
    };

    // notes in the melody:
    int melody[] = {
      NOTE_C6, NOTE_G7
      //Define the melody as being the notes following using those defined in pitches.h
    };
    for (int thisNote = 0; thisNote < 3; thisNote++) {

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

void genopliv() {
    int noteDurations[] = {
      2, 4, 8, 1 
    };

    // notes in the melody:
    int melody[] = {
      NOTE_A6, NOTE_B6, NOTE_B6, NOTE_E7 
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

  void vundet() {
    int noteDurations[] = {
      1, 4, 4, 4, 1, 4, 4, 4, 1 
    };

    // notes in the melody:
    int melody[] = {
      NOTE_C6, NOTE_C6, NOTE_G5, NOTE_C6, NOTE_C6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_G6 
      //Define the melody as being the notes following using those defined in pitches.h
    };
    for (int thisNote = 0; thisNote < 9; thisNote++) {

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

  void gul() {
    int noteDurations[] = {
      2, 4, 8, 8
    };

    // notes in the melody:
    int melody[] = {
      NOTE_C7, NOTE_A5,  
      //NOTE_E4, NOTE_E4,NOTE_E4,NOTE_E4
      //NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4
    //  NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7
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
