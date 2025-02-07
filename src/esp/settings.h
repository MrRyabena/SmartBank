#pragma once


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
