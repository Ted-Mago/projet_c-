#ifndef CARRE_HPP
#define CARRE_HPP
#include "Forme.hpp"
#include "Cercle.hpp"

class Carre: public Forme{
protected:
  int cote;
public:
  Carre()=default;
  Carre(int posX, int posY, int cote): cote(cote){ posX=posX; posY=posY;}
  const int& getCote() const{ return cote;}
  int getCote() { return cote;}

};


#endif
