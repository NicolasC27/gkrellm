//
// IMonitorModule.hpp for IMonitorModule in /home/gerard_v/CPP_Pool/cpp_gkrellm/includes/modules
// 
// Made by valentin gerard
// Login   <gerard_v@epitech.net>
// 
// Started on  Sat Jan 21 14:26:37 2017 valentin gerard
// Last update Sat Jan 21 14:49:22 2017 valentin gerard
//

#ifndef __IMONITORMODULE_HPP_
# define __IMONITORMOFULE_HPP_

# include <string>

class IMonitorModule
{
public:
  virtual		~IMonitorModule() {};
  virtual bool		getStatus() = 0;
  virtual std::string	getName() = 0;
};

#endif /* IMONITORMODULE_HPP_ */
