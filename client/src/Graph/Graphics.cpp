/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#include <SFML/Window.hpp>
#include <unistd.h>
#include "Graphics.hpp"

#include "Character.hpp"
#include "Map.hpp"
#include "InventoryGraph.hpp"
#include "Resources.hpp"

void Graphics::run()
{
    sf::Event event;
    Map map;
    InventoryGraph inventory;
    Resources resources;
    Character c("cartman", 1536, 0);
    Character c2("kenny", 804, 128);
    Character c3("kyle", 1144, 512);
    Character c4("philip", 0, 448);
    Character c5("stan", 1592, 796);
    Character c6("terence", 512, 1024);

    map.createMap(60, 34);
    inventory.createItems();
    resources.createItems(60, 34);
    _window.setFramerateLimit(60);
    while (_window.isOpen()) {
        while (_window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                _window.close();
        _window.clear();
        inventory.updateItems("Food", "100");
        resources.updateItems();
        //c.move(50, 40);
        _window.draw(map);
        _window.draw(resources);
        _window.draw(inventory);
        _window.draw(c);
        _window.draw(c2);
        _window.draw(c3);
        _window.draw(c4);
        _window.draw(c5);
        _window.draw(c6);
        _window.display();
    }
}

std::string Graphics::Utility::concatClientPath(const std::string &filePathCurr)
{
    char filePathTmp[100] = {0};
    std::string filePathNew("");

    getcwd(filePathTmp, sizeof(filePathTmp));
    filePathNew = filePathTmp;
    filePathNew += "/client/media/";
    filePathNew += filePathCurr;
    return filePathNew;
}
