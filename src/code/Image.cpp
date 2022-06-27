#include "../../include/Image.hpp"


Image::Image(const std::string& s, const int& im_posX, const int& im_posY , int l, int h, const int& posX, const int& posY){
  addTexture(s, im_posX, im_posY, l, h);
  sprite.setTexture(texture);
  //this->_posX()=*(&posX);
  //this->_posY()=*(&posY);
  this->setPosition(posX, posY);

}

Image& Image::operator=(const Image& o){
  this->changeTexture(o);
  this->sprite.setPosition(o.get_sprite().getPosition());
  return *this;
}

Image::Image(const Image& o){
  *this=o;
}

void Image::addTexture(const std::string& s, const int& im_posX, const int& im_posY , int l, int h){
  if(!texture.loadFromFile(s, sf::IntRect(im_posY, im_posX, l, h)))
    std::cout<<"problème chargement de l'image"<<std::endl;
}

void Image::changeTexture(const Image& o){
  this->texture=o.texture;
  this->sprite=o.sprite;
}
