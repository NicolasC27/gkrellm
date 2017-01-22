//
// Created by cheval_8 on 1/21/17.
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
  sleep(1);
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
