/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Client
*/

#include "Client.hpp"
#include <cstring>

Client::Client(unsigned int port, std::string name) :
_port(port), _name(name), _machineName("127.0.0.1"), sockfd(0) , servaddr() , _c(0), is_egg(false) , _pid(getpid()){
  std::memset(&servaddr,0, sizeof(servaddr));
}

Client Client::NewClient(Client a) {
  Client client = a; 

  client.createEgg();
  fork();
  _pid = getpid();
  client.connectClient();
  return (client);
}

Client::~Client() {
}

void Client::connectClient() {
  char buff[MAX] = {0};
  int valread = 0;

  this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    std::cout << "Socket creation failed...\n";
    exit(84);
  } else
    std::cout << "Socket successfully created..\n";
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(_machineName.c_str());
  servaddr.sin_port = htons(_port);
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
    std::cout << "Connection with the server failed...\n";
    exit(84);
  } else
    std::cout << "Connected to the server...\n";
  valread = read(sockfd, buff, MAX);
  std::cout << buff << _name.c_str() << "\n";
  static_cast<void>(valread);
  bzero(buff, sizeof(buff));
  std::strcat(buff, _name.c_str());
  std::strcat(buff, "\n");
  send(sockfd, buff, sizeof(buff), 0);
  bzero(buff, sizeof(buff));
  read(sockfd, buff, sizeof(buff));
  std::cout << "From Server : " << buff;
  bzero(buff, sizeof(buff));
  usleep(0.1);
  read(sockfd, buff, sizeof(buff));
  std::cout << "From Server : " << buff;
  bzero(buff, sizeof(buff));
}

std::string Client::getTeam() {
  return (this->_name);
}

int Client::ParseAtChar(std::string a, char c) {
  for (unsigned i = 0; i < a.length(); i++)
    if (a.at(i) == c)
      return (i);
  return (-1);
}

void Client::createEgg()
{
  this->is_egg = true;
}
