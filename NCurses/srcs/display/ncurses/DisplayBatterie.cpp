//
// DisplayBatterie.cpp for DisplayBatterie.cpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/srcs/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:06:25 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:06:25 2017 Nicolas Chevalier
//
#include "../../../includes/display/ncurses/DisplayBatterie.hpp"
#include "../../../includes/modules/Ram.hpp"
#include "../../../includes/modules/Battery.hpp"
#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayBatterie::DisplayBatterie() : Ncurses(), _status(true)
{
  window = newwin(5, 90, 5, 0);
}

DisplayBatterie::~DisplayBatterie()
{
  setEndwin();
}

void DisplayBatterie::run()
{
  Battery Batterie;
  int level;
  bool status;
  int res;

  setWclear(window);
  level = Batterie.getBatteryLevel();
  status = Batterie.getACStatus();
  res = 100 - level;

  std::stringstream temp_str;
  temp_str << std::setprecision(3) << static_cast<float>(level);
  std::string str = temp_str.str();
  setBox(window, 0, 0);
  setWmove(window, 2, 1);
  setWprintw(window, "Battery: ");
  setWprintw(window, str.c_str());
  waddch(window, '%');
  setWprintw(window, "[");
  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (level / 2); i++)
    setWaddch(window, '|');
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "] ");
  if (status == 1)
    setWprintw(window, "Plugged ...");
  else
    setWprintw(window, "Unplugged ...");
  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayBatterie::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayBatterie::getStatus()
{
  return _status;
}

std::string DisplayBatterie::getDisplayName()
{
  return std::string(DISPLAYBATTERIE_MODULE_NAME);
}

int DisplayBatterie::getSize()
{
  return 0;
}
