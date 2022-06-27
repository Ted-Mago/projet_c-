#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>



class Image{
protected:
  sf::Texture texture;
  sf::Sprite sprite;
public:

  Image(const std::string& s, const int& im_posX, const int& im_posY , int l, int h, const int& posX, const int& posY);
  Image()=default;
  Image(const Image& o);
  Image& operator=(const Image& o);


  void addTexture(const std::string& s, const int& im_posX, const int& im_posY , int l, int h);
  void changeTexture(const Image& o);


  sf::Sprite get_sprite() const {return sprite;}
  sf::Texture get_texture() const {return texture;}

  
  void setPosition(const int& posX, const int& posY ){sprite.setPosition(posX, posY);}



};

typedef std::shared_ptr<Image> img_ptr;

#endif
