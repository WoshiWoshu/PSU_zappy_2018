/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "Graphics.hpp"
#include "Help.hpp"
#include "Client.hpp"
#include "Player.hpp"

int main(int argc, char const *argv[]) {
  if (argc == 2 && !std::strcmp(argv[1], "-help"))
    Help::usage();
  else if (argc < 5) {
    Help::usage();
    return (84);
  } else {
    if (!Help::checkParams(argc, argv)) {
      Help::usage();
      return (84);
    } else if (argc == 5) {
      Client client(std::atoi(argv[2]), argv[4]);
      client.connectClient();
      Player player(client);
      player.run();
    } else if (argc == 7) {
      Client client(std::atoi(argv[2]), std::string(argv[4]));
      client.setMachineName(argv[6]);
      client.connectClient();
      Player player(client);
      player.run();
    } else if (argc == 8 && !std::strcmp(argv[7], "-g")) {
      Graphics *interface = new Graphics();
      interface->run();
    }
  }
  return (0);
}
