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

  int	receive_bytes;
  int 	receive_packets;
  int 	trans_bytes;
  int 	trans_packet;
  bool _status;

 public:

  NetworkLoad();

  virtual ~NetworkLoad();

  bool getStatus() const;

  std::string getName() const;

  std::string getDescription() const;

  void update();

  const std::string &getIface() const;

  int getReceive_bytes() const;

  int getReceive_packets() const;

  int getTrans_bytes() const;

  int getTrans_packet() const;


};


#endif //CPP_GKRELLM_NETWORKLOAD_H
