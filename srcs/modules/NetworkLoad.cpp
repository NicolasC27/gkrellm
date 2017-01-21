//
// Created by cheval_8 on 1/21/17.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include "../../includes/modules/NetworkLoad.hpp"

NetworkLoad::NetworkLoad() : _status(true)
{}


NetworkLoad::~NetworkLoad()
{

}

void NetworkLoad::update()
{
  std::ifstream file("/proc/net/dev", std::ifstream::in);
  std::string line;
  t_data tmp;


  if (!file.good())
    _status = false;
  else
    {
      for (int i = 0; i < 2; ++i)
	std::getline(file, line);

      while (!file.eof() && std::getline(file, line))
	{
	  std::istringstream os(line);
	  os >> tmp._Iface >> tmp._MTUMET >> tmp._RXDRP >> tmp._RXERR >> tmp._RXOK >> tmp._RXOVR >> tmp._TXDRP
	     >> tmp._TXERR >> tmp._TXOK >> tmp._TXOVR;
	  _info.push_front(tmp);
	}
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

const std::list<NetworkLoad::Data> &NetworkLoad::getInfo() const
{
  return _info;
}

int main()
{
  NetworkLoad *test;

  test->update();
}