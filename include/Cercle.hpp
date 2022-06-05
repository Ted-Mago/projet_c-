#ifndef MONDE_HPP
#define MONDE_HPP
#include "Forme.hpp"
#include <cmath>

//class Carre;
class Cercle: public Forme{
protected:
  int rayon;
public:
  Cercle()=default;
  Cercle(const int& posX, const int& posY, int rayon): rayon(rayon){ this->posX=posX; this->posY=posY;};
  const int& getRayon() const { return rayon;}
  int getRayon() { return rayon;}

  //méthodes
  bool collision(const Cercle& c) const;
  bool collision(const Carre& c) const;

};


#endif
