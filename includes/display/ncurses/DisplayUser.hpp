//
// Created by cheval_8 on 1/21/17.
//
#ifndef CPP_GKRELLM_DISPLAYUSER_HPP
# define CPP_GKRELLM_DISPLAYUSER_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

#define DISPLAYUSER_MODULE_NAME "DisplayUser"

class DisplayUser : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;

 public:
  DisplayUser();

  virtual ~DisplayUser();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYUSER_HPP
