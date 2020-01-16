/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Inventory.hpp
*/

#pragma once

#include "Graphics.hpp"

namespace graph {
    enum Gems {
        LINEMATE = 0,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME,
        FOOD
    };
}

class InventoryGraph : public Graphics::Utility, public sf::Drawable {
public:
    InventoryGraph();
    InventoryGraph(const std::string &tmp);
    void createItems(void);
    void updateItems(const std::string &resources,
    const std::string &quantity);
protected:
    std::array<sf::Sprite, 7> _gemsSprite;
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setUpText(void);
    void setUpGemsTexture(void);
    sf::Sprite _boardSprite;
    sf::Text _boardText;
    std::array<sf::Text, 7> _gemsText;
    sf::Font _fontInventory;
    std::pair<sf::Texture, sf::Texture> _textureInventory;
};
