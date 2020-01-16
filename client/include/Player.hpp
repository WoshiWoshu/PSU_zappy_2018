/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "Client.hpp"
#include <strings.h>
#include <cstring>
#include "Inventory.hpp"
#include <cmath>

class Player {
  public:
    typedef enum goal {
        COLLECTING = 0,
        MOVING = 1,
        LOOKING = 2,
        ELEVATING = 3,
        FORKING = 4,
        NEEDTOLOOK = 5
    } goal_t;
    Player(Client&);
    Player(const Player&);
    Player operator=(const Player&);
    ~Player(){};
    void searchFood();
    void execCommands();
    void ForkPlayer();
    void run();
    void move();
    void parseInventory(std::string);
    std::string parseLook(std::string);
    int parseTile(std::string);
    std::string itemToTake(std::string);
    int getGoal();
    bool isStoneNeeded(std::string);
    bool isGoalAchieved();
    std::string getNextAction(const std::string &);
    std::string getTeam() const { return _team; };
    int getLevel() const { return _level; };
    std::vector<int> getStones() const { return _stones; };
    void sendServ();
    std::string doFunction(const std::string &);
    int setNBlock(int*, bool);
    void doCommands(std::string);
  private:
    Client c;
    int _port;
    std::string _idClient;
    int _level;
    std::string _team;
    int _sockPlayer;
    std::vector<int> _stones;
    int _food;
    goal_t _currentGoal;
    int _targetTile;
};

#endif
