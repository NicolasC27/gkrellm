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

  bool _status;

 public:

  NetworkLoad();

  virtual ~NetworkLoad();

  bool getStatus() const;

  std::string getName() const;

  std::string getDescription() const;

  void update();

  const std::string &getIface() const;

  size_t getMTUMET() const;

  size_t getRXOK() const;

  size_t getRXERR() const;

  size_t getRXDRP() const;

  size_t getRXOVR() const;

  size_t getTXOK() const;

  size_t getTXDRP() const;

  size_t getTXERR() const;

  size_t getTXOVR() const;
};


#endif //CPP_GKRELLM_NETWORKLOAD_H
