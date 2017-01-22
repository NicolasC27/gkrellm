//
// DisplayBatterie.hpp for DisplayBatterie in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:04:50 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:04:51 2017 Nicolas Chevalier
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
