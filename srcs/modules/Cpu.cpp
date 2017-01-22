//
// Cpu.cpp for Cpu.cpp in /home/lacomm_m/cpp_gkrellm/srcs/modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 17:20:38 2017 Manon Lacommare
// Last update Sun Jan 22 02:48:35 2017 Manon Lacommare
//

#include "Cpu.hpp"

Cpu::Cpu()
{
  this->name = "Cpu";
  this->desc = "CPU information";
  this->status = true;
  this->setModel();
  this->setFrequency();
  this->setNbCores();
  this->setActivity();
}

Cpu::~Cpu() {}

Cpu::Cpu(const Cpu & other)
{
  this->name = other.name;
  this->desc = other.desc;
  this->status = other.status;
  this->model = other.getModel();
  this->frequency = other.getFrequency();
  this->nbCores = other.getNbCores();
  this->cpu1 = other.getActivity();
  this->cpu2 = other.getActivity();
  this->cpu3 = other.getActivity();
  this->cpu4 = other.getActivity();
}

Cpu &		Cpu::operator=(const Cpu & other)
{
  if (&other != this)
    {
      this->name = other.name;
      this->desc = other.desc;
      this->status = other.status;
      this->model = other.getModel();
      this->frequency = other.getFrequency();
      this->nbCores = other.getNbCores();
      this->cpu1 = other.getActivity();
      this->cpu2 = other.getActivity();
      this->cpu3 = other.getActivity();
      this->cpu4 = other.getActivity();
    }
  return (*this);
}

std::string	Cpu::getName() const
{
  return (this->name);
}

std::string	Cpu::getDescription() const
{
  return (this->desc);
}

bool		Cpu::getStatus() const
{
  return (this->status);
}

std::string	Cpu::getModel() const
{
  return (this->model);
}

float		Cpu::getFrequency() const
{
  return (this->frequency);
}

int		Cpu::getNbCores() const
{
  return (this->nbCores);
}

float		Cpu::getActivity() const
{
  return (this->cpu1);
}

void		Cpu::setModel()
{
  std::ifstream	file;
  std::string	line;

  file.open("/proc/cpuinfo");
  if (file.is_open())
    {
      while (file.good() && line.find("model name") != 0)
	getline(file, line);
      line = line.substr(13, line.size() - 13);
      this->model = line;
      file.close();
    }
}

void		Cpu::setFrequency()
{
  std::ifstream	file;
  std::string	line;

  file.open("/proc/cpuinfo");
  if (file.is_open())
    {
      while (file.good() && line.find("cpu MHz") != 0)
	getline(file, line);
      line = line.substr(11, line.size() - 11);
      this->frequency = atof(line.c_str());
      file.close();
    }
}

void		Cpu::setNbCores()
{
  std::ifstream	file;
  std::string	line;

  file.open("/proc/cpuinfo");
  if (file.is_open())
    {
      while (file.good() && line.find("cpu cores") != 0)
	getline(file, line);
      line = line.substr(12, line.size() - 12);
      this->nbCores = atoi(line.c_str());
      file.close();
    }
}

void		Cpu::setActivity()
{
  setPrevParams(1);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  setParams(1);
  this->cpu1 = 100 * ((this->total - this->prevtotal) - (this->idle - this->previdle)) / (this->total - this->prevtotal);
  
  setPrevParams(2);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  setParams(2);
  this->cpu2 = 100 * ((this->total - this->prevtotal) - (this->idle - this->previdle)) / (this->total - this->prevtotal);

  setPrevParams(3);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  setParams(3);
  this->cpu3 = 100 * ((this->total - this->prevtotal) - (this->idle - this->previdle)) / (this->total - this->prevtotal);

  setPrevParams(4);
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  setParams(4);
  this->cpu4 = 100 * ((this->total - this->prevtotal) - (this->idle - this->previdle)) / (this->total - this->prevtotal);
}

void		Cpu::setPrevParams(int nbline)
{
  std::ifstream	file;
  std::string	line;
  std::string	user;
  std::string	nice;
  std::string	sys;
  std::string	idle;
  int		total;
  int		i = 0;

  file.open("/proc/stat");
  if (file.is_open())
    {
      while (i <= nbline)
	{
	  getline(file, line);
	  ++i;
	}
      line = line.substr(5, line.size() - 5);
      user = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      nice = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      sys = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      idle = line.substr(0, line.find(" "));
      file.close();
    }
  total = atoi(user.c_str()) + atoi(nice.c_str()) + atoi(sys.c_str()) + atoi(idle.c_str());
  this->previdle = atoi(idle.c_str());
  this->prevtotal = total;
}

void		Cpu::setParams(int nbline)
{
  std::ifstream	file;
  std::string	line;
  std::string	user;
  std::string	nice;
  std::string	sys;
  std::string	idle;
  int		total;
  int		i = 0;

  file.open("/proc/stat");
  if (file.is_open())
    {
      while (i <= nbline)
	{
	  getline(file, line);
	  ++i;
	}
      line = line.substr(5, line.size() - 5);
      user = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      nice = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      sys = line.substr(0, line.find(" "));
      line = line.substr(line.find(" ") + 1, line.size());
      idle = line.substr(0, line.find(" "));
      file.close();
    }
  total = atoi(user.c_str()) + atoi(nice.c_str()) + atoi(sys.c_str()) + atoi(idle.c_str());
  this->idle = atoi(idle.c_str());
  this->total = total;
}
