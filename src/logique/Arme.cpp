#include "../../include/Arme.hpp"

void Arme::seDeplacer(){
  posX=posX+vitesseX;
  posY=posY+vitesseX;
}


void Arme::update(){
  this->seDeplacer();
}

Arme::Arme(const int& posx, const int& posy, Munition munition, Image image){
posX=posx;
posY=posy;
this->munition=munition;
this->image=image;
niveauDeVie=1000;
}
Arme::Arme(){
  posX=1000;
  posY=1000;
  munition_ptr m= std::make_shared<Munition>();

  munition=*m;
//  delete m;
};

//Arme::~Arme(){;}
