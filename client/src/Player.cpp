/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#include "Player.hpp"
#include <string.h>

Player::Player(Client &client) : c(client), _port(client.getPort()), _idClient(client.getMachineName()),  _level(1), _team(client.getTeam()), _sockPlayer(client.getSock()), _stones(std::vector<int>(6, 0)), _food(0), _currentGoal(LOOKING), _targetTile(0) {
}

Player::Player(const Player &p) : c(p.c), _port(p._port), _idClient(p._idClient), _level(p._level), _team(p._team), _sockPlayer(p._sockPlayer), _stones(p._stones), _food(p._food), _currentGoal(p._currentGoal), _targetTile(p._targetTile) {
}

void Player::parseInventory(std::string inventory) {
  for (size_t i = 0; i < inventory.size(); i++) {
    if (inventory.at(i) == ' ' || inventory.at(i) == '[' || inventory.at(i) == ']')
      inventory.erase(inventory.begin() + i);
  }
  std::vector<std::string> stones;
  std::string stone;
  std::istringstream stoneStream(inventory);
  while (std::getline(stoneStream, stone, ',')) {
      stones.push_back(stone);
  }
  for (size_t i = 0; i < stones.size(); i++) {
    if (stones.at(i).find("food") != std::string::npos) {
      stones.at(i).erase(0, 4);
      _food = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("linemate") != std::string::npos) {
      stones.at(i).erase(0, 8);
      _stones.at(0) = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("deraumere") != std::string::npos) {
      stones.at(i).erase(0, 9);
      _stones.at(1) = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("sibur") != std::string::npos) {
      stones.at(i).erase(0, 5);
      _stones.at(2) = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("mendiane") != std::string::npos) {
      stones.at(i).erase(0, 8);
      _stones.at(3) = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("phiras") != std::string::npos) {
      stones.at(i).erase(0, 6);
      _stones.at(4) = std::stoi(stones.at(i));
    }
    else if (stones.at(i).find("thystame") != std::string::npos) {
      stones.at(i).erase(0, 8);
      _stones.at(5) = std::stoi(stones.at(i));
    }
  }
}

int Player::parseTile(std::string tile) {
  std::vector<std::string> items;
  std::string item;
  std::istringstream itemStream(tile);
  while (std::getline(itemStream, item, ' ')) {
    items.push_back(item);
  }
  int tileValue = 0;
  for (size_t i = 0; i < items.size(); i++) {
    if (items.at(i) == "food")
      tileValue++;
    else if (isStoneNeeded(items.at(i)))
      tileValue++;
  }
  return (tileValue);
}

std::string Player::itemToTake(std::string tile) {
  std::vector<std::string> items;
  std::string item;
  std::istringstream itemStream(tile);
  std::string stone;
  while (std::getline(itemStream, item, ' ')) {
    items.push_back(item);
  }
  for (size_t i = 0; i < items.size(); i++) {
    if (items.at(i) == "food")
      return ("food");
    else if (isStoneNeeded(items.at(i)))
      stone = items.at(i);
  }
  return (stone);
}

std::string Player::parseLook(std::string vision) {
  for (size_t i = 0; i < vision.size(); i++) {
    if (vision.at(i) == '[' || vision.at(i) == ']')
      vision.erase(vision.begin() + i);
  }
  std::vector<std::string> tiles;
  std::string tile;
  std::istringstream tileStream(vision);
  while (std::getline(tileStream, tile, ',')) {
      tiles.push_back(tile);
  }
  int max = 0;
  int tileGoal = 2;
  int tileValue;
  if (parseTile(tiles.at(0)) > 0)
    return (tiles.at(0));
  for (size_t i = 0; i < tiles.size(); i++) {
    tileValue = parseTile(tiles.at(i));
    if (tileValue > max) {
      max = tileValue;
      tileGoal = i;
    }
  }
  _targetTile = tileGoal;
  return ("move" + std::to_string(tileGoal));
}

int Player::getGoal() {
  if (_level == 1)
    return (1);
  else if (_level == 2)
    return (21);
  else if (_level == 3)
    return (530);
  else if (_level == 4)
    return (293);
  else if (_level == 5)
    return (217);
  else if (_level == 6)
    return (313);
  else if (_level == 7)
    return (1706);
  else return (0);
}

