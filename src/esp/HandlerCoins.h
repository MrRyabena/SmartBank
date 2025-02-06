#pragma once

#include <shs_ProgramTime.h>
#include <shs_Process.h>

#include <stdint.h>
#include <algorithm>
#include <shs_debug.h>
#include <array.h>

namespace shs
{
    class HandleCoins;
};

class shs::HandleCoins : public shs::Process
{
public:
    HandleCoins() : m_ir(A0), m_coins({ Coin(1), Coin(2), Coin(5), Coin(10) }) {}

    static constexpr auto NOTIFICATION_DELAY = 60; // in seconds

    [[nodiscard]] uint16_t getSum() const;

    void registerCoin(const uint8_t value) { m_register_coin_value = value; }

    void waiteCoin() { while (!m_coin_flag) { tick(); yield(); } }
    uint16_t getLastRAW() const { return m_ir_last; }

    [[nodiscard]] uint16_t getSumCoin(const uint8_t value) const;

    [[nodiscard]] uint16_t getActiveSum();
    [[nodiscard]] uint32_t getActiveTime() { return m_active_time_point.seconds(); }

    void start() override;
    void tick() override;
    void stop() override {}

private:
    struct Coin
    {
        Coin(const uint16_t set_value, const uint16_t set_ir_value = 0, const uint16_t set_counter = 0)
            : value(set_value), counter(set_counter), ir_value(set_ir_value)
        {
        }

        uint16_t value{};
        uint16_t ir_value{};
        uint16_t counter{};
    };

    struct CoinCompare { bool operator()(const Coin& lhs, const Coin& rhs) const { return lhs.value < rhs.value; } };

    std::array<Coin, 4> m_coins;

    shs::ProgramTime m_active_time_point;
    uint16_t m_active_sum{};
    uint8_t m_register_coin_value{};
    bool m_coin_flag{};

    //shs::SensorAnalog m_ir;
    uint16_t m_ir_empty{};
    uint16_t m_ir_last{};
};
