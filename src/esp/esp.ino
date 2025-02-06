#define DEBUG
#include "settings.h"
//#include <shs_debug.h>
//#include "HandlerCoins.h"

//shs::HandleCoins bank;
uint16_t last{};
uint16_t val{};
void setup() {
  dinit();
  doutln();
  dsep();
  //bank.start();
  last = analogRead(0);
}



void loop() {
  val = analogRead(0);
  if (abs(val - last) > 30) doutln(val);
  //doutln(val);
  //bank.waiteCoin();
  //bank.tick();
  //doutln(bank.getLastRAW());
 // doutln(analogRead(A0));

}
