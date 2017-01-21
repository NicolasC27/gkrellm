#include "../includes/modules/Date.hpp"
#include "../includes/modules/Battery.hpp"
#include "../includes/modules/Ram.hpp"
#include "../includes/modules/Cpu.hpp"
#include "../includes/modules/System.hpp"
#include "../includes/modules/User.hpp"


int main(int argc, char *argv[])
{
  if (argc == 2 &&
      argv[1][0] == '-' &&
      (argv[1][1] == 'T' || argv[1][1] == 'G') &&
      !argv[1][2])
  {

  }
  else
  {
    std::cout << "Error : Bad usage." << std::endl << std::endl <<
                 "Usage : ./gkrellm <displaytype>" << std::endl <<
                 " -G  : Graphical mod" << std::endl <<
                 " -T  : Terminal mod" << std::endl;
  }
}
