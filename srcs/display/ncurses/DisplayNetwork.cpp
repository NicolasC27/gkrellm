//
// Created by cheval_8 on 1/21/17.
//
#include "../../../includes/display/ncurses/DisplayNetwork.hpp"
#include "../../../includes/modules/Ram.hpp"
#include "../../../includes/modules/NetworkLoad.hpp"
#include <iomanip>
#include <zconf.h>
#include <sstream>

DisplayNetwork::DisplayNetwork() : Ncurses(), _status(true)
{
  window = newwin(7, 70, 10, 0);
}

DisplayNetwork::~DisplayNetwork()
{
  setEndwin();
}

void DisplayNetwork::run()
{
  NetworkLoad network;

  network.update();
  setWclear(window);
  setBox(window, 0, 0);
  setWmove(window, 2, 1);
  setWprintw(window, "Reseaux: ");
  setWprintw(window, network.getIface().c_str());
  setWmove(window, 3, 1);
  setWprintw(window, "Receive bytes    ");
  setWprintw(window, "Receive packet    ");
  setWprintw(window, "Trans packet    ");
  setWprintw(window, "Trans bytes    ");
  setWmove(window, 4, 1);
  setWprintw(window, " ");
  setWprintw(window, std::to_string(network.getReceive_bytes()).c_str());
  setWprintw(window, "           ");
  setWprintw(window, std::to_string(network.getReceive_packets()).c_str());
  setWprintw(window, "          ");
  setWprintw(window, std::to_string(network.getTrans_packet()).c_str());
  setWprintw(window, "          ");
  setWprintw(window, std::to_string(network.getTrans_bytes()).c_str());

  setWrefresh(window);
  usleep(SLEEP);
}


DisplayType DisplayNetwork::getType() const
{
  return DisplayType::NCURSES;
}

bool DisplayNetwork::getStatus()
{
  return _status;
}

std::string DisplayNetwork::getDisplayName()
{
  return std::string(DISPLAYNETWORK_MODULE_NAME);
}

int DisplayNetwork::getSize()
{
  return 0;
}
