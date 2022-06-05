#ifndef ENNEMI_HPP
#define ENNEMI_HPP
#include "Personnage.hpp"
#include "Carre.hpp"
#include <ctime>


class Ennemi: public Personnage{
protected:
  //Arme arme;
  const std::string img_name= "res/enb.png";
  float chargeDest;
  Carre carre_en;
public:
  Ennemi(const int& posx, const int& posy);
  void seDeplacer();
  void update();



};


#endif
