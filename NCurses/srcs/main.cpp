#include "../includes/display/ncurses/DisplayBatterie.hpp"
#include "../includes/display/ncurses/DisplayNetwork.hpp"
#include "../includes/display/ncurses/DisplayUser.hpp"
#include "../includes/display/ncurses/DisplayDate.hpp"
#include "../includes/display/ncurses/DisplayRam.hpp"

#include "../includes/modules/Date.hpp"
#include "../includes/modules/Battery.hpp"
#include "../includes/modules/Ram.hpp"
#include "../includes/modules/Cpu.hpp"
#include "../includes/modules/System.hpp"
#include "../includes/modules/User.hpp"

void exec_ncurses()
{

  DisplayRam *ram = new DisplayRam();
  DisplayBatterie *Batterie = new DisplayBatterie();
  DisplayNetwork *network = new DisplayNetwork();
  DisplayUser *user = new DisplayUser();
  DisplayDate *date = new DisplayDate();

  while (1)
    {
      Batterie->run();
      ram->run();
      network->run();
      user->run();
      date->run();
    }

}

int main(int argc, char *argv[])
{
  exec_ncurses();
  return 0;
}
