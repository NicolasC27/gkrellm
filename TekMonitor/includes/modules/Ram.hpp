//
// Ram.hpp for Ram.hpp in /home/lacomm_m/cpp_gkrellm/Includes/Modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 12:14:00 2017 Manon Lacommare
// Last update Sun Jan 22 09:52:11 2017 valentin gerard
//

#ifndef RAM_HPP_
# define RAM_HPP_

# include "../../includes/modules/IMonitorModule.hpp"
# include <iostream>
# include <string>
# include <fstream>

class			Ram : public IMonitorModule
{
  std::string		name;
  std::string		desc;
  bool			status;
  int			totalRam;
  int			availRam;
  int			occupRam;

public:
  Ram();
  virtual ~Ram();
  Ram(const Ram &);
  Ram &			operator=(const Ram &);

  virtual std::string	getName() const;
  virtual std::string	getDescription() const;
  virtual bool		getStatus() const;
  int			getTotalRam() const;
  int			getAvailRam() const;
  int			getOccupRam() const;
  void			setTotalRam();
  void			setAvailRam();
  void			setOccupRam();
};

#endif /* !__RAM_HPP__ */
