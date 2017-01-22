//
// Created by cheval_8 on 1/21/17.
//
#include "../../../includes/display/ncurses/DisplayUser.hpp"
#include "../../../includes/modules/User.hpp"
#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayUser::DisplayUser() : Ncurses(), _status(true)
{
  window = newwin(6, 30, 0, 120);
}

DisplayUser::~DisplayUser()
{
  setEndwin();
}

void DisplayUser::run()
{
  User user;
  int level;

  level = 0;
  setWclear(window);

  setBox(window, 0, 0);
  setWmove(window, 2, 1);
  setWprintw(window, "UserName: ");
  setWprintw(window, user.getUserName().c_str());
  setWmove(window, 3, 1);
  setWprintw(window, "Machine name: ");
  setWprintw(window, user.getMachineName().c_str());
  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayUser::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayUser::getStatus()
{
  return _status;
}

std::string DisplayUser::getDisplayName()
{
  return std::string(DISPLAYUSER_MODULE_NAME);
}

int DisplayUser::getSize()
{
  return 0;
}
