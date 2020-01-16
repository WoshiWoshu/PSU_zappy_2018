/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Resources.hpp
*/

#pragma once

#include "InventoryGraph.hpp"

class Resources : public InventoryGraph
{
public:
    explicit Resources();
    void createItems(int height, int width);
    void updateItems();
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::vector<sf::Sprite> _resources;
};
