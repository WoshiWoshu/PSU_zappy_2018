/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

static const char TILE_MAP_PATH[] = "MapTileSet.png";
static const char BOARD_INVENTORY_PATH[] = "boardInventory.png";
static const char GEMS_INVENTORY_PATH[] = "gemsInventory.png";
static const char TEXT_FONT_PATH[] = "south park.ttf";

class Graphics {
  public:
    inline Graphics() : _window(sf::VideoMode(1920, 1080),
    "Zappy", sf::Style::Default) {};
    virtual ~Graphics() = default;
    void run();
    class Utility {
    public:
        virtual ~Utility() = default;
        std::string concatClientPath(const std::string &filePathCurr);
    };
  private:
    sf::RenderWindow _window;
};
#endif