bool Player::isStoneNeeded(std::string stone) {
  if (stone == "linemate") {
    if (getGoal() % 4 > _stones.at(0))
      return (true);
  }
  else if (stone == "deraumere") {
    if ((getGoal() % 16 >> 2) > _stones.at(1))
      return (true);
  }
  else if (stone == "sibur") {
    if ((getGoal() % 64 >> 4) > _stones.at(2))
      return (true);
  }
  else if (stone == "mendiane") {
    if ((getGoal() % 256 >> 6) > _stones.at(3))
      return (true);
  }
  else if (stone == "phiras") {
    if ((getGoal() % 1024 >> 8) > _stones.at(4))
      return (true);
  }
  else if (stone == "thystame") {
    if ((getGoal() >> 10) > _stones.at(5))
      return (true);
  }
  return (false);
}

bool Player::isGoalAchieved() {
  if (getGoal() % 4 > _stones.at(0))
      return (false);
  if ((getGoal() % 16 >> 2) > _stones.at(1))
      return (false);
  if ((getGoal() % 64 >> 4) > _stones.at(2))
    return (false);
  if ((getGoal() % 256 >> 6) > _stones.at(3))
    return (false);
  if ((getGoal() % 1024 >> 8) > _stones.at(4))
    return (false);
  if ((getGoal() >> 10) > _stones.at(5))
    return (false);
  return (true);
}


std::string Player::getNextAction(const std::string &anwser) {
  if (_currentGoal == LOOKING) {
    std::string goal = parseLook(anwser);
    if (goal.find("move") != std::string::npos) {
      _currentGoal = MOVING;
      return ("Forward\n");
    }
    else {
      _currentGoal = COLLECTING;
      return ("Take " + itemToTake(goal) + "\n");
    }
  }
  else if (_currentGoal == COLLECTING) {
    if (isGoalAchieved()) {
      _currentGoal = ELEVATING;
      return ("Drop Linemate\n");
    }
    else {
      _currentGoal = LOOKING;
      return ("Look\n");
    }
  }
  else if (_currentGoal == MOVING) {
    if (_targetTile > 4) {
      _currentGoal = NEEDTOLOOK;
      return ("Forward\n");
    }
    else if (_targetTile == 2) {
      _currentGoal = LOOKING;
      return ("Look\n");
    }
    else if (_targetTile == 1) {
      _currentGoal = NEEDTOLOOK;
      return ("Left\n");
    }
    else {
      _currentGoal = NEEDTOLOOK;
      return ("Right\n");
    }
  }
  else if (_currentGoal == ELEVATING) {
    _currentGoal = MOVING;
    return ("Incantation\n");
  }
  else if (_currentGoal == FORKING) {
    _currentGoal = MOVING;
    return ("Fork\n");
  }
  else {
    _currentGoal = LOOKING;
    return ("Look\n");
  }
}

void Player::ForkPlayer() {
  Client cli(c.getPort(), c.getMachineName());
  cli = c.NewClient(c);
  Player p(cli);
  p.run();
}

void Player::run() {
  sendServ();
}

void Player::sendServ() {
  std::string action = "Look\n";
  std::string answer;
  while (1) {
    answer = doFunction(action);
    action = getNextAction(answer);
    std::cout << "To Server :" << action;
  }
}

std::string Player::doFunction(const std::string &action) {
  std::string answer;
  doCommands(action.c_str());
  answer.resize(10000);
  if (write(_sockPlayer, (const void *)action.c_str(), action.size()) != -1) {
    if (read(_sockPlayer, (void *)answer.c_str(), answer.size()) > 0)
      std::cout << "From Server : " << answer;
  }
  return (answer);
}

int Player::setNBlock(int *sck, bool chx)
{
  int flags = fcntl(*sck, F_GETFL);

  if(chx == true)
    fcntl(*sck, F_SETFL, flags | O_NONBLOCK);
  else
    fcntl(*sck, F_SETFL, flags | O_ASYNC);
  return (flags);
}

void Player::doCommands(std::string buff) {
  if (buff == "Fork\n")
    ForkPlayer();
}
