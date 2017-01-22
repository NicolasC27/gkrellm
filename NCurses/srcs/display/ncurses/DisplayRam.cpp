//
// DisplayRam.cpp for DisplayRam.cpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/srcs/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:06:57 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:06:58 2017 Nicolas Chevalier
//
#include "../../../includes/display/ncurses/DisplayRam.hpp"
#include "../../../includes/modules/Ram.hpp"
#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayRam::DisplayRam() : Ncurses(), _status(true)
{
  window = newwin(5, 80, 0, 0);
}

DisplayRam::~DisplayRam()
{
  setEndwin();
}

void DisplayRam::run()
{

  Ram ram;
  float total;
  float occup;
  float pourcent;
  float res;

  setWclear(window);
  occup = static_cast<float>(ram.getOccupRam());
  total = static_cast<float>(ram.getTotalRam());
  pourcent = (occup / total) * 100;
  res = 100 - pourcent;

  std::stringstream temp_str;
  temp_str << std::setprecision(3) << static_cast<float>(ram.getOccupRam()) / 1000000;
  std::string str = temp_str.str();
  setBox(window, 0, 0);
  setWmove(window, 2, 1);
  setWprintw(window, "Mem: ");
  setWprintw(window, str.c_str());
  setWprintw(window, "GB / ");

  temp_str.str("");
  temp_str << std::setprecision(3) << static_cast<float>(ram.getTotalRam()) / 1000000;
  str = temp_str.str();
  setWprintw(window, str.c_str());
  setWprintw(window, "GB ");
  setWmove(window, 2, 23);
  setWprintw(window, "[");

  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (pourcent / 2); i++)
    setWaddch(window, '|');
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "]");

  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayRam::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayRam::getStatus()
{
  return _status;
}

std::string DisplayRam::getDisplayName()
{
  return std::string(DISPLAYRAM_MODULE_NAME);
}

int DisplayRam::getSize()
{
  return 0;
}
