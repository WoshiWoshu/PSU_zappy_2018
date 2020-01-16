/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>
#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sstream>

#define MAX 80

class Client {
public:
  Client(unsigned int, std::string);
  Client NewClient(Client);
  ~Client();
  unsigned int getPort() const { return (_port); };
  std::string getName() const { return (_name); };
  std::string getMachineName() const { return (_machineName); };
  void setMachineName(const std::string mn) { if (mn == "localhost") {_machineName = "127.0.0.1";} else {_machineName = mn;}};
  void connectClient();
  std::string getTeam();
  int ParseAtChar(std::string, char);
  int getSock() {return sockfd;};
  void createEgg();

private:
  unsigned int _port;
  std::string _name;
  std::string _machineName;
  int sockfd;
  struct sockaddr_in servaddr;
  int _c;
  bool is_egg;
  pid_t _pid;
};

#endif /* !CLIENT_HPP_ */
