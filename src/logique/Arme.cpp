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
Arme::Arme(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  munition_ptr m= std::make_shared<Munition>(posx, posy);

  munition=*m;
//  delete m;
};

void Arme::afficher(sf::RenderWindow& r){
    r.draw(image.get_sprite());
  }
