
#include "settings.h"
#include <shs_debug.h>
#include <HandlerCoins.h>

shs::HanderCoins bank;

void setup()
{
    dinit();
    bank.start();
}


void loop()
{
    bank.tick();

    if (bank.)
}
