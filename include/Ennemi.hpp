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
  void attaquer();

  //accesseur
  Carre getCarre_en(){return carre_en;}
  const Carre& getCarre_en() const { return carre_en;}




};
typedef std::shared_ptr<Ennemi> en_ptr;



#endif
