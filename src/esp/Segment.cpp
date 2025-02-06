#include "Segment.h"

void shs::Segment::start()
{
    pinMode(p_A, OUTPUT);
    pinMode(p_B, OUTPUT);
    pinMode(p_C, OUTPUT);
    pinMode(p_D, OUTPUT);
    pinMode(p_E, OUTPUT);
    pinMode(p_F, OUTPUT);
    pinMode(p_G, OUTPUT);

    pinMode(p_DIGIT_1, OUTPUT);
    pinMode(p_DIGIT_2, OUTPUT);
    pinMode(p_DIGIT_3, OUTPUT);
    pinMode(p_DIGIT_4, OUTPUT);

    digitalWrite(p_DIGIT_1, true);
    digitalWrite(p_DIGIT_2, true);
    digitalWrite(p_DIGIT_3, true);
    digitalWrite(p_DIGIT_4, true);
}


void shs::Segment::m_segment_out(const uint16_t n)
{
    digitalWrite(p_DIGIT_1, false);
    m_num_display(n % 10);
    m_delay(1);
    m_clearDisplay();
    digitalWrite(p_DIGIT_1, true);
    if (n > 9)
    {
        digitalWrite(p_DIGIT_2, false);
        m_num_display(n % 100 / 10);
        m_delay(1);
        m_clearDisplay();
        digitalWrite(p_DIGIT_2, true);
        if (n > 99)
        {
            digitalWrite(p_DIGIT_3, false);
            m_num_display(n % 1000 / 100);
            m_delay(1);
            m_clearDisplay();
            digitalWrite(p_DIGIT_3, true);
            if (n > 999)
            {
                digitalWrite(p_DIGIT_4, false);
                m_num_display(n / 1000);
                m_delay(1);
                m_clearDisplay();
                digitalWrite(p_DIGIT_4, true);
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
    digitalWrite(p_A, LOW);
    digitalWrite(p_B, LOW);

    digitalWrite(p_G, LOW);
    digitalWrite(p_C, LOW);
    digitalWrite(p_D, LOW);

    digitalWrite(p_E, LOW);
    digitalWrite(p_F, LOW);
}

void shs::Segment::m_delay(const uint16_t ms)
{
    shs::ProgramTime timer;
    while (timer.milliseconds() < ms)  if (m_on_delay) m_on_delay();
}



void shs::Segment::m_display1()
{
    digitalWrite(p_B, HIGH);
    digitalWrite(p_C, HIGH);
}

void shs::Segment::m_display2()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_B, HIGH);

    digitalWrite(p_G, HIGH);
    digitalWrite(p_E, HIGH);
    digitalWrite(p_D, HIGH);
}


void shs::Segment::m_display3()
{
    digitalWrite(p_A, HIGH);

    digitalWrite(p_B, HIGH);

    digitalWrite(p_C, HIGH);
    digitalWrite(p_D, HIGH);

    digitalWrite(p_G, HIGH);
}


void shs::Segment::m_display4()
{
    digitalWrite(p_F, HIGH);
    digitalWrite(p_B, HIGH);
    digitalWrite(p_G, HIGH);

    digitalWrite(p_C, HIGH);
}


void shs::Segment::m_display5()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_F, HIGH);
    digitalWrite(p_G, HIGH);

    digitalWrite(p_C, HIGH);
    digitalWrite(p_D, HIGH);
}



void shs::Segment::m_display6()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_F, HIGH);

    digitalWrite(p_G, HIGH);
    digitalWrite(p_C, HIGH);
    digitalWrite(p_D, HIGH);

    digitalWrite(p_E, HIGH);
}



void shs::Segment::m_display7()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_B, HIGH);
    digitalWrite(p_C, HIGH);
}



void shs::Segment::m_display8()
{
    digitalWrite(p_A, HIGH);

    digitalWrite(p_B, HIGH);
    digitalWrite(p_G, HIGH);
    digitalWrite(p_C, HIGH);

    digitalWrite(p_D, HIGH);
    digitalWrite(p_E, HIGH);
    digitalWrite(p_F, HIGH);
}


void shs::Segment::m_display9()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_B, HIGH);
    digitalWrite(p_G, HIGH);

    digitalWrite(p_C, HIGH);
    digitalWrite(p_D, HIGH);
    digitalWrite(p_F, HIGH);
}


void shs::Segment::m_display0()
{
    digitalWrite(p_A, HIGH);
    digitalWrite(p_B, HIGH);

    digitalWrite(p_C, HIGH);
    digitalWrite(p_D, HIGH);
    digitalWrite(p_E, HIGH);

    digitalWrite(p_F, HIGH);
}
