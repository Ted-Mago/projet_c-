#include "../../include/Joueur.hpp"
#include <iostream>

Joueur::Joueur(int posX, int posY){

  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=1;
  vitesseY=1;
  image= *(new Image(img_name, 0, 0, 0, 0, posX, posY));
  cercle_j=*(new Cercle(posX, posY, 8));
  //arme
  arme=*(new Arme(posX, posY));
}



void Joueur::seDeplacer(){

  if(direction==1)
    posX=posX-vitesseX;
  else if(direction==2)
    posX=posX+vitesseX;
  else if(direction==3)
    posY=posY-vitesseY;
  else if(direction==4)
    posY=posY+vitesseY;
  else perror("erreur s");
  //this->seDeplacer();
  image.setPosition(posX, posY);
  direction=0;
}
void Joueur::update(){
  this->seDeplacer();
}
