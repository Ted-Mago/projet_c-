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
  int direction;
public:
  Munition(int posX, int posY, float chargeDest);

  Munition(const int& posx, const int& posy);
  Munition()=default;
  //~Munition();
  void seDeplacer();
  void update();
  void afficher(sf::RenderWindow &r);

//  void blesserEnnemi(Joueur j);
  const Cercle& getCercle_min() const{return cercle_min;}
  Cercle getCercle_min(){return cercle_min;}


};

typedef std::shared_ptr<Munition> munition_ptr;



#endif
