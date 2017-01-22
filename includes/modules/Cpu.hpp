//
// Cpu.hpp for Cpu.hpp in /home/lacomm_m/cpp_gkrellm/includes/modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 16:57:15 2017 Manon Lacommare
// Last update Sun Jan 22 02:48:02 2017 Manon Lacommare
//

#ifndef CPU_HPP_
# define CPU_HPP_
# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <thread>
# include <chrono>
# include "IMonitorModule.hpp"

class			Cpu : public IMonitorModule
{
  std::string		name;
  std::string		desc;
  bool			status;
  std::string		model;
  float			frequency;
  int			nbCores;
  int			prevtotal;
  int			previdle;
  int			total;
  int			idle;
  float			cpu1;
  float			cpu2;
  float			cpu3;
  float			cpu4;

public:
  Cpu();
  virtual ~Cpu();
  Cpu(const Cpu &);
  Cpu &			operator=(const Cpu &);

  virtual std::string	getName() const;
  virtual std::string	getDescription() const;
  virtual bool		getStatus() const;
  std::string		getModel() const;
  float			getFrequency() const;
  int			getNbCores() const;
  float			getActivity() const;
  void			setModel();
  void			setFrequency();
  void			setNbCores();
  void			setActivity();
  void			setPrevParams(int);
  void			setParams(int);
};

# endif /* !__CPU_HPP__ */
