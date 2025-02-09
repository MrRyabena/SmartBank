#pragma once

#include <Arduino.h>


#if __has_include("secrets.h")
#include "secrets.h"
static constexpr auto TBOT_TOKEN = SECRETS_TBOT_TOKEN;
static constexpr auto CHAT_ID = SECRETS_CHAT_ID;        // commander's chat
#else
#pragma message "It is necessary to specify private data"
static constexpr auto TBOT_TOKEN = "";
static constexpr auto CHAT_ID = "0";
#endif

#define BOT_ACTIVE
static constexpr auto TBOT_NAME = "@shs_SmartBank_bot";

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
