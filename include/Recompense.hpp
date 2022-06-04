#ifndef REC_HPP
#define REC_HPP
#include "ObjetFixe.hpp"
#include "Cercle.hpp"
#include "Joueur.hpp"

class Recompense: public ObjetFixe {
protected:
  int val;
public:
  int getVal(){ return val;}
  const int& getVal() const {return val;}
  //virtual void addRec(const int& posx, const int& posy)=0;


};

#endif
