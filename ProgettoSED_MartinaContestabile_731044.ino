/**
 * Progetto di Sistemi di Elettronica Digitale — A.A. 2022-23
 * Martina Contestabile
 * Matricola 731044
 */


#include <ESP32Servo.h>  // fondamentale per poter usare la funzione tone()

/*
 * Frequenza delle note, notazione Anglosassone.
 */
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978


/*
 * Tempi delle note musicali e pause, servono per dare il corretto ritmo ai brani.
 */
#define PAUSE 0
#define FOUR 4
#define TWO 2
#define THIRTEEN_EIGHTHS 13/8
#define ONE 1                                                     
#define THREE_EIGHT 8/3
#define SEVEN_QUARTER 7/4
#define HALF 2
#define A_QUARTER 4
#define SEVEN_EIGHTHS 8/7
#define ONE 1
#define THREE_HALF 3/2


/*
 * Setup dei pin assegnati sull'Arduino.
 * I bottoni sono pull-down, cioè sono settati a low.
 */
int buzzer = 23;
int buttonFr = 15;
int bFr = 5;
int wFr = 19;
int rFr = 21;

int buttonAg = 12;
int bAg = 27;
int wAg = 26;


/*
 * Array che rappresenta l'insieme delle note dell'inno francese.
 */
int marseillaise[] = {
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4,
  NOTE_D5, NOTE_B4, NOTE_G4, NOTE_G4, NOTE_B4, NOTE_G4,
  NOTE_E4, NOTE_C5, NOTE_A4, NOTE_FS4,
  NOTE_G4, PAUSE, NOTE_G4, NOTE_A4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4,
  NOTE_B4, NOTE_A4, PAUSE, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5,
  NOTE_B4, PAUSE, NOTE_D5, NOTE_D5,
  NOTE_D5, NOTE_B4, NOTE_G4, NOTE_D5, NOTE_B4, NOTE_G4,
  NOTE_D4,
  PAUSE
};

/*
 * Durata di ciascuna nota dell'inno francese.
 */
int durationsFrance[] = {
  FOUR, THIRTEEN_EIGHTHS, FOUR,
  ONE, ONE, ONE, ONE,
  THIRTEEN_EIGHTHS, TWO, THIRTEEN_EIGHTHS, FOUR, THIRTEEN_EIGHTHS, FOUR,
  ONE, TWO, THIRTEEN_EIGHTHS, FOUR,
  TWO, ONE, THIRTEEN_EIGHTHS, FOUR,
  ONE, ONE, ONE, THIRTEEN_EIGHTHS, FOUR,
  ONE, ONE, ONE, THIRTEEN_EIGHTHS, FOUR,
  ONE, ONE, ONE, THIRTEEN_EIGHTHS, FOUR,
  TWO, ONE, THIRTEEN_EIGHTHS, FOUR,
  ONE, THIRTEEN_EIGHTHS, FOUR, ONE, THIRTEEN_EIGHTHS, FOUR,
  TWO,
  THREE_EIGHT
};

/*
 * Array che rappresenta l'insieme delle note dell'inno argentino.
 */
int argentinaAnthem[] = {
  NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_F5, NOTE_DS5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_C4, NOTE_AS4, PAUSE, PAUSE, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_AS4, NOTE_AS4, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_AS3, NOTE_D4, NOTE_F4, NOTE_DS4, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_AS3, NOTE_C4, NOTE_D4,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_AS4, NOTE_CS4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4
};

/*
 * Durata di ciascuna nota dell'inno argentino.
 */
int durationsArgentina[] = {
  TWO, SEVEN_QUARTER, A_QUARTER, SEVEN_QUARTER, A_QUARTER, ONE, ONE, ONE, ONE, THREE_HALF, A_QUARTER, A_QUARTER, TWO, TWO, TWO, HALF, HALF, ONE, ONE,
  ONE, THREE_HALF, HALF, ONE, ONE, THREE_HALF, HALF, HALF, HALF, ONE, THREE_HALF, HALF, ONE, THREE_HALF, HALF, ONE, THREE_HALF, HALF, TWO, HALF, THREE_HALF, HALF,
  ONE, THREE_HALF, HALF, ONE, ONE, ONE, ONE, ONE, ONE, ONE, THREE_HALF, HALF, ONE, THREE_HALF, HALF, ONE, THREE_HALF, HALF, TWO, HALF, ONE, ONE
};

void setup() {
  // Imposto il buzzer come output, in quanto è deve solo riprodurre un suono, non si compiono azioni sul buzzer.
   pinMode(buzzer, OUTPUT);

   // Componenti associate alla Francia.
   pinMode(buttonFr, INPUT);
   pinMode(bFr, OUTPUT);
   pinMode(wFr, OUTPUT);
   pinMode(rFr, OUTPUT);

   // Componenti associate all'Argentina.
   pinMode(buttonAg, INPUT);
   pinMode(bAg, OUTPUT);
   pinMode(wAg, OUTPUT);
}


