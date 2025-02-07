FastBot bot(TBOT_TOKEN);

void botSetup()
{
#ifdef BOT_UPDATE_TIME
  bot.setPeriod(BOT_UPDATE_TIME);
#endif

  bot.attach(handleBot);

  bot.setTextMode(FB_HTML);
  botSendNotification("I am started!");
}

void botTick()
{

#ifdef BOT_ACTIVE

  bot.tick();

#endif
}

void botSendNotification(String message)
{
#ifdef BOT_ACTIVE

  bot.sendMessage("<b><u><i>SYSTEM NOTIFICATION!</i></u>\n" + message + "</b>", CHAT_ID);

#endif
}

void botSendSum(uint16_t sum)
{
String mes = "The bank is replenished on: ";
mes += sum;

  bot.sendMessage(mes, CHAT_ID);
}


void handleBot(FB_msg& message)
{
  if (message.OTA && message.text.equals(F("/OTA")))
  {
    if (message.fileName.indexOf(F("mklittlefs")) > 0 || message.fileName.indexOf(F("spiffs")) > 0)
    {
      bot.updateFS();  // update spiffs
    }
    else
    {
      bot.update();  // update sketch
    }
  }

  if (message.text.indexOf('@') != -1) if (message.text.indexOf(TBOT_NAME) != -1) message.text.remove(0, strlen(TBOT_NAME));
  if (message.text.startsWith("/")) message.text.remove(0, 1);


  if (message.text.startsWith(F("sum")))
  {
    String answ = "Sum in bank:  ";
    answ += bank.getSum();

    bot.sendMessage(answ, message.chatID);
  }

  else if (message.text.startsWith(F("stat")))
  {
    String answ = "Statistics\n";
    static constexpr uint8_t values[] = {1, 2, 5, 10};
    for (auto i = 0; i < 4; i++) answ += String(values[i]) + "  --  " + bank.getSumCoin(values[i]) + '\n';

    bot.sendMessage(answ, message.chatID);
  }

  else if (message.text.startsWith(F("reset")))
  {
    bank.reset();
  }
}
