#ifndef PERSO_HPP
#define PERSO_HPP
#include "Arme.hpp"
#include "ObjetDynamique.hpp"
#define size_perso 100



class Personnage: public ObjetDynamique{
protected:
  Arme arme;
public:
  void afficher(sf::RenderWindow &r);


  virtual void seDeplacer()=0;
  virtual void update()=0;
  //virtual void cacher()=0;

  //accesseur
  Arme getArme(){ return arme;}

};

#endif
