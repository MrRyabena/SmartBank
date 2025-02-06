#pragma once


#include <shs_Process.h>

#include <FastBot2.h>

namespace shs
{
    class TelegramBot;
}

class shs::TelegramBot : shs::Process
{
public: 
    TelegramBot();

    void onSumChange(const uint16_t sum);   // notification

    void message();

    void handler();

    void start() override;
    void tick() override;
    void stop() override;

private:
   FastBot2 m_tbot;
};
