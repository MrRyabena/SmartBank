#pragma once

#include <shs_SensorAnalog.h>
#include <shs_ProgramTime.h>

#include <shs_SortedBuf.h>
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

    static constexpr auto NOTIFICATION_DELAY = 60; // in seconds

    [[nodiscard]] uint16_t getSum();

    void registerCoin(const uint8_t value) { m_register_coin_value = value; }

    [[nodiscard]] uint16_t getSumCoin(const uint8_t value) const;

    [[nodiscard]] uint16_t getActiveSum() const;
    [[nodiscard]] uint32_t getActiveTime() { return m_active_time_point.seconds(); }

    void start() override;
    void tick() override;
    void stop() override;

private:
    struct Coin
    {
        Coin(const uint16_t set_value, const uint16_t set_ir_value, const uin16_t set_counter)
            : value(set_value), counter(set_counter), ir_value(set_ir_value) {
        }

        uint16_t value{};
        uint16_t ir_value{};
        uint16_t counter{};
    };

    struct CoinCompare { bool operator(const Coin& lhs, const Coin& rhs) const { return lhs.value < rhs.value; } };

    shs::SortedBuf<Coin, CoinCompare> m_coins;

    shs::ProgramTime m_active_time_point;
    uint16_t m_active_sum{};
    uint8_t m_register_coin_value{};

    shs::SensorAnalog m_ir;
    uint16_t m_ir_empty{};
    uint16_t m_ir_last{};
};
