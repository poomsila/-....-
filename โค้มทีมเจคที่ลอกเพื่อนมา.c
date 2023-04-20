#include <LedControl.h>

#define DIN 11
#define CLK 13
#define CS 10
#define BTN_1 2
#define BTN_2 3
#define LEDR 4
#define LEDG 5
#define LEDY 6


volatile int present1 = 0;
volatile int present2 = 0;
const int debounce = 50;
volatile int check[6] = { 0, 0, 0, 0, 0, 0 };
const int v[6] = { 1, 1, 2, 2, 1, 2 };
volatile int order = 0;

LedControl lc = LedControl(DIN, CLK, CS, 0);

void wow() {
  if (millis() - present1 > debounce) {
    if (digitalRead(BTN_1) == LOW) {
      if (order > 6) {
        order = 0;
        for (int i = 0; i < 6; i++) {
          check[i] = 0;
        }
      }
      check[order] = 1;
      if (check[order] == v[order]) {
        digitalWrite(LEDG, HIGH);
        delay(1000);
        digitalWrite(LEDG, LOW);
      } else {
        digitalWrite(LEDR, HIGH);
        delay(1000);
        digitalWrite(LEDR, LOW);
      }
      order++;
    }
  }
}

void omg() {
  if (millis() - present2 > debounce) {
    if (digitalRead(BTN_2) == LOW) {
      if (order > 6) {
        order = 0;
        for (int i = 0; i < 6; i++) {
          check[i] = 0;
        }
      }
      check[order] = 2;
      if (check[order] == v[order]) {
        digitalWrite(LEDG, HIGH);
        delay(1000);
        digitalWrite(LEDG, LOW);
      } else {
        digitalWrite(LEDR, HIGH);
        delay(1000);
        digitalWrite(LEDR, LOW);
      }
      order++;
    }
  }
}

void test() {
  byte t[8] = {
    B11111111, //ตัวเทส
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111
  };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, t[i]);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      lc.setLed(0, i, j, 0);
      delay(50);
    }
  }
}

void triangle() {
  byte a[8] = { //เป็น3เหลี่ยม
    B10000000,
    B11000000,
    B10100000,
    B10010000,
    B10001000,
    B10000100,
    B10000010,
    B11111111
  };

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, a[i]);
  }
}

void n() {
  byte A[8] = 
  {B00011000, //ตัว A
B00100100,
B01000010,
B01000010,
B01111110,
B01000010,
B01000010,
B01000010};

  byte R[8] = 
  {B01111100, //ตัว R
B01000100,
B01000100,
B01000100,
B01111100,
B01001000,
B01000100,
B01000010};

  byte T[8] = 
  {B11111111, //ตัวT
B11111111,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000,
B00011000
  };
  
  byte H[8] = 
  {B11000011, //ตัวH
B11000011,
B11000011,
B11111111,
B11111111,
B11000011,
B11000011,
B11000011};
 
  byte U[8] = 
  {B01000010,
B01000010,
B01000010,
B01000010,
B01000010,
B01000010,
B00100100,
B00011000};



  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, A[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, R[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, T[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, H[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, U[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, R[i]);
  }
  delay(500);
}


void num() {
  //1070
  byte zero[8] =
    {B00011000, //เลข0
B00100100,
B01000010,
B01000010,
B01000010,
B01000010,
B00100100,
B00011000
  };

  byte eight[8] = 
    {B00111100,
B01000010,
B01000010,
B00111100,
B01000010,
B01000010,
B01000010,
B00111100
  };

  byte five[8] = 
    {B01111110,
B01000000,
B01000000,
B01000000,
B01111110,
B00000010,
B00000010,
B01111110};
  byte seven[8] = 
    {B01111110,
B01000010,
B00000100,
B00001000,
B00111110,
B00001000,
B00001000,
B00001000};

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, zero[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, eight[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, five[i]);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, seven[i]);
  }
  delay(500);
}

void yolo() {
  byte y[8] = { B11111000,
                B11110000,
                B11110000,
                B11111000,
                B10011100,
                B00001110,
                B00000111,
                B00000010 };
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, y[i]);
  }
}


void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, LOW);

  attachInterrupt(digitalPinToInterrupt(BTN_1), wow, CHANGE);
  pinMode(BTN_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN_2), omg, CHANGE);
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  if (check[0] == 1 && check[1] == 1 && check[2] == 2 && check[3] == 2 && check[4] == 1 && check[5] == 2 && order == 6) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    delay(100);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDY, HIGH);
    delay(100);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, LOW);
    delay(100);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDY, HIGH);

    for (int i = 0; i < 6; i++) {
      check[i] = 0;
    }
    order = 0;
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, LOW);
  } else {
    for (int i = 0; i < 6; i++) {
      check[i] = 0;
    }
    order = 0;
    triangle();
    delay(1000);
    n();
    delay(1000);
    num();
    delay(1000);
    yolo();
    delay(1000);
  }
}
