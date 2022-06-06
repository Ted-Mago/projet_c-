#ifndef ARME_HPP
#define ARME_HPP
#include "ObjetDynamique.hpp"
#include "Munition.hpp"
#include "Image.hpp"



class Arme: public ObjetDynamique{
protected:
    Munition munition;
    int nbr_munitions;
    int direction;
  //  std::vector<munition_ptr> projeciles;

public:
    Arme(const int& posx, const int& posy);
    Arme(const int& posx, const int& posy, Munition munition, Image image);
    Arme()=default;
  void seDeplacer();
  Munition tir();
  void update();
  void afficher(sf::RenderWindow& r);
  Munition getMunition(){ return munition;}
  const Munition& getMunition() const{ return munition;}
  void nbr_plus(){ nbr_munitions++;}
  void nbr_moins(){ nbr_munitions--;}
  int getDirection(){return direction;}
  void setDirection(int dir){ direction=dir;}
  void seDeplacer(const int& posx, const int& posy);

};

#endif
