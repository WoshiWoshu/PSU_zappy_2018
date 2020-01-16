/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Map.cpp
*/

#include <iostream>
#include "Map.hpp"

std::vector<std::vector<int>> Map::createConsoleMap(unsigned int width,
    unsigned int height)
{
    std::vector<std::vector<int>> tileMap(0);

    for (unsigned int i = 0; i < height; i++) {
        tileMap.push_back(std::vector<int>(0));
        for (unsigned int j = 0; j < width; j++)
                tileMap.at(i).push_back(0);
    }
    return tileMap;
}

sf::VertexArray Map::makePositionQuadTexture(sf::VertexArray tileMapTmp,
    int currentTile, int i, int j)
{
    std::pair<int, int> texturePos(0, 0);

    texturePos.first = currentTile % (_tileTexture.getSize().x / _tileSize.x);
    texturePos.second = currentTile / (_tileTexture.getSize().x / _tileSize.x);
    tileMapTmp[0].position = sf::Vector2f(j * _tileSize.x, i * _tileSize.y);
    tileMapTmp[1].position =
    sf::Vector2f((j + 1) * _tileSize.x, i * _tileSize.y);
    tileMapTmp[2].position
    = sf::Vector2f((j + 1) * _tileSize.x, (i + 1) * _tileSize.y);
    tileMapTmp[3].position
    = sf::Vector2f(j * _tileSize.x, (i + 1) * _tileSize.y);
    tileMapTmp[0].texCoords = sf::Vector2f(texturePos.first * _tileSize.x,
    texturePos.second * _tileSize.y);
    tileMapTmp[1].texCoords = sf::Vector2f((texturePos.first + 1)
    * _tileSize.x, texturePos.second * _tileSize.y);
    tileMapTmp[2].texCoords = sf::Vector2f((texturePos.first + 1)
    * _tileSize.x, (texturePos.second + 1) * _tileSize.y);
    tileMapTmp[3].texCoords = sf::Vector2f(texturePos.first
    * _tileSize.x, (texturePos.second + 1) * _tileSize.y);
    return tileMapTmp;
}

void Map::fillVertexQuadTexture(sf::VertexArray tileMapTmp, int i)
{
    _tileMap.push_back(std::vector<sf::Vertex>());
    for (int j = 0; j < 4; j++)
        _tileMap.at(i).push_back(tileMapTmp[j]);
}

void Map::createMap(unsigned int width, unsigned int height)
{
    sf::VertexArray tileMapTmp(sf::Quads, 4);
    std::vector<std::vector<int>> tiles(this->createConsoleMap(width, height));
    int currentTile(0);

    if (!_tileTexture.loadFromFile(this->concatClientPath(TILE_MAP_PATH)))
        exit(84);
    for (unsigned int i = 0; i < tiles.size(); i++)
        for (unsigned int j = 0; j < tiles[i].size(); j++) {
            currentTile = tiles[i][j];
            tileMapTmp =
            this->makePositionQuadTexture(tileMapTmp, currentTile, i, j);
            this->fillVertexQuadTexture(tileMapTmp, i);
        }
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::VertexArray tileMapTmp(sf::Quads, _tileMap.size() * 4);
    int k(0);

    states.transform *= getTransform();
    states.texture = &_tileTexture;
    for (auto i : _tileMap)
        for (auto j : i)
            tileMapTmp[k++] = j;
    target.draw(tileMapTmp, states);
}
