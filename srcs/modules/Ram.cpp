//
// Ram.cpp for Ram.cpp in /home/lacomm_m/cpp_gkrellm/Srcs
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 12:13:43 2017 Manon Lacommare
// Last update Sat Jan 21 16:50:23 2017 Manon Lacommare
//

#include "../../includes/modules/Ram.hpp"

Ram::Ram()
{
  this->name = "Ram";
  this->desc = "RAM informations";
  this->status = true;
  this->setTotalRam();
  this->setAvailRam();
  this->setOccupRam();
}

Ram::~Ram() {}

Ram::Ram(const Ram & other)
{
  this->name = other.name;
  this->desc = other.desc;
  this->status = other.status;
  this->totalRam = other.getTotalRam();
  this->availRam = other.getAvailRam();
  this->occupRam = other.getOccupRam();
}

Ram &		Ram::operator=(const Ram & other)
{
  if (&other != this)
    {
      this->name = other.name;
      this->status = other.status;
      this->totalRam = other.getTotalRam();
      this->availRam = other.getAvailRam();
      this->occupRam = other.getOccupRam();
    }
  return (*this);
}

std::string	Ram::getName() const
{
  return (this->name);
}

std::string	Ram::getDesc() const
{
  return (this->desc);
}

bool		Ram::getStatus() const
{
  return (this->status);
}

int		Ram::getTotalRam() const
{
  return (this->totalRam);
}

int		Ram::getAvailRam() const
{
  return (this->availRam);
}

int		Ram::getOccupRam() const
{
  return (this->occupRam);
}

void		Ram::setTotalRam()
{
  std::ifstream	file;
  std::string	line;
  std::string	nb;
  int		i = 0;

  file.open("/proc/meminfo");
  if (file.is_open())
    {
      getline(file, line);
      file.close();
    }
  while (line[i] != '\0')
    {
      if (line[i] >= 48 && line[i] <= 57)
	nb += line[i];
      ++i;
    }
  this->totalRam = std::atoi(nb.c_str());
}

void		Ram::setAvailRam()
{
  std::ifstream	file;
  std::string	line;
  std::string	nb;
  int		i = 0;

  file.open("/proc/meminfo");
  if (file.is_open())
    {
      getline(file, line);
      getline(file, line);
      getline(file, line);
      file.close();
    }
  while (line[i] != '\0')
    {
      if (line[i] >= 48 && line[i] <= 57)
	nb += line[i];
      ++i;
    }
  this->availRam = std::atoi(nb.c_str());
}

void		Ram::setOccupRam()
{
  this->occupRam = this->getTotalRam() - this->getAvailRam();
}
