#pragma once

#include <stdint.h>

#include <Arduino.h>

#include <shs_ProgramTime.h>
#include <shs_Process.h>



namespace shs
{
    class Segment;
};


class shs::Segment : public shs::Process
{
public:

    using OnDelayFunc = void (*)();

    void set(const uint16_t value) { m_value = value; m_on_flag = true; }
    void clear() { m_clearDisplay(); m_on_flag = false; }

    void attachOnDelay(OnDelayFunc f) { m_on_delay = f; }

    void start() override;
    void tick() override { if (m_on_flag) m_segment_out(m_value); }
    void stop() override { m_on_flag = false; }


    static constexpr auto p_A = D4;
    static constexpr auto p_B = D5;
    static constexpr auto p_C = D6;
    static constexpr auto p_D = D7;
    static constexpr auto p_E = D8;
    static constexpr auto p_F = 3;
    static constexpr auto p_G = 1;


    static constexpr auto p_DIGIT_1 = D0;
    static constexpr auto p_DIGIT_2 = D1;
    static constexpr auto p_DIGIT_3 = D2;
    static constexpr auto p_DIGIT_4 = D3;
private:
    OnDelayFunc m_on_delay{};
    uint16_t m_value{};
    bool m_on_flag;

    void m_segment_out(const uint16_t n);
    void m_num_display(const uint16_t  n);
    void m_clearDisplay();

    void m_delay(const uint16_t ms);

    void m_display1();
    void m_display2();
    void m_display3();
    void m_display4();
    void m_display5();
    void m_display6();
    void m_display7();
    void m_display8();
    void m_display9();
    void m_display0();
};

