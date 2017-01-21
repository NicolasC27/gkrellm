//
// system.cpp for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm/Srcs/Modules
// 
// Made by Lucas Debouté
// Login   <debout_l@epitech.net>
// 
// Started on  Sat Jan 21 11:36:47 2017 Lucas Debouté
// Last update Sat Jan 21 14:43:34 2017 Lucas Debouté
//


#include "../../includes/modules/System.hpp"


//C&D
System::System()
{
  struct utsname uname_s;

  if (uname(&uname_s))
    exit(1);
  std::cout << uname_s.machine << std::endl;
}

System::~System(){}
