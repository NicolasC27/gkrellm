//
// Ram.hpp for Ram.hpp in /home/lacomm_m/cpp_gkrellm/Includes/Modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 12:14:00 2017 Manon Lacommare
// Last update Sat Jan 21 16:53:00 2017 Manon Lacommare
//

#ifndef RAM_HPP_
# define RAM_HPP_
# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

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
  ~Ram();
  Ram(const Ram &);
  Ram &			operator=(const Ram &);

  std::string		getName() const;
  std::string		getDesc() const;
  bool			getStatus() const;
  int			getTotalRam() const;
  int			getAvailRam() const;
  int			getOccupRam() const;
  void			setTotalRam();
  void			setAvailRam();
  void			setOccupRam();
};

#endif /* !__RAM_HPP__ */
