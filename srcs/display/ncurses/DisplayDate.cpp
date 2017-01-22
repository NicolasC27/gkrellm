//
// DisplayDate.cpp for DisplayDate.cpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/srcs/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:06:41 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:06:41 2017 Nicolas Chevalier
//
#include "../../../includes/display/ncurses/DisplayDate.hpp"
#include "../../../includes/modules/Date.hpp"
#include "../../../includes/modules/User.hpp"

#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayDate::DisplayDate() : Ncurses(), _status(true)
{
  window = newwin(6, 30, 8, 120);
}

DisplayDate::~DisplayDate()
{
  setEndwin();
}

void DisplayDate::run()
{
  Date date;

  setWclear(window);
  setBox(window, 0, 0);
  setWmove(window, 2, 1);
  setWprintw(window, "Date: ");
  std::stringstream temp_str;
  temp_str << date.getTime();
  std::string str = temp_str.str();
  setWprintw(window, str.c_str());
  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayDate::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayDate::getStatus()
{
  return _status;
}

std::string DisplayDate::getDisplayName()
{
  return std::string(DISPLAYDATE_MODULE_NAME);
}

int DisplayDate::getSize()
{
  return 0;
}
