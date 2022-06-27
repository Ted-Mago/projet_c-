#include "../../include/Joueur.hpp"
#include <iostream>

Joueur::Joueur(int posX, int posY, std::string s){

  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=2;
  vitesseY=2;
  image= *(new Image(s, 0, 0, size_jo, size_jo, posX, posY));
  cercle_j=*(new Cercle(posX, posY, size_jo/2));
  last_dir=2;
  arme=*(new Arme(posX+size_jo, posY+size_jo));
  time(&last_col);
}



void Joueur::seDeplacer(){
  last_dir=direction;
  if(direction==1 && posX>0)
    posX=posX-vitesseX;
  else if(direction==2 && posX<size_win-size_jo)
    posX=posX+vitesseX;
  else if(direction==3 && posY>0)
    posY=posY-vitesseY;
  else if(direction==4 && posY<size_win-size_jo)
    posY=posY+vitesseY;
  arme.setDirection(direction);
  image.setPosition(posX, posY);
  arme.seDeplacer(posX+size_jo, posY+size_jo);
  cercle_j.move(posX, posY);

  direction=0;
}
void Joueur::update(){
  this->seDeplacer();
  arme.update();
}

bool Joueur::collision( Joueur& j){
  time(&col_time);
  if(cercle_j.collision(j.getCercle_j()) && abs(difftime(last_col, col_time))>3){
    time(&last_col);
    niveauDeVie=niveauDeVie-2;
    j.niveauDeVie=j.niveauDeVie-2;
    return true;
  }
  else return false;
}

bool Joueur::collision(const Ennemi& e){
  time(&col_time);
  if(cercle_j.collision(e.getCarre_en())  && abs(difftime(last_col, col_time))>3){
    time(&last_col);
    niveauDeVie=niveauDeVie-50;
    return true;
  }
  else return false;
}

bool Joueur::collision(Munition& m){
  time(&col_time);
  if(cercle_j.collision(m.getCercle_min()) && abs(difftime(last_col, col_time))>3){
    time(&last_col);
    niveauDeVie=niveauDeVie-m.getChargeDest();
    m.setNiveauDeVie(0);
    return true;
  }
  else return false;
}

bool Joueur::collision(const Mur& m){
  if(cercle_j.collision(m.getCarre_mur())){
    if(last_dir%2==0) direction=last_dir-1;
    else direction=last_dir+1;
    seDeplacer();
    return true;

  }

  else return false;
}

bool Joueur::collision(Paku& p){
  if(cercle_j.collision(p.getCercle_paku())){
    score++;
    arme.nbr_plus();
    p.setNiveauDeVie(0);
    return true;
  }
  else return false;
}

bool Joueur::attaquer(){
  if(last_dir!=0) return arme.tir(last_dir);
  return false;
}
