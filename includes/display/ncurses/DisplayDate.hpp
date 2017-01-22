//
// Created by cheval_8 on 1/21/17.
//
#ifndef CPP_GKRELLM_DISPLAYDATE_HPP
# define CPP_GKRELLM_DISPLAYDATE_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

#define DISPLAYDATE_MODULE_NAME "DisplayDate"

class DisplayDate : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;

 public:
  DisplayDate();

  virtual ~DisplayDate();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYDATE_HPP
