#include "../../include/Joueur.hpp"
#include <iostream>

Joueur::Joueur(int posX, int posY){

  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=1;
  vitesseY=1;
  image= *(new Image(img_name, 0, 0, 0, 0, posX, posY));
  cercle_j=*(new Cercle(posX, posY, 18));
  //arme
  arme=*(new Arme(posX+32, posY+32));
}



void Joueur::seDeplacer(){

  if(direction==1 && posX>0+cercle_j.getRayon())
    posX=posX-vitesseX;
  else if(direction==2 && posX<800-cercle_j.getRayon())
    posX=posX+vitesseX;
  else if(direction==3 && posY>0+cercle_j.getRayon())
    posY=posY-vitesseY;
  else if(direction==4 && posY<800-cercle_j.getRayon())
    posY=posY+vitesseY;
  else perror("erreur s");
  arme.setDirection(direction);
  image.setPosition(posX, posY);
  arme.seDeplacer(posX+32, posY+32);
  cercle_j.move(posX, posY);

  direction=0;
}
void Joueur::update(){
  this->seDeplacer();
}

bool Joueur::collision(const Joueur& j){
  if(cercle_j.collision(j.getCercle_j())){
    niveauDeVie=niveauDeVie-2;
    std::cout<< "col jo j"<<std::endl;
    return true;
  }
  else return false;
}
