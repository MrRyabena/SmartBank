#include "telegram_bot.h"

void shs::TelegramBot::start()
{
    m_tbot.setToken("token");  // установка токена
    // bot.setToken(F("token")); // любым текстовым способом

    // НЕОБЯЗАТЕЛЬНЫЕ (указаны настройки по умолчанию)
    m_tbot.skipUpdates(-1);    // пропустить все входящие обновления
    m_tbot.setLimit(3);        // максимум сообщений в одном обновлении (экономия памяти)
    m_tbot.setPollMode(fb::Poll::Sync, 4000);
}

void shs::TelegramBot::message(){
    m_tbot.message("Копилка пополнена на сумму: " + String(sum) );
}


void shs::TelegramBot::tick()
{
    
}

void shs::TelegramBot::stop()
{
}
