#include "../../include/Munition.hpp"

void Munition::seDeplacer(){
  posX=posX+vitesseX;
  posY=posY+vitesseX;
}

void Munition::update(){
  seDeplacer();
}

Munition::Munition(){
  this->posX=10000;
  this->posY=10000;
  this->chargeDest=14;
  this->forme=std::make_shared<Cercle>(posX, posY, 5);
}
//Munition::~Munition(){}

//Munition::blesserEnnemi()
