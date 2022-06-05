#include "../../include/Munition.hpp"

void Munition::seDeplacer(){
  posX=posX+vitesseX;
  posY=posY+vitesseX;
}

void Munition::update(){
  seDeplacer();
}

Munition::Munition(const int& posx, const int& posy){
  this->posX=posx;
  this->posY=posy;
  this->chargeDest=14;
  cercle_min=*(new Cercle(posX, posY, 5));
}
//Munition::~Munition(){}

Munition::Munition(int posX, int posY, float chargeDest){
  this->posX=posX;
  this->posY=posY;
  this->chargeDest=chargeDest;
  cercle_min=*(new Cercle(posX, posY, 5));
};

void Munition::afficher(sf::RenderWindow &r){
  sf::CircleShape circle;
  circle.setRadius(cercle_min.getRayon());
  circle.setOutlineColor(sf::Color::Red);
  circle.setPosition(cercle_min.getPosX(), cercle_min.getPosY());
  r.draw(circle);
}
