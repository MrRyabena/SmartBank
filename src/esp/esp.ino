#include "settings.h"


#include <shs_ControlWiFi.h>
#include <FastBot.h>

#include "HandlerCoins.h"
#include "Segment.h"

shs::HandlerCoins bank;
shs::Segment segment(
    p_A, p_B, p_C, p_D, p_E, p_F, p_G,
    p_DIGIT_1, p_DIGIT_2, p_DIGIT_3, p_DIGIT_4
);

void onDelay();


void setup()
{
    uint8_t f = shs::ControlWiFi::connectWiFiWait(5000);

    botSetup();

    bank.start();
    segment.attachOnDelay(onDelay);
    segment.start();
    segment.set(10 + f);

    while (millis() < 8000) segment.tick();
}


void onDelay()
{
    bank.tick();
    yield();
}


void loop()
{
    bank.tick();
    segment.tick();

    if (bank.getActiveTime() >= shs::HandlerCoins::NOTIFICATION_DELAY)
    {
        auto val = bank.takeActiveSum();

        if (val)
        {
            botSendSum(val);
            segment.clear();
            segment.tick();
        }
        if (bank.getSum() == 0)
        {
            segment.clear();
            segment.tick();
        }
        botTick();

    }
    else
    {
        segment.set(bank.getSum());
    }
}
