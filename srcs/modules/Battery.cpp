//
// Battery.cpp for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm/srcs/modules
// 
// Made by Lucas Debouté
// Login   <debout_l@epitech.net>
// 
// Started on  Sat Jan 21 18:30:37 2017 Lucas Debouté
// Last update Sat Jan 21 18:31:25 2017 Lucas Debouté
//

#include "../../includes/modules/Battery.hpp"

//C&D
Battery::Battery()
{
  this->isEnabled = true;
  this->_blevel = getBatteryLevel();
}

Battery::Battery(Battery const &other)
{
  this->isEnabled = other.isEnabled;
  this->_blevel= other._blevel;
}

Battery &Battery::operator=(Battery const &other)
{
  this->isEnabled = other.isEnabled;
  this->_blevel = other._blevel;
  return *this;
}

int Battery::getBatteryLevel()
{
  int level = 0;
  std::string tmp;

  std::ifstream file(std::string("/sys/class/power_supply/BAT0/capacity"), std::ifstream::in);
  if (file.is_open())
  {
    std::getline(file, tmp);
  }
  level = std::stoi(tmp);
  return (level);
}

//IMonitorModules
bool		Battery::getStatus() const
{ return this->isEnabled; }
std::string		Battery::getName() const
{ return std::string("Battery"); }
std::string		Battery::getDescription() const
{ return std::string("Module who gives the battery level"); }

Battery::~Battery(){}
