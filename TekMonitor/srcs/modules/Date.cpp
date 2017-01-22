//
// Date.cpp for Date in /home/gerard_v/CPP_Pool/cpp_gkrellm/srcs/modules
// 
// Made by valentin gerard
// Login   <gerard_v@epitech.net>
// 
// Started on  Sat Jan 21 15:17:16 2017 valentin gerard
// Last update Sun Jan 22 09:53:25 2017 valentin gerard
//

#include <iostream>
#include <string>
#include <fstream>
#include "../../includes/modules/Date.hpp"

Date::Date() : _date(getDate()), _time(getTime()), _name("Date"), _description("Date and Time module"), _isEnable(true) {}

Date::Date(const Date &other)
{
  this->_date = other._date;
  this->_description = other._description;
  this->_isEnable = other._isEnable;
}

Date& Date::operator=(const Date &other)
{
  if (&other != this)
    {
      this->_date = other._date;
      this->_description = other._description;
      this->_isEnable = other._isEnable;
    }
  return *this;
}

Date::~Date() {}

std::string Date::getName() const
{
  return this->_name;
}

bool Date::getStatus() const
{
  return this->_isEnable;
}

void Date::setStatus(bool status)
{
  this->_isEnable = status;
}

std::string Date::getDescription() const
{
  return this->_description;
}

std::string Date::getDate()
{
  std::string tmp;

  std::ifstream file(std::string("/proc/driver/rtc"), std::ifstream::in);
  if (file.is_open())
  {
    while (file.good() && tmp.find("rtc_date") != 0)
    {
      std::getline(file, tmp);
    }
  }
  else { this->setStatus(false); }
  tmp = tmp.substr(tmp.find(":") + 2);
  return (tmp);
}


std::string Date::getTime()
{
  std::string tmp;

  std::ifstream file(std::string("/proc/driver/rtc"), std::ifstream::in);
  if (file.is_open())
  {
    while (file.good() && tmp.find("rtc_time") != 0)
    {
      std::getline(file, tmp);
    }
  }
  else { this->setStatus(false); }
  tmp = tmp.substr(tmp.find(":") + 2);
  return (tmp);
}

void Date::setDate(std::string date)
{
  this->_date = date;
}
