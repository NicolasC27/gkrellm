//
// DisplayDate.hpp for DisplayDate.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:12 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:12 2017 Nicolas Chevalier
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
