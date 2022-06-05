#ifndef ARME_HPP
#define ARME_HPP
#include "ObjetDynamique.hpp"
#include "Munition.hpp"



class Arme: public ObjetDynamique{
protected:
    Munition munition;
  //  std::vector<munition_ptr> projeciles;

public:
    Arme(const int& posx, const int& posy);
    Arme(const int& posx, const int& posy, Munition munition, Image image);
    Arme()=default;

  void seDeplacer();
  //void attaquer();
  void update();
  void afficher(sf::RenderWindow& r);

};

#endif
