#include "../../include/Cercle.hpp"

bool Cercle::collision(Cercle& c){
  int r_2=pow(this->getRayon()+c.getRayon(), 2);
  int x_2=pow(this->getPosX()-c.getPosX(), 2);
  int y_2=pow(this->getPosY()-c.getPosY(), 2);

  if(r_2>=(x_2+y_2))
    return true;
  else return false;
}
