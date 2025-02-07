#include "settings.h"

#include <array>

#include <shs_ControlWiFi.h>
#include <FastBot.h>

#include "HandlerCoins.h"
#include "Segment.h"

shs::HandleCoins bank;
shs::Segment segment;

void onDelay();

void setup() {
  uint8_t f = shs::ControlWiFi::connectWiFiWait(5000);

  botSetup();

  bank.start();
  segment.attachOnDelay(onDelay);
  segment.start();
  segment.set(10 + f);
  
  while (millis() < 8000) segment.tick();
}


void onDelay() {
  bank.tick();
  yield();
}


void loop() {

  bank.tick();
  segment.tick();
 
  if (bank.getActiveTime() >= 60) {
    auto val = bank.takeActiveSum();

    if (val) {
      botSendSum(val);
      segment.clear();
      segment.tick();
    }
    if (bank.getSum() == 0) {segment.clear();
      segment.tick();}
    botTick();

  } else {
    segment.set(bank.getSum());
  }
}
