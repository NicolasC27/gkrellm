//
// Cpu.cpp for Cpu.cpp in /home/lacomm_m/cpp_gkrellm/srcs/modules
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 17:20:38 2017 Manon Lacommare
// Last update Sun Jan 22 06:57:56 2017 Manon Lacommare
//

#include "../../includes/modules/Cpu.hpp"

Cpu::Cpu()
{
  this->name = "Cpu";
  this->desc = "CPU information";
  this->status = true;
  this->setModel();
  this->setFrequency();
  this->setNbCores();
  this->setNbCpu();
  this->cpu.resize(this->getNbCpu());
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
  this->cpu = other.cpu;
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
      this->cpu = other.cpu;
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

int		Cpu::getNbCpu() const
{
  return (this->nbCpu);
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

void		Cpu::setNbCpu()
{
  std::ifstream	file;
  std::string	line;
  int		i = -1;

  file.open("/proc/stat");
  if (file.is_open())
    {
      while (getline(file, line))
	{
	  if (line.find("cpu") != line.npos)
	    ++i;
	}
      file.close();
    } 
  this->nbCpu = i;
}
void		Cpu::setActivity()
{
  this->setNbCpu();
  for (int i = this->getNbCpu(); i > 0; --i)
    {
      setPrevParams(i);
      do
	{
	  std::this_thread::sleep_for(std::chrono::milliseconds(200));
	  setParams(i);
	}
      while ((this->total == this->prevtotal) || (this->val == this->prevval));
      this->cpu[i] = (this->val - this->prevval) / (this->total - this->prevtotal) * 100;
    }
}

void		Cpu::setPrevParams(int nbline)
{
  std::ifstream	file;
  std::string	line;
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
      this->prevtotal = (double)atol(line.substr(0, line.find(" ")).c_str());
      line = line.substr(line.find(" ") + 1, line.size());
      this->prevtotal += (double)atol(line.substr(0, line.find(" ")).c_str());
      line = line.substr(line.find(" ") + 1, line.size());
      this->prevval = this->prevtotal += (double)atol(line.substr(0, line.find(" ")).c_str());
      i = 0;
      while (i <= 6)
	{
	  line = line.substr(line.find(" ") + 1, line.size());
	  this->prevtotal += (double)atol(line.substr(0, line.find(" ")).c_str());
	  ++i;
	}
    }
}

void		Cpu::setParams(int nbline)
{
  std::ifstream	file;
  std::string	line;
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
      this->total = (double)atol(line.substr(0, line.find(" ")).c_str());
      line = line.substr(line.find(" ") + 1, line.size());
      this->total += (double)atol(line.substr(0, line.find(" ")).c_str());
      line = line.substr(line.find(" ") + 1, line.size());
      this->val = this->total += (double)atol(line.substr(0, line.find(" ")).c_str());
      i = 0;
      while (i <= 6)
	{
	  line = line.substr(line.find(" ") + 1, line.size());
	  this->total += (double)atol(line.substr(0, line.find(" ")).c_str());
	  ++i;
	}
    }
}
