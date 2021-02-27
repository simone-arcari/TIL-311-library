#include "TIL_311.h"

#define LatchDataInputA_1 5
#define LatchDataInputB_1 4
#define LatchDataInputC_1 6
#define LatchDataInputD_1 7
#define LatchStrobeInput_1 3

#define LatchDataInputA_2 11
#define LatchDataInputB_2 10
#define LatchDataInputC_2 12
#define LatchDataInputD_2 13
#define LatchStrobeInput_2 9

int number = 0;
TIL_311 display1 = TIL_311(LatchDataInputA_1,LatchDataInputB_1,LatchDataInputC_1,LatchDataInputD_1,LatchStrobeInput_1);
TIL_311 display2 = TIL_311(LatchDataInputA_2,LatchDataInputB_2,LatchDataInputC_2,LatchDataInputD_2,LatchStrobeInput_2);


void setup() {
  // put your setup code here, to run once:

  //display1 pin
  pinMode(LatchDataInputA_1, OUTPUT);
  pinMode(LatchDataInputB_1, OUTPUT);
  pinMode(LatchDataInputC_1, OUTPUT);
  pinMode(LatchDataInputD_1, OUTPUT);
  pinMode(LatchStrobeInput_1, OUTPUT);

  //display2 pin
  pinMode(LatchDataInputA_2, OUTPUT);
  pinMode(LatchDataInputB_2, OUTPUT);
  pinMode(LatchDataInputC_2, OUTPUT);
  pinMode(LatchDataInputD_2, OUTPUT);
  pinMode(LatchStrobeInput_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  display1.printNumber(number);
  display2.printNumber(number);

  number++;
  if(number > 15)
    number = 0;

  delay(500);
}
