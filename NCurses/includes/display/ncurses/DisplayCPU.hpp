//
// DisplayCPU.hpp for DisplayCPU.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:03 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:03 2017 Nicolas Chevalier
//
#ifndef CPP_GKRELLM_DISPLAYCPU_HPP
# define CPP_GKRELLM_DISPLAYBATTERIE_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

#define DISPLAYCPU_MODULE_NAME "DisplayCPU"

class DisplayCPU : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;

 public:
  DisplayCPU();

  virtual ~DisplayCPU();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYBATTERIE_HPP
