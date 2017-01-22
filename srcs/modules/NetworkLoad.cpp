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


  if (!file.good())
    _status = false;
  else
    {
      for (int i = 0; i < 3; ++i)
	std::getline(file, line);

      std::getline(file, line);
      std::istringstream os(line);
      os >> _Iface >> _MTUMET >> _RXOK >> _RXERR >> _RXDRP >> _RXOVR >> _TXOK
	 >> _TXERR >> _TXDRP >> _TXOVR;
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

size_t NetworkLoad::getMTUMET() const
{
  return _MTUMET;
}

size_t NetworkLoad::getRXOK() const
{
  return _RXOK;
}

size_t NetworkLoad::getRXERR() const
{
  return _RXERR;
}

size_t NetworkLoad::getRXDRP() const
{
  return _RXDRP;
}

size_t NetworkLoad::getRXOVR() const
{
  return _RXOVR;
}

size_t NetworkLoad::getTXOK() const
{
  return _TXOK;
}

size_t NetworkLoad::getTXDRP() const
{
  return _TXDRP;
}

size_t NetworkLoad::getTXERR() const
{
  return _TXERR;
}

size_t NetworkLoad::getTXOVR() const
{
  return _TXOVR;
}
