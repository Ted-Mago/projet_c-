#ifndef MONDE_HPP
#define MONDE_HPP
#include "Joueur.hpp"
#include "Objet.hpp"
#include "ObjetDynamique.hpp"
#include "Munition.hpp"
#include "Ennemi.hpp"
##include <vector>

class MondePhys{
protected:
  std::vector<objet_ptr> objets;
public:
  MondePhys();
  bool hascollision();
  string keyPressed();
  void signalCollision();
  void signalKeyPressed();
  void updateOb(Objet o1, Objet o2);
  void updateObdyn();

};


#endif
