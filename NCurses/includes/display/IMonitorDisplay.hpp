//
// IMonitorDisplay.hpp for IMonitorDisplay in /home/gerard_v/CPP_Pool/cpp_gkrellm/includes/display
// 
// Made by valentin gerard
// Login   <gerard_v@epitech.net>
// 
// Started on  Sat Jan 21 14:27:11 2017 valentin gerard
// Last update Sat Jan 21 15:09:06 2017 valentin gerard
//

#ifndef __IMONITORDISPLAY_HPP_
# define __IMONITORDISPLAY_HPP_

#define SLEEP 5000
enum DisplayType
  {
    QT,
    NCURSES
  };

class IMonitorDisplay
{
public:
  virtual		~IMonitorDisplay() {}
  virtual DisplayType	getType() const = 0;
  virtual bool		getStatus() = 0;
  virtual std::string	getDisplayName() = 0;
  virtual int		getSize() = 0;
};

#endif /* !__IMONITORDISPLAY_HPP_ */
