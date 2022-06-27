#ifndef OBJETD_HPP
#define OBJETD_HPP
#include "SFML/Graphics.hpp"
#include "Objet.hpp"




class ObjetDynamique:public Objet{
protected:
  int vitesseX;
  int vitesseY;
public:

  //accesseur
  int getVitesseX(){ return vitesseX;}
  int getVitesseY(){ return vitesseY;}
  void setVitesse(int vX, int vY){ vitesseX=vX, vitesseY=vY;}

  //méthodes
  virtual void update()=0; //permet de mettre à jour les observateurs enregistrés 
  virtual void seDeplacer()=0;



};

#endif
