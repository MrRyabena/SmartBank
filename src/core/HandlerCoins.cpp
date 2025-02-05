#include "HandlerCoins.h"

uint16_t shs::HandleCoins::getActiveSum()
{
    if (m_active_time_point.seconds() > NOTIFICATION_DELAY && m_active_sum)
    {
        auto value = m_active_sum;
        m_active_sum = 0;
        return value;
    }
    return 0;
}

void shs::HandleCoins::start()
{
    m_ir.setup();
    m_ir.update();

    m_ir_empty = m_ir.getValueI();
    m_ir_last = m_ir_empty;
}

void shs::HandleCoins::tick()
{
    m_ir.update();
    bool flag{};

    if (m_ir.getValueI() > m_ir_last)
        m_ir_last = m_ir.getValueI();
    if (!(m_ir.getValueI() - m_ir_empty > 3))
        return;

    if ((abs(m_ir.getValueI() - m_ir_empty) < 2))
    {
        if (m_register_coin_value)
            m_coins.push_back(Coin(m_register_coin_value, m_ir.getValueI()));

        for (auto coin : m_coins)
        {
            auto delta = abs(m_ir.getValueI() - coin.ir_value);
            if (delta < 30)
            {
                m_coins.counter++;
                m_active_sum += m_coins.value;

                m_active_time_point.reset();
            }
        }
    }
}
