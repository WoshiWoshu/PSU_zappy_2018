/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#include "Character.hpp"

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_tileSprite, states);
}

void Character::move(int x, int y)
{
  if (y > _y)
    _tileSprite.setTexture(_textures.at(0));
  if (y < _y)
    _tileSprite.setTexture(_textures.at(1));
  if (x > _x)
    _tileSprite.setTexture(_textures.at(2));
  if (x < _x)
    _tileSprite.setTexture(_textures.at(3));
  _tileSprite.setPosition(x, y);
  _x = x;
  _y = y;
}
