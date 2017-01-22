//
// DisplayNetwork.hpp for DisplayNetwork.hpp in /home/cheval_8/rendu/Pool_cpp/cpp_gkrellm/includes/display/ncurses
//
// Made by Nicolas Chevalier
// Login   <cheval_8@epitech.net>
//
// Started on  Sun Jan 22 09:05:23 2017 Nicolas Chevalier
// Last update Sun Jan 22 09:05:23 2017 Nicolas Chevalier
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
