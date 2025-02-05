#pragma once

#include <shs_Processs.h>
#include <LittleFS.h>

namespace shs
{
    class SmartBank;
}

class shs::SmartBank : public shs::Process
{
public:
    SmartBank() : m_photosens(A0) {}

    void start() override;
    void tick() override;
    void stop() override;

private:

    

};
