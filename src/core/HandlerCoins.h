#pragma once

#include <shs_SensorAnalog.h>
#include <shs_ProgramTime.h>

#include <vector>
#include <stdint.h>
#include <algorithm>

namespace shs
{
    class HandleCoins;
};

class shs::HandleCoins : public shs::Process
{
public:
    HandleCoins() {}

    static constexpr auto NOTIFICATION_DELAY = 60;

    [[nodiscard]] uint16_t getSum()
    {
        uint16_t res_sum{};
        for (auto &x : m_coins)
            res_sum += x.value * x.value;
        return res_sum();
    }

    void registerCoin(const uint16_t value)
    {
        m_register_coin_value = value;
    }

    [[nodiscard]] uint16_t getSumCoin(const uint8_t value);

    [[nodiscard]] uint16_t getActiveSum();
    [[nodiscard]] uint32_t getActiveTime() { return m_active_time_point.seconds(); }

    void start() override;
    void tick() override;
    void stop() override;

private:
    struct Coin
    {
        Coin(const uint16_t set_value, const uint16_t set_ir_value, const uin16_t set_counter)
            : value(set_value), counter(set_counter), ir_value(set_ir_value) {}

        uint16_t value{};
        uint16_t ir_value{};
        uint16_t counter{};
    };

    std::vector<Coin> m_coins;

    shs::ProgramTime m_active_time_point;
    uint16_t m_active_sum{};
    uint16_t m_register_coin_value{};

    shs::SensorAnalog m_ir;
    uint16_t m_ir_empty{};
    uint16_t m_ir_last{};
};
