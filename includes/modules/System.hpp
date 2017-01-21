//
// system.hpp for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm/Includes/Modules
// 
// Made by Lucas Debouté
// Login   <debout_l@epitech.net>
// 
// Started on  Sat Jan 21 11:42:42 2017 Lucas Debouté
// Last update Sat Jan 21 11:42:43 2017 Lucas Debouté
//

#ifndef SYSTEM_HPP
# define SYSTEM_HPP

# include "../../includes/modules/IMonitorModule.hpp"
# include <string>
# include <iostream>
# include <fstream>

class System : public IMonitorModule
{
private:
  std::string _vkernel;
  std::string _osname;
  bool isEnabled;


public:
  System();
  virtual ~System();

  std::string getVersion();
  std::string getOSVersion();

  virtual bool		getStatus() const;
  virtual std::string	getName() const;
  virtual std::string   getDescription() const;
};

#endif // SYSTEM_HPP
