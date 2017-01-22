//
// DisplayUser.hpp for DisplayUser.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:47 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:47 2017 Nicolas Chevalier
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
