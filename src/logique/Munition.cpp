#include "../../include/Munition.hpp"

void Munition::seDeplacer(){
  if(direction==1 && posX>0)
    posX=posX-vitesseX;
  else if(direction==2 && posX<800)
    posX=posX+vitesseX;
  else if(direction==3 && posY>0)
    posY=posY-vitesseY;
  else if(direction==4 && posY<800)
    posY=posY+vitesseY;
  image.setPosition(posX, posY);
  cercle_min.move(posX, posY);

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
  this->direction=0;
  cercle_min=*(new Cercle(posX, posY, 5));
};

void Munition::afficher(sf::RenderWindow &r){
  sf::CircleShape circle;
  circle.setRadius(cercle_min.getRayon());
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(cercle_min.getPosX(), cercle_min.getPosY());
  r.draw(circle);
}
