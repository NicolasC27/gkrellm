//
// Battery.hpp for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm/includes/modules
// 
// Made by Lucas Debouté
// Login   <debout_l@epitech.net>
// 
// Started on  Sat Jan 21 18:35:53 2017 Lucas Debouté
// Last update Sat Jan 21 18:35:58 2017 Lucas Debouté
//

#ifndef BATTERY_HPP
# define BATTERY_HPP

# include "../../includes/modules/IMonitorModule.hpp"
# include <string>
# include <iostream>
# include <fstream>

class Battery : public IMonitorModule
{
private:
  int _blevel;
  bool isEnabled;

public:
  Battery();
  Battery(Battery const &other);
  Battery &operator=(Battery const &other);
  virtual ~Battery();

  int getBatteryLevel();

  virtual bool		getStatus() const;
  virtual std::string	getName() const;
  virtual std::string   getDescription() const;
};

#endif // BATTERY_HPP
