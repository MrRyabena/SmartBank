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

    Segment(
        const uint8_t p_A, const uint8_t p_B, const uint8_t p_C,
        const uint8_t p_D, const uint8_t p_E,
        const uint8_t p_F, const uint8_t p_G,
        const uint8_t p_DIGIT_1, const uint8_t p_DIGIT_2,
        const uint8_t p_DIGIT_3, const uint8_t p_DIGIT_4
    );

    using OnDelayFunc = void (*)();

    void set(const uint16_t value) { m_value = value; m_on_flag = true; }
    void clear() { m_clearDisplay(); m_on_flag = false; }

    void attachOnDelay(OnDelayFunc f) { m_on_delay = f; }

    void start() override;
    void tick() override { if (m_on_flag) m_segment_out(m_value); }
    void stop() override { clear(); m_on_flag = false; }


private:
    OnDelayFunc m_on_delay{};
    uint16_t m_value{};
    bool m_on_flag;

    const uint8_t m_p_A;
    const uint8_t m_p_B;
    const uint8_t m_p_C;
    const uint8_t m_p_D;
    const uint8_t m_p_E;
    const uint8_t m_p_F;
    const uint8_t m_p_G;

    const uint8_t m_p_DIGIT_1;
    const uint8_t m_p_DIGIT_2;
    const uint8_t m_p_DIGIT_3;
    const uint8_t m_p_DIGIT_4;

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

