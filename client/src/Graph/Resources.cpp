/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Resources.cpp
*/

#include "Resources.hpp"

Resources::Resources() : InventoryGraph("Create"), _resources(0)
{}

void Resources::createItems(int width, int height)
{
    std::pair<size_t, size_t> gemsPos(0, 0);
    size_t gemsInfo(0);
    size_t k(0);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width - 1; j++) {
            if (j % 2 == 1) {
                _resources.push_back(_gemsSprite[gemsInfo]);
                _resources.at(k).setScale(sf::Vector2f(0.06, 0.06));
                _resources.at(k).setPosition(sf::Vector2f(gemsPos.first,
                gemsPos.second));
                k++;
            }
            gemsInfo++;
            gemsInfo == 7 ? gemsInfo = 0 : 0;
            gemsPos.first += 32;
        }
        i % 2 == 0 ? gemsPos.first = 32 : gemsPos.first = 0;
        gemsPos.second += 32;
    }
}

void Resources::updateItems()
{}

void Resources::draw(sf::RenderTarget &target,
    sf::RenderStates states) const
{
    for (auto &i : _resources)
        target.draw(i, states);
}