void loop() {
  /*
   * Bisogna controllare i bottoni: se non si fa nulla su di loro, allora il programma non fa
   * nulla, resta in attesa. Invece, se si preme uno dei bottoni, si fa partire il rispettivo
   * inno. Una volta premuto il bottone, questo fa partire l'inno e torna LOW, in attesa di
   * future azioni su di esso.
   */
   int buttonFrState = digitalRead(buttonFr);
   if (buttonFrState == HIGH) {
     franceAnthem();
   }

   int buttonAgState = digitalRead(buttonAg);
   if (buttonAgState == HIGH) {
     agentinaAnthem();
   }
}


/*
 * Metodo che si occupa di gestire l'inno francese.
 */
void franceAnthem() {
  for (int thisNote = 0; thisNote < 45; thisNote++) {
     int note = marseillaise[thisNote];
     int noteDuration = 500 / durationsFrance[thisNote];
     int pauseBetweenNotes = noteDuration * 1.00;
     ledshowFr(note);

     if (note == 0) {
      while (noteDuration--) {
        delayMicroseconds(50); 
      }
      continue;
    } else {
      tone(buzzer, marseillaise[thisNote], noteDuration);
      delay(pauseBetweenNotes);
      noTone(buzzer); 
    }
  }

  // Terminato il brano, devo spegnere i led.
  digitalWrite(bFr, LOW);
  digitalWrite(wFr, LOW);
  digitalWrite(rFr, LOW);
}


/*
 * Metodo che si occupa di gestire i led dell'inno francese.
 */
void ledshowFr(int currentNote) {
  switch (currentNote) {
      case NOTE_D4:
        digitalWrite(bFr, HIGH);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, HIGH);
        break;
      case NOTE_G4:
        digitalWrite(bFr, HIGH);
        digitalWrite(wFr, LOW);
        digitalWrite(rFr, HIGH);
        break;
      case NOTE_A4:
        digitalWrite(bFr, LOW);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, LOW);
        break;
      case NOTE_D5:
        digitalWrite(bFr, HIGH);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, LOW);
        break;
      case NOTE_B4:
        digitalWrite(bFr, LOW);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, HIGH);
        break;
      case NOTE_E4:
        digitalWrite(bFr, LOW);
        digitalWrite(wFr, LOW);
        digitalWrite(rFr, LOW);
        break;
      case NOTE_C5:
        digitalWrite(bFr, HIGH);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, HIGH);
        break;
      case NOTE_FS4:
        digitalWrite(bFr, LOW);
        digitalWrite(wFr, HIGH);
        digitalWrite(rFr, LOW);
        break;
      case PAUSE:
        digitalWrite(bFr, HIGH);
        digitalWrite(wFr, LOW);
        digitalWrite(rFr, HIGH);
        break;
      default:
        break;
    }
}


/*
 * Metodo che si occupa di gestire l'inno argentino.
 */
void agentinaAnthem() {
  for (int thisNote = 0; thisNote < 62; thisNote++) {
     int note = argentinaAnthem[thisNote];
     int noteDuration = 500 / durationsArgentina[thisNote];
     int pauseBetweenNotes = noteDuration * 1.00;
     ledshowAg(note);

     if (note == 0) {
      while (noteDuration--) {
        delayMicroseconds(5); 
      }
      continue;
    } else {
      tone(buzzer, argentinaAnthem[thisNote], noteDuration);
      delay(pauseBetweenNotes);
      noTone(buzzer); 
    }
  }

  // Terminato il brano, devo spegnere i led.
  digitalWrite(bAg, LOW);
  digitalWrite(wAg, LOW);
}


/*
 * Metodo che si occupa di gestire i led dell'inno argentino.
 */
void ledshowAg(int currentNote) {
  switch (currentNote) {
      case NOTE_A4:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, HIGH);
        break;
      case NOTE_C5:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_D5:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_B4:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, HIGH);
        break;
      case NOTE_G4:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, HIGH);
        break;
      case NOTE_E4:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, HIGH);
        break;
      case NOTE_F4:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_C4:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, HIGH);
        break;
      case PAUSE:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_A3:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, HIGH);
        break;
      case NOTE_D4:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_CS4:
        digitalWrite(bAg, LOW);
        digitalWrite(wAg, LOW);
        break;
      case NOTE_B3:
        digitalWrite(bAg, HIGH);
        digitalWrite(wAg, HIGH);
        break;
      default:
        break;
    }
}