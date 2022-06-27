#include "../../include/Munition.hpp"
#include <iostream>

void Munition::seDeplacer(){
  if(posX+size_min<0 || posX>size_win || posY+size_min<0 || posY>size_win) niveauDeVie=0;
  if(direction==1 && posX>-4*size_min)
    posX=posX-vitesseX;
  else if(direction==2 && posX<size_win)
    posX=posX+vitesseX;
  else if(direction==3 && posY>-4*size_min)
    posY=posY-vitesseY;
  else if(direction==4 && posY<size_win)
    posY=posY+vitesseY;
  cercle_min.move(posX, posY);

}

void Munition::update(){
  seDeplacer();
}

Munition::Munition(const int& posx, const int& posy){
  this->posX=posx;
  this->posY=posy;
  this->chargeDest=14;
  this->niveauDeVie=1000;
  this->direction=0;
  cercle_min=*(new Cercle(posX, posY, 5));
  vitesseX=5;
  vitesseY=5;
}
//Munition::~Munition(){}
Munition::Munition(const Munition& m){
  posX=m.posX;
  posY=m.posY;
  chargeDest=m.chargeDest;
  niveauDeVie=m.niveauDeVie;
  cercle_min=m.cercle_min;
  vitesseX=m.vitesseX;
  vitesseY=m.vitesseY;
  direction=m.direction;


}

void Munition::afficher(sf::RenderWindow &r){
  sf::CircleShape circle;
  circle.setRadius(cercle_min.getRayon());
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(cercle_min.getPosX()+2*cercle_min.getRayon(), cercle_min.getPosY()+2*cercle_min.getRayon());
  r.draw(circle);
}

bool Munition::collision(const Mur& m){
  if(cercle_min.collision(m.getCarre_mur())){
    niveauDeVie=0;
    return true;
  }

  else return false;

}

bool Munition::collision(Munition& m){
  if(cercle_min.collision(m.cercle_min)){
    niveauDeVie=0;
    m.niveauDeVie=0;
    return true;
  }
  else return false;
}
