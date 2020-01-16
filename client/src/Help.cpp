/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Help
*/

#include "Help.hpp"

#include <iostream>
#include <cstring>

Help::Help() {
}

Help::~Help() {
}

void Help::usage() {
  std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
  std::cout << "\tport\tis the port number" << std::endl;
  std::cout << "\tname\tis the name of the team" << std::endl;
  std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

bool Help::checkParams(int ac, const char **av) {
  if (std::strcmp(av[1], "-p") || std::strcmp(av[3], "-n"))
    return (false);
  else if (ac == 5)
    return (true);
  else if (ac == 6)
    return (false);
  else {
    if (std::strcmp(av[5], "-h"))
      return (false);
  }
  return (true);
}
