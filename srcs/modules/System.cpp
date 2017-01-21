//
// system.cpp for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm/Srcs/Modules
// 
// Made by Lucas Debouté
// Login   <debout_l@epitech.net>
// 
// Started on  Sat Jan 21 11:36:47 2017 Lucas Debouté
// Last update Sat Jan 21 15:34:47 2017 Lucas Debouté
//


#include "../../includes/modules/System.hpp"


//C&D
System::System()
{
  this->isEnabled = true;
  this->_vkernel = getVersion();
  this->_osname = getOSVersion();
}

std::string System::getVersion()
{
  std::string version;

  std::ifstream file(std::string("/proc/sys/kernel/osrelease"), std::ifstream::in);
  if (file.is_open()) { std::getline(file, version); }
  else { this->isEnabled = false; }

  return (version);
}

std::string System::getOSVersion()
{
  int i = 0;
  std::string version;

  std::ifstream file(std::string("/etc/os-release"), std::ifstream::in);
  if (file.is_open())
  {
    while (file.good() && version.find("VERSION") != 0)
    {
      std::getline(file, version);
    }
  }
  else { this->isEnabled = false; }
  version = version.substr(9, version.find("\"") +6);
  return (version);
}

//IMonitorModules
bool		System::getStatus() const
{ return this->isEnabled; }
std::string		System::getName() const
{ return std::string("System"); }
std::string		System::getDescription() const
{ return std::string("Module who contains os & kernel versions."); }

System::~System(){}
