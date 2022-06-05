#include "../../include/Arme.hpp"

void Arme::seDeplacer(){
  image.setPosition(posX, posY);
  munition.setPosX(posX);
  munition.setPosY(posY);
}

void Arme::seDeplacer(const int& posx, const int& posy ){

  posX=posx;
  posY=posy;
  seDeplacer();

}


void Arme::update(){
  this->seDeplacer();
}

Arme::Arme(const int& posx, const int& posy, Munition munition, Image image){
posX=posx;
posY=posy;
nbr_munitions=0;
this->munition=munition;
this->image=image;
direction=0;
niveauDeVie=1000;
}
Arme::Arme(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  nbr_munitions=0;
  munition_ptr m= std::make_shared<Munition>(posx, posy);
  munition=*m;
  image= *(new Image("res/arme.png", 0, 0, 8, 8, posX, posY));


//  delete m;
};

void Arme::afficher(sf::RenderWindow& r){
    r.draw(image.get_sprite());
  }
Munition Arme::tir(){
  nbr_munitions--;
  return getMunition();

}
