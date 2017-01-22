//
// User.hpp for User.hpp in /home/lacomm_m/cpp_gkrellm/includes/modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 11:41:03 2017 Manon Lacommare
// Last update Sat Jan 21 22:21:03 2017 valentin gerard
//

#ifndef USER_HPP_
# define USER_HPP_

# include "../../includes/modules/IMonitorModule.hpp"
# include <iostream>
# include <string>
# include <fstream>

class			User : public IMonitorModule
{
  bool			status;
  std::string		name;
  std::string		desc;
  std::string		userName;
  std::string		machineName;

public:
  User();
  virtual ~User();
  User(const User &);
  User &		operator=(const User &);

  virtual std::string	getName() const;
  virtual std::string	getDescription() const;
  virtual bool		getStatus() const;  
  std::string		getUserName() const;
  std::string		getMachineName() const;
  void			setUserName();
  void			setMachineName();
};

#endif /* !__USER_HPP__ */
