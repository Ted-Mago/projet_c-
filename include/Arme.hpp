#ifndef ARME_HPP
#define ARME_HPP
#include "ObjetDynamique.hpp"
#include "Munition.hpp"
#include "Image.hpp"
#include <vector>
#include <ctime>



class Arme: public ObjetDynamique{
protected:
    Munition munition;
    int nbr_munitions;
    int direction;
    std::vector<munition_ptr> projectiles;
    time_t t_entre_tir;
    time_t last_tir;

public:
    Arme(const int& posx, const int& posy);
    Arme(const int& posx, const int& posy, Munition munition, Image image);
    Arme()=default;
  void seDeplacer();
  bool tir(int i);
  void update();
  void afficher(sf::RenderWindow& r);
  Munition getMunition(){ return munition;}
  const Munition& getMunition() const{ return munition;}
  void nbr_plus(){ nbr_munitions=nbr_munitions+1;}
  void nbr_moins(){ nbr_munitions=nbr_munitions-1;}
  void setNbr_muni(int nbr){ nbr_munitions=nbr;}
  int getDirection(){return direction;}
  void setDirection(int dir){ direction=dir;}
  void seDeplacer(const int& posx, const int& posy);

};

#endif
