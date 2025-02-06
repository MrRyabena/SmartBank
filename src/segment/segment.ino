#include <Pineapple.h>

int serial = D6;  // shifte register, serial pin
int registerClock = D7;  // shift register, register clock
int serialClock = D8;  // shift register, clock

int numberofRegisters = 1;    // how many registers?

Pineapple pineapple;     // initialize the library

int digit_1 = D0; //1- единицы,..., 4-тысячи
int digit_2 = D1;
int digit_3 = D2;
int digit_4 = D3;

void setup() {
  segment_setup ();
}

uint32_t tmr{};
void loop (){
 // for (int i = 1;i<10000;i++){
   // while (millis() - tmr <= 50)
    //{
    //segment_out(9999);
    //}
    //tmr = millis();
    //delay(50);
  //}
}



void segment_out(int n) {
    digitalWrite(digit_1, false);
    pineapple.write(n%10);
    delay(1);
    digitalWrite(digit_1, true);
    if (n>9){
      digitalWrite(digit_2, false);
      pineapple.write(n%100/10);
      delay(1);
      digitalWrite(digit_2, true);
      if (n>99){
        digitalWrite(digit_3, false);
        pineapple.write(n%1000/100);
        delay(1);
        digitalWrite(digit_3, true);
        if (n>999){
          digitalWrite(digit_4, false);
          pineapple.write(n/1000);
          digitalWrite(digit_4, true);
        }
      }
    }
}
void segment_setup (){
  pinMode(digit_1, OUTPUT);
  pinMode(digit_2, OUTPUT);
  pinMode(digit_3, OUTPUT);
  pinMode(digit_4, OUTPUT);
  digitalWrite(digit_1, true);
  digitalWrite(digit_2, true);
  digitalWrite(digit_3, true);
  digitalWrite(digit_3, true);
  pineapple.segmentPins(0, 1, 2, 3, 4, 5, 6, 7, LOW);  // set high for common anode, and low for common cathode
  pineapple.registerPins(serial, registerClock, serialClock, numberofRegisters);
}
