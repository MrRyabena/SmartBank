#include "Segment.h"


shs::Segment::Segment(
    const uint8_t p_A, const uint8_t p_B, const uint8_t p_C,
    const uint8_t p_D, const uint8_t p_E,
    const uint8_t p_F, const uint8_t p_G,
    const uint8_t p_DIGIT_1, const uint8_t p_DIGIT_2,
    const uint8_t p_DIGIT_3, const uint8_t p_DIGIT_4
)
    :
    m_p_A(p_A), m_p_B(p_B), m_p_C(p_C),
    m_p_D(p_D), m_p_E(p_E), m_p_F(p_F),
    m_p_G(p_G),
    m_p_DIGIT_1(p_DIGIT_1), m_p_DIGIT_2(p_DIGIT_2),
    m_p_DIGIT_3(p_DIGIT_3), m_p_DIGIT_4(p_DIGIT_4)
{}



void shs::Segment::start()
{
    pinMode(m_p_A, OUTPUT);
    pinMode(m_p_B, OUTPUT);
    pinMode(m_p_C, OUTPUT);
    pinMode(m_p_D, OUTPUT);
    pinMode(m_p_E, OUTPUT);
    pinMode(m_p_F, OUTPUT);
    pinMode(m_p_G, OUTPUT);

    pinMode(m_p_DIGIT_1, OUTPUT);
    pinMode(m_p_DIGIT_2, OUTPUT);
    pinMode(m_p_DIGIT_3, OUTPUT);
    pinMode(m_p_DIGIT_4, OUTPUT);

    digitalWrite(m_p_DIGIT_1, true);
    digitalWrite(m_p_DIGIT_2, true);
    digitalWrite(m_p_DIGIT_3, true);
    digitalWrite(m_p_DIGIT_4, true);
}


void shs::Segment::m_segment_out(const uint16_t n)
{
    digitalWrite(m_p_DIGIT_1, false);
    m_num_display(n % 10);
    m_delay(1);
    m_clearDisplay();
    digitalWrite(m_p_DIGIT_1, true);
    if (n > 9)
    {
        digitalWrite(m_p_DIGIT_2, false);
        m_num_display(n % 100 / 10);
        m_delay(1);
        m_clearDisplay();
        digitalWrite(m_p_DIGIT_2, true);
        if (n > 99)
        {
            digitalWrite(m_p_DIGIT_3, false);
            m_num_display(n % 1000 / 100);
            m_delay(1);
            m_clearDisplay();
            digitalWrite(m_p_DIGIT_3, true);
            if (n > 999)
            {
                digitalWrite(m_p_DIGIT_4, false);
                m_num_display(n / 1000);
                m_delay(1);
                m_clearDisplay();
                digitalWrite(m_p_DIGIT_4, true);
            }
        }
    }
}


inline void shs::Segment::m_num_display(const uint16_t n)
{
    switch (n)
    {
    case 0: m_display0(); break;
    case 1: m_display1(); break;
    case 2: m_display2(); break;
    case 3: m_display3(); break;
    case 4: m_display4(); break;
    case 5: m_display5(); break;
    case 6: m_display6(); break;
    case 7: m_display7(); break;
    case 8: m_display8(); break;
    case 9: m_display9(); break;
    }
}


void shs::Segment::m_clearDisplay()
{
    digitalWrite(m_p_A, LOW);
    digitalWrite(m_p_B, LOW);

    digitalWrite(m_p_G, LOW);
    digitalWrite(m_p_C, LOW);
    digitalWrite(m_p_D, LOW);

    digitalWrite(m_p_E, LOW);
    digitalWrite(m_p_F, LOW);
}

void shs::Segment::m_delay(const uint16_t ms)
{
    shs::ProgramTime timer;
    while (timer.milliseconds() < ms)  if (m_on_delay) m_on_delay();
}



void shs::Segment::m_display1()
{
    digitalWrite(m_p_B, HIGH);
    digitalWrite(m_p_C, HIGH);
}

void shs::Segment::m_display2()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_B, HIGH);

    digitalWrite(m_p_G, HIGH);
    digitalWrite(m_p_E, HIGH);
    digitalWrite(m_p_D, HIGH);
}


void shs::Segment::m_display3()
{
    digitalWrite(m_p_A, HIGH);

    digitalWrite(m_p_B, HIGH);

    digitalWrite(m_p_C, HIGH);
    digitalWrite(m_p_D, HIGH);

    digitalWrite(m_p_G, HIGH);
}


void shs::Segment::m_display4()
{
    digitalWrite(m_p_F, HIGH);
    digitalWrite(m_p_B, HIGH);
    digitalWrite(m_p_G, HIGH);

    digitalWrite(m_p_C, HIGH);
}


void shs::Segment::m_display5()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_F, HIGH);
    digitalWrite(m_p_G, HIGH);

    digitalWrite(m_p_C, HIGH);
    digitalWrite(m_p_D, HIGH);
}



void shs::Segment::m_display6()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_F, HIGH);

    digitalWrite(m_p_G, HIGH);
    digitalWrite(m_p_C, HIGH);
    digitalWrite(m_p_D, HIGH);

    digitalWrite(m_p_E, HIGH);
}



void shs::Segment::m_display7()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_B, HIGH);
    digitalWrite(m_p_C, HIGH);
}



void shs::Segment::m_display8()
{
    digitalWrite(m_p_A, HIGH);

    digitalWrite(m_p_B, HIGH);
    digitalWrite(m_p_G, HIGH);
    digitalWrite(m_p_C, HIGH);

    digitalWrite(m_p_D, HIGH);
    digitalWrite(m_p_E, HIGH);
    digitalWrite(m_p_F, HIGH);
}


void shs::Segment::m_display9()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_B, HIGH);
    digitalWrite(m_p_G, HIGH);

    digitalWrite(m_p_C, HIGH);
    digitalWrite(m_p_D, HIGH);
    digitalWrite(m_p_F, HIGH);
}


void shs::Segment::m_display0()
{
    digitalWrite(m_p_A, HIGH);
    digitalWrite(m_p_B, HIGH);

    digitalWrite(m_p_C, HIGH);
    digitalWrite(m_p_D, HIGH);
    digitalWrite(m_p_E, HIGH);

    digitalWrite(m_p_F, HIGH);
}
