//
// Created by cheval_8 on 1/21/17.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include "../../includes/modules/NetworkLoad.hpp"

NetworkLoad::NetworkLoad() : _status(true)
{

}


NetworkLoad::~NetworkLoad()
{

}

void NetworkLoad::update()
{
  std::ifstream file("/proc/net/dev", std::ifstream::in);
  std::string line;

  size_t nothing;

  if (!file.good())
    _status = false;
  else
    {
      for (int i = 0; i < 3; ++i)
	std::getline(file, line);

      std::getline(file, line);
      std::istringstream os(line);
      os >> _Iface >> receive_bytes >> receive_packets >> nothing >> nothing >> nothing >> nothing >> nothing >> nothing
	 >> trans_bytes >> trans_packet;
    }
}


bool NetworkLoad::getStatus() const
{
  return _status;
}

std::string NetworkLoad::getName() const
{
  return std::string(NETWORK_MODULE_NAME);
}

std::string NetworkLoad::getDescription() const
{
  return std::string(NETWORK_MODULE_DESC);
}

const std::string &NetworkLoad::getIface() const
{
  return _Iface;
}

int NetworkLoad::getReceive_bytes() const
{
  return receive_bytes;
}

int NetworkLoad::getReceive_packets() const
{
  return receive_packets;
}

int NetworkLoad::getTrans_bytes() const
{
  return trans_bytes;
}

int NetworkLoad::getTrans_packet() const
{
  return trans_packet;
}