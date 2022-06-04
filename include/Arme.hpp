#ifndef ARME_HPP
#define ARME_HPP
#include "ObjetDynamique.hpp"
#include "Munition.hpp"



class Arme: public ObjetDynamique{
protected:
    Munition munition;
    std::vector<munition_ptr> projeciles;

public:
    Arme();
    Arme(const int& posx, const int& posy, Munition munition, Image image);


  void seDeplacer();
  //void attaquer();
  void update();

};

#endif
