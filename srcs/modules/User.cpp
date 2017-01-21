//
// User.cpp for User.cpp in /home/lacomm_m/cpp_gkrellm/Srcs
// 
// Made by Manon Lacommare
// Login   <lacomm_m@epitech.net>
// 
// Started on  Sat Jan 21 11:34:18 2017 Manon Lacommare
// Last update Sat Jan 21 15:33:02 2017 Manon Lacommare
//

#include "User.hpp"

User::User()
{
  this->name = "User";
  this->desc = "Module machine name and user name";
  this->setUserName();
  this->setMachineName();
}

User::~User() {}

User::User(const User & other)
{
  this->name = other.name;
  this->desc = other.name;
  this->userName = other.getUserName();
  this->machineName = other.getMachineName();
}

User &		User::operator=(const User & other)
{
  if (&other != this)
    {
      this->name = other.name;
      this->desc = other.name;
      this->userName = other.getUserName();
      this->machineName = other.getMachineName();
    }
  return (*this);
}

std::string	User::getName() const
{
  return (this->name);
}

std::string	User::getDesc() const
{
  return (this->desc);
}

bool		User::getStatus() const
{
  return (this->status);
}

std::string	User::getUserName() const
{
  return (this->userName);
}

std::string	User::getMachineName() const
{
  return (this->machineName);
}

void		User::setUserName()
{
  std::ifstream	file;
  std::string	line;
  int		i = 0;

  file.open("/etc/passwd");
  if (file.is_open())
    {
      while (file != '\0')
	{
	  getline(file, line);
	  ++i;
	}
      file.close();
    }
  file.open("/etc/passwd");
  if (file.is_open())
    {
      while (i > 1)
	{
	  getline(file, line);
	  --i;
	}
      file.close();
    }
  i = 0;
  while (line[i] != ':')
    this->userName += line[i++];
}

void 	User::setMachineName()
{
  std::ifstream	file;

  file.open("/etc/hostname");
  if (file.is_open())
    {
      getline(file, this->machineName);
      file.close();
    }
}
