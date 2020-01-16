/*
** EPITECH PROJECT, 2018
** $NAME_OF_THE_PROJECT
** File description:
** Here is coded a super function
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <unistd.h>

class Character : public sf::Drawable, public sf::Transformable {
  public:
    Character(std::string name, int x, int y) : _textures(), _tileSprite(), _x(x), _y(y) {
      std::vector<std::string> images;
      sf::Texture texture;
      std::string filePath;
      char filePathTmp[100] = {0};

      getcwd(filePathTmp, sizeof(filePathTmp));
      filePath = filePathTmp;
      for (int i = 1; i < 5; i++) {
        images.push_back(filePath+"/client/media/"+name+std::to_string(i)+".png");
        texture.loadFromFile(images.at(i-1));
        texture.setSmooth(true);
        _textures.push_back(texture);
      }
      _tileSprite.setTexture(_textures.at(0));
      _tileSprite.setPosition(x, y);
    };
    ~Character() = default;
    void move(int, int);

  private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    std::vector<sf::Texture> _textures;
    sf::Sprite _tileSprite;
    int _x;
    int _y;
};

#endif
