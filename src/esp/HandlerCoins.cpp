#include "HandlerCoins.h"

uint16_t shs::HandleCoins::getSum() const
{
    uint16_t res_sum{};
    for (auto& x : m_coins) res_sum += x.value * x.counter;
    return res_sum;
}

uint16_t shs::HandleCoins::getSumCoin(const uint8_t value) const
{
    auto it = std::find_if(m_coins.begin(), m_coins.end(), [value](const Coin& coin) { return coin.value == value; });
    if (it == m_coins.end()) return 0xffff;
    return it->value * it->counter;
}

uint16_t shs::HandleCoins::takeActiveSum()
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
    //LittleFS.begin();

    //m_storage.read();
    
    m_ir_empty = analogRead(0);
    m_ir_last = m_ir_empty;
}

void shs::HandleCoins::tick()
{
    uint16_t ir_value = analogRead(0);
    m_coin_flag = false;


    if (ir_value > m_ir_last) m_ir_last = ir_value;
    if (ir_value - m_ir_empty > 3) m_flag = true;

    if (m_flag && (abs(ir_value - m_ir_empty)) < 2)
    {
        m_coin_flag = true;

        if (m_register_coin_value)
        {
            auto val = m_register_coin_value;
            auto it = std::find_if(m_coins.begin(), m_coins.end(), [val](const Coin& coin) { return coin.value == val; });
            //if (it == m_coins.end()) return 0xffff;
        }


        for (auto i = 0; i < m_coins.size(); i++)
        {
            if (m_ir_last == 1024 && i != 2) continue;            // temporarily due to a flaw in the model
            auto delta = abs(m_ir_last - m_coins[i].ir_value);
            if (delta < 9)
            {
                m_coins[i].counter++;
                m_active_sum += m_coins[i].value;
                m_active_time_point.reset();
                //m_ir_last = m_ir_empty;
                break;

            }
        }

        m_ir_last = ir_value;
        m_flag = false;
    }

    //if (m_active_time_point.seconds() > NOTIFICATION_DELAY && m_active_sum) m_storage.write();
    //m_storage.updateNow();
}