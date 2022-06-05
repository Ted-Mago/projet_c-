#ifndef MUNITION_HPP
#define MUNITION_HPP
#include "ObjetDynamique.hpp"
#include "SFML/Graphics.hpp"
#include "Cercle.hpp"


//class Joueur;
class Munition: public ObjetDynamique {
protected:
  float chargeDest;
  Cercle cercle_min;
public:
  Munition(int posX, int posY, float chargeDest);

  Munition(const int& posx, const int& posy);
  Munition()=default;
  //~Munition();
  void seDeplacer();
  void update();
  void afficher(sf::RenderWindow &r);

//  void blesserEnnemi(Joueur j);


};

typedef std::shared_ptr<Munition> munition_ptr;



#endif
