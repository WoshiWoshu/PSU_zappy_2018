/*
** EPITECH PROJECT, 2019
** Zappy
** File description:
** Map.hpp
*/

#pragma once

#include "Graphics.hpp"

class Map : public Graphics::Utility, public sf::Drawable
    , public sf::Transformable {
public:
    explicit inline Map()
     : _tileSize(sf::Vector2u(32, 32)),
     _tileTexture(), _tileMap(sf::Quads) {};
    ~Map() = default;
    void createMap(unsigned int width, unsigned int height);
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::vector<std::vector<int>> createConsoleMap(unsigned int width,
    unsigned int height);
    sf::VertexArray makePositionQuadTexture(sf::VertexArray tileMapTmp,
    int currentTile, int i, int j);
    void fillVertexQuadTexture(sf::VertexArray tileMapTmp, int i);
    
    sf::Vector2u _tileSize;
    sf::Texture _tileTexture;
    std::vector<std::vector<sf::Vertex>> _tileMap;
};
