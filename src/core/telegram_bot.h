#pragma once


#include <shs_Process.h>

namespace shs
{
    class TelegramBot;
}

class shs::TelegramBot : shs::Process
{
public: 
    TelegramBot();

    void start() override;
    void tick() override;
    void stop() override;
};
