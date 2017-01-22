//
// DisplayRam.hpp for DisplayRam.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:37 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:37 2017 Nicolas Chevalier
//
#ifndef CPP_GKRELLM_DISPLAYRAM_HPP
#define CPP_GKRELLM_DISPLAYRAM_HPP

#include <iostream>
#include "Ncurses.hpp"
#include "../IMonitorDisplay.hpp"

# define DISPLAYRAM_MODULE_NAME "DisplayRam"

class DisplayRam : public IMonitorDisplay, public Ncurses
{
 private:

  bool _status;
  WINDOW *window;
  float _total;
  float _occup;

 public:
  DisplayRam();

  virtual ~DisplayRam();

  void run();

  DisplayType getType();

  bool getStatus();


  std::string getDisplayName();

  DisplayType	getType() const;
  int getSize();
};


#endif //CPP_GKRELLM_DISPLAYRAM_HPP
