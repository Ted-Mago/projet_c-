#ifndef ENNEMI_HPP
#define ENNEMI_HPP
#include "Personnage.hpp"


class Ennemi: public Personnage{
protected:
  //Arme arme;
  const std::string img_name= "res/enb.png"
  float chargeDest;
public:
  Ennemi(const int& posx, const int& poy);
  void seDeplacer();
  void update();



};


#end
