/*
g++ -c omega2.cpp
g++ -shared omega2.o -o omega2.so
*/

#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <oled-exp.h>
#include <algorithm>

#define MINESERVER_C_API
#include "plugin_api.h"
#include "logtype.h"

#define PLUGIN_OMEGA2_VERSION 1.0

mineserver_pointer_struct* mineserver;

std::string pluginName = "omega2";
std::string logSource = "plugin.omega2";

std::vector<std::string> usernames;

std::string dtos(double n)
{
  std::ostringstream result;
  result << n;
  return result.str();
}

bool filelog_config_boolean(const char* key, bool defaultValue)
{
  if (!mineserver->config.has(key))
  {
    return defaultValue;
  }
  return mineserver->config.bData(key);
}


const char* filelog_config_string(const char* key, const char*defaultValue)
{
  if (!mineserver->config.has(key))
  {
    return defaultValue;
  }
  return mineserver->config.sData(key);
}



void timer10000Function()
{
  // mineserver->logger.log(LOG_INFO, logSource.c_str(), "Omega2 OLED is enabled");
}


void updateOled()
{
  oledSetCursor(4, 0);

  char result[10];
  sprintf(result, "%s %d ", "Online:", usernames.size());
  oledWrite(result);
}

void updatePlayerList(bool joining, const char *username)
{
  if (joining)
  {
    usernames.push_back(username);
  }
  else
  {
    std::vector<std::string>::iterator element = std::find(usernames.begin(), usernames.end(), std::string(username));

    if (element != usernames.end())
    {
      usernames.erase(element);
    }
  }

  updateOled();
}

bool on_player_login(const char *username)
{
  updatePlayerList(true, username);
  return false;
}

bool on_player_quit(const char *username)
{
  updatePlayerList(false, username);
  return false;
}

PLUGIN_API_EXPORT void CALLCONVERSION omega2_init(mineserver_pointer_struct* mineserver_temp)
{
  mineserver = mineserver_temp;

  if (mineserver->plugin.getPluginVersion(pluginName.c_str()) > 0)
  {
    std::string msg = atoi(pluginName.c_str())+ " is already loaded v."+dtos(mineserver->plugin.getPluginVersion(pluginName.c_str()));
    mineserver->logger.log(LOG_INFO, logSource.c_str(), msg.c_str());
    return;
  }
  std::string msg = "Loaded "+pluginName+"!";
  mineserver->logger.log(LOG_INFO, logSource.c_str(), msg.c_str());
  mineserver->plugin.setPluginVersion(pluginName.c_str(), PLUGIN_OMEGA2_VERSION);

  if (filelog_config_boolean("omega2.oled.enable", false))
  {

    oledDriverInit();
    oledSetDisplayPower(1);

    oledClear();

    oledSetCursor(0, 0);
    char t[] = "Omega2 MINESERVER";
    oledWrite(t);

    oledSetCursor(1, 0);
    char p[20];
    sprintf(p, "%s %d", "Max players:", mineserver->config.iData("system.user_limit"));
    oledWrite(p);

    updateOled();

    mineserver->plugin.addCallback("PlayerLoginPost", reinterpret_cast<voidF>(on_player_login));
    mineserver->plugin.addCallback("PlayerQuitPost", reinterpret_cast<voidF>(on_player_quit));

    mineserver->plugin.addCallback("Timer10000", reinterpret_cast<voidF>(timer10000Function));
    mineserver->logger.log(LOG_INFO, logSource.c_str(), "Omega2 OLED is enabled");
  }
}

PLUGIN_API_EXPORT void CALLCONVERSION omega2_shutdown(void)
{
  if (mineserver->plugin.getPluginVersion(pluginName.c_str()) <= 0)
  {
    mineserver->logger.log(LOG_INFO, logSource.c_str(), atoi(pluginName.c_str()) + " is not loaded!");
    return;
  }

  oledSetDisplayPower(0);
}
