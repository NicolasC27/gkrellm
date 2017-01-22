//
// Created by cheval_8 on 1/21/17.
//
#ifndef CPP_GKRELLM_DISPLAYNETWORK_HPP
# define CPP_GKRELLM_DISPLAYNETWORK_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

#define DISPLAYNETWORK_MODULE_NAME "DisplayNetwork"

class DisplayNetwork : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;

 public:
  DisplayNetwork();

  virtual ~DisplayNetwork();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYNETWORK_HPP
