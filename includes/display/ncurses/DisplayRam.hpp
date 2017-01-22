//
// Created by cheval_8 on 1/21/17.
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
