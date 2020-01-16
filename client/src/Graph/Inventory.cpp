/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Inventory.cpp
*/

#include "InventoryGraph.hpp"

InventoryGraph::InventoryGraph()
    : _gemsSprite(), _boardSprite(),_boardText(),
    _gemsText(), _fontInventory(), _textureInventory()
{
    if (!_textureInventory.first
    .loadFromFile(this->concatClientPath(BOARD_INVENTORY_PATH))
    || !_textureInventory.second
    .loadFromFile(this->concatClientPath(GEMS_INVENTORY_PATH))
    || !_fontInventory.loadFromFile(this->concatClientPath(TEXT_FONT_PATH)))
        exit(84);
}

void InventoryGraph::setUpGemsTexture(void)
{
    std::pair<size_t, size_t> range(0, 0);

    for (auto &i : _gemsSprite) {
        i.setTextureRect(sf::IntRect(range.first, range.second, 340, 340));
        i.setTexture(_textureInventory.second);
        range.first += 340;
        if (range.first > 680) {
            range.first = 0;
            range.second += 340;
        }
    }
}

InventoryGraph::InventoryGraph(const std::string &tmp)
    : _gemsSprite(), _boardSprite(), _boardText(),
    _gemsText(), _fontInventory(), _textureInventory()
{
    static_cast<void>(tmp);
    if (!_textureInventory.second
    .loadFromFile(this->concatClientPath(GEMS_INVENTORY_PATH)))
        exit(84);
    this->setUpGemsTexture();
}

void InventoryGraph::setUpText(void)
{
    _boardText.setFont(_fontInventory);
    _boardText.setString("Inventory");
    _boardText.setCharacterSize(22);
    _boardText.setFillColor(sf::Color::White);
    _boardText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _boardText.setPosition(sf::Vector2f(1615, 96));
    for (auto &i : _gemsText) {
        i.setFont(_fontInventory);
        i.setFillColor(sf::Color::Black);
        i.setCharacterSize(12);
    }
    //à mettre au propre
    _gemsText[0].setString("Line: 0");
    _gemsText[0].setPosition(sf::Vector2f(1600, 180));
    _gemsText[1].setString("Derau: 0");
    _gemsText[1].setPosition(sf::Vector2f(1750, 180));
    _gemsText[2].setString("Sibur: 0");
    _gemsText[2].setPosition(sf::Vector2f(1600, 280));
    _gemsText[3].setString("Mendi: 0");
    _gemsText[3].setPosition(sf::Vector2f(1760, 280));
    _gemsText[4].setString("Phiras: 0");
    _gemsText[4].setPosition(sf::Vector2f(1610, 380));
    _gemsText[5].setString("Thys: 0");
    _gemsText[5].setPosition(sf::Vector2f(1760, 380));
    _gemsText[6].setString("Food: 0");
    _gemsText[6].setPosition(sf::Vector2f(1710, 450));
    //
}

void InventoryGraph::createItems(void)
{
    std::pair<size_t, size_t> range(1530, 150);

    _boardSprite.setTexture(_textureInventory.first);
    this->setUpGemsTexture();
    this->setUpText();
    _boardSprite.setColor(sf::Color(255, 255, 255, 210));
    _boardSprite.setScale(sf::Vector2f(0.7, 0.7));
    _boardSprite.setPosition(sf::Vector2f(1450, 50));
    for (auto it = _gemsSprite.begin();
    it != _gemsSprite.end() - 1; it++) {
        it->setPosition(sf::Vector2f(range.first, range.second));
        it->setScale(sf::Vector2f(0.2, 0.2));
        range.first += 10;
        range.second += 100;
        if (range.first == 1560) {
            range.first = 1680;
            range.second = 150;
        }
    }
    _gemsSprite[graph::FOOD].setPosition(sf::Vector2f(1612, 428));
    _gemsSprite[graph::FOOD].setScale(sf::Vector2f(0.2, 0.2));
}

void InventoryGraph::updateItems(const std::string &resources,
    const std::string &quantity)
{
    std::string newResources;

    newResources = resources + ':' + ' ' + quantity;
    if (resources.compare("Line") == 0)
        _gemsText[0].setString(newResources);
    else if (resources.compare("Derau") == 0)
        _gemsText[1].setString(newResources);
    else if (resources.compare("Sibur") == 0)
        _gemsText[2].setString(newResources);
    else if (resources.compare("Mendian") == 0)
        _gemsText[3].setString(newResources);
    else if (resources.compare("Phiras") == 0)
        _gemsText[4].setString(newResources);
    else if (resources.compare("Thys") == 0)
        _gemsText[5].setString(newResources);
    else if (resources.compare("Food") == 0)
        _gemsText[6].setString(newResources);
}

void InventoryGraph::draw(sf::RenderTarget &target,
    sf::RenderStates states) const
{
    target.draw(_boardSprite, states);
    for (auto &i : _gemsSprite)
        target.draw(i, states);
    target.draw(_boardText, states);
    for (auto &i : _gemsText)
        target.draw(i, states);
}
