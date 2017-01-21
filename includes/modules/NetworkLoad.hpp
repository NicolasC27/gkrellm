//
// Created by cheval_8 on 1/21/17.
//
#ifndef CPP_GKRELLM_NETWORKLOAD_H
#define CPP_GKRELLM_NETWORKLOAD_H

#include <list>
#include "IMonitorModule.hpp"

#define NETWORK_MODULE_NAME "Network"
#define NETWORK_MODULE_DESC "Network load"

class NetworkLoad : public IMonitorModule
{
 private:
  typedef struct Data
  {
    std::string _Iface;

    size_t _MTUMET;

    size_t _RXOK;
    size_t _RXERR;
    size_t _RXDRP;
    size_t _RXOVR;

    size_t _TXOK;
    size_t _TXDRP;
    size_t _TXERR;
    size_t _TXOVR;
  } t_data;

  std::list<Data>	_info;
  bool			_status;

 public:

  NetworkLoad();

  virtual ~NetworkLoad();

  bool getStatus() const;

  std::string getName() const;

  std::string getDescription() const;

  const std::list<Data> &getInfo() const;

  void update();

};


#endif //CPP_GKRELLM_NETWORKLOAD_H
