//
// Date.cpp for Date in /home/gerard_v/CPP_Pool/cpp_gkrellm/srcs/modules
// 
// Made by valentin gerard
// Login   <gerard_v@epitech.net>
// 
// Started on  Sat Jan 21 15:17:16 2017 valentin gerard
// Last update Sat Jan 21 15:17:16 2017 valentin gerard
//

#include <iostream>
#include <ctime>
#include "../../includes/modules/Date.hpp"

static std::string getTime()
{
   time_t now = time(0);
   char* dt = ctime(&now);
   return dt;
}

Date::Date() : _date(getTime()), _name("Date"), _description("Date and Time module"), _isEnable(true) {}

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

std::string Date::getDate() const
{
  return this->_date;
}

void Date::setDate(std::string date)
{
  this->_date = date;
}
