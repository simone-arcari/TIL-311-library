#ifndef TIL_311_h
#define TIL_311_h

class TIL_311 {
    public:   
        //attributes
        short int LatchDataInputA;
        short int LatchDataInputB; 
        short int LatchDataInputC; 
        short int LatchDataInputD;
        short int LatchStrobeInput;
        short int LeftPointDecCathod;
        short int RightPointDecCathod;
        short int BlankingInput;
        short int numberToDisplay = 0;

        // methods
        TIL_311(short int,short int,short int,short int,short int,short int,short int,short int); //costruttore
        void printNumber(short int);
        void turnOnLeftPoint(void);
        void turnOffLeftPoint(void);
        void turnOnRightPoint(void);
        void turnOffRightPoint(void);
        void turnOnBlankingInput(void);
        void turnOffBlankingInput(void);
        bool binaryConvertForOneBit(short int); 
};



TIL_311::TIL_311(short int a, short int b, short int c, short int d, short int strobe, short int leftPoint = -1, short int rightPoint = -1, short int blanking = -1) {
    LatchDataInputA = a;
    LatchDataInputB = b; 
    LatchDataInputC = c; 
    LatchDataInputD = d;
    LatchStrobeInput = strobe;
    LeftPointDecCathod = leftPoint;
    RightPointDecCathod = rightPoint;
    BlankingInput = blanking;
}

void TIL_311::printNumber(short int number) {
    if(number < 0 && number > 15) {
        return; 
    }

    numberToDisplay = number;

    short int outputValue_A = binaryConvertForOneBit(0);
    short int outputValue_B = binaryConvertForOneBit(1);
    short int outputValue_C = binaryConvertForOneBit(2);
    short int outputValue_D = binaryConvertForOneBit(3);

    digitalWrite(LatchStrobeInput, LOW);
  
    digitalWrite(LatchDataInputA, outputValue_A);
    digitalWrite(LatchDataInputB, outputValue_B);
    digitalWrite(LatchDataInputC, outputValue_C);
    digitalWrite(LatchDataInputD, outputValue_D);

    digitalWrite(LatchStrobeInput, HIGH);
}

void TIL_311::turnOnLeftPoint(void) {
    digitalWrite(LeftPointDecCathod, OUTPUT);  
}

void TIL_311::turnOffLeftPoint(void) {
    digitalWrite(LeftPointDecCathod, LOW);  
}

void TIL_311::turnOnRightPoint(void) {
    digitalWrite(RightPointDecCathod, OUTPUT);
}

void TIL_311::turnOffRightPoint(void){
    digitalWrite(RightPointDecCathod, LOW);
}

void TIL_311::turnOnBlankingInput(void) {
    digitalWrite(BlankingInput, OUTPUT);
}

void TIL_311::turnOffBlankingInput(void) {
    digitalWrite(BlankingInput, LOW);
}

bool TIL_311::binaryConvertForOneBit(short int bitPosition) {
    short int confronto = 0b0001;
    if(numberToDisplay & (confronto << bitPosition))
        return HIGH;
    else
        return LOW; 
}

#endif
