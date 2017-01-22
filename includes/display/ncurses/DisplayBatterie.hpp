//
// Created by cheval_8 on 1/21/17.
//
#ifndef CPP_GKRELLM_DISPLAYBATTERIE_HPP
# define CPP_GKRELLM_DISPLAYBATTERIE_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

#define DISPLAYBATTERIE_MODULE_NAME "DisplayBatterie"

class DisplayBatterie : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;

 public:
  DisplayBatterie();

  virtual ~DisplayBatterie();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYBATTERIE_HPP
