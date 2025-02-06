#include "settings.h"

#include <shs_ControlWiFi.h>
#include <FastBot.h>

#include "HandlerCoins.h"
#include "Segment.h"

shs::HandleCoins bank;
shs::Segment segment;

void onDelay();

void setup() {
  shs::ConnectWiFi();

  bank.start();
  segment.attachOnDelay(onDelay);
  segment.start();
}


void onDelay() {
  bank.tick();
}


void loop() {

  bank.tick();

  segment.set(bank.getSum());
  segment.tick();
}
