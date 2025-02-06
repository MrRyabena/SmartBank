#pragma once


#if __has_include("sectets.h")
#include "secrets.h"
static constexpr auto TBOT_TOKEN = SECRETS_TBOT_TOKEN;
#endif
