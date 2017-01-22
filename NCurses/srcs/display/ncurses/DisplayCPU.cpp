//
// DisplayCPU.cpp for DisplayCPU.cpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/srcs/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:06:34 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:06:34 2017 Nicolas Chevalier
//
#include "../../../includes/display/ncurses/DisplayCPU.hpp"
#include "../../../includes/modules/Cpu.hpp"
#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayCPU::DisplayCPU() : Ncurses(), _status(true)
{
  window = newwin(10, 80, 20, 0);
}

DisplayCPU::~DisplayCPU()
{
  setEndwin();
}

void DisplayCPU::run()
{
  Cpu cpu;
  double var1;
  double var2;
  double var3;
  double var4;
  double res;

  var1 = cpu.cpu[0];
  var2 = cpu.cpu[1];
  var3 = cpu.cpu[2];
  var4 = cpu.cpu[3];
  setWclear(window);
  setBox(window, 0, 0);
  setWmove(window, 2, 1);

  setWprintw(window, "CPU1: ");
  setWprintw(window, std::to_string(var1).c_str());
  setWmove(window, 2, 18);
  setWprintw(window, "[");
  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (var1 / 2); i++)
    setWaddch(window, '|');
  res = 100 - var1;
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "]");

  setWmove(window, 3, 1);
  setWprintw(window, "CPU2: ");
  setWprintw(window, std::to_string(var2).c_str());
  setWmove(window, 3, 18);
  setWprintw(window, "[");
  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (var2 / 2); i++)
    setWaddch(window, '|');
  res = 100 - var2;
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "]");

  setWmove(window, 4, 1);
  setWprintw(window, "CPU3: ");
  setWprintw(window, std::to_string(var3).c_str());
  setWmove(window, 4, 18);
  setWprintw(window, "[");
  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (var3 / 2); i++)
    setWaddch(window, '|');
  res = 100 - var3;
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "]");

  setWmove(window, 5, 1);
  setWprintw(window, "CPU4: ");
  setWprintw(window, std::to_string(var4).c_str());
  setWmove(window, 5, 18);
  setWprintw(window, "[");
  setWattron(window, COLOR_PAIR(2));
  for (int i = 0; i < (var4 / 2); i++)
    setWaddch(window, '|');
  res = 100 - var4;
  setWattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < (res / 2); i++)
    setWaddch(window, '|');
  setWprintw(window, "]");

  setWmove(window, 6, 1);
  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayCPU::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayCPU::getStatus()
{
  return _status;
}

std::string DisplayCPU::getDisplayName()
{
  return std::string(DISPLAYCPU_MODULE_NAME);
}

int DisplayCPU::getSize()
{
  return 0;
}
