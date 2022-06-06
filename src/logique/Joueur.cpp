#include "../../include/Joueur.hpp"
#include <iostream>

Joueur::Joueur(int posX, int posY){

  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=2;
  vitesseY=2;
  image= *(new Image(img_name, 0, 0, size_jo, size_jo, posX, posY));
  cercle_j=*(new Cercle(posX, posY, size_jo/2));
  //arme
  arme=*(new Arme(posX+size_jo, posY+size_jo));
}



void Joueur::seDeplacer(){

  if(direction==1 && posX>0)
    posX=posX-vitesseX;
  else if(direction==2 && posX<size_win-size_jo)
    posX=posX+vitesseX;
  else if(direction==3 && posY>0)
    posY=posY-vitesseY;
  else if(direction==4 && posY<size_win-size_jo)
    posY=posY+vitesseY;
  else perror("erreur s");
  arme.setDirection(direction);
  image.setPosition(posX, posY);
  arme.seDeplacer(posX+size_jo, posY+size_jo);
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

bool Joueur::collision(const Ennemi& e){
  if(cercle_j.collision(e.getCarre_en())){
    niveauDeVie=niveauDeVie-50;
    std::cout<< "col jo e"<<std::endl;
    return true;
  }
  else return false;
}

bool Joueur::collision(Munition& m){
  if(cercle_j.collision(m.getCercle_min())){
    niveauDeVie=niveauDeVie-m.getChargeDest();
    m.setNiveauDeVie(0);
    std::cout<< "col jo e"<<std::endl;
    return true;
  }

  else return false;
}
