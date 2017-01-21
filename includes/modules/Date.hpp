//
// Date.hpp for Date in /home/gerard_v/CPP_Pool/cpp_gkrellm/includes/modules
// 
// Made by valentin gerard
// Login   <gerard_v@epitech.net>
// 
// Started on  Sat Jan 21 15:17:01 2017 valentin gerard
// Last update Sat Jan 21 15:17:02 2017 valentin gerard
//

#ifndef __DATE_HPP_
# define __DATE_HPP_

#include "../../includes/modules/IMonitorModule.hpp"

class Date : public IMonitorModule
  {
  private:
    std::string _date;
    std::string _name;
    std::string _description;
    bool        _isEnable;

  public:
    Date();
    Date(const Date&);
    Date& operator=(const Date&);
    virtual ~Date();

    virtual bool         getStatus() const;
    void         setStatus(bool status);
    virtual std::string  getName() const;
    virtual std::string  getDescription() const;
    std::string  getDate() const;
    void         setDate(std::string date);
  };

#endif /* DATE_HPP */
