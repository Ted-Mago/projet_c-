#include "../../include/Cercle.hpp"
#include "../../include/Carre.hpp"


bool Cercle::collision(const Cercle& c) const{
  int r_2=pow(this->getRayon()+c.getRayon(), 2);
  int x_2=pow(this->getPosX()-c.getPosX(), 2);
  int y_2=pow(this->getPosY()-c.getPosY(), 2);

  if(r_2>=(x_2+y_2))
    return true;
  else return false;
}

bool Cercle::collision(const Carre& c) const{
  int x=abs(getPosX()-2*getRayon()-c.getPosX());
  int y=abs(getPosY()-2*getRayon()-c.getPosY());
  int dist=(c.getCote()/2 +getRayon());
  if(x>dist || y>dist)
    return false;
  else if(x<=c.getCote()/2 || y<= c.getCote()/2)
    return true;
  else{
    int dist_2=pow(x-c.getCote()/2, 2)+ pow(y-c.getCote()/2, 2);
    return (dist_2 <= pow(getRayon(), 2));
  }
}
/*
bool Cercle::collision(const Carre& c) const{
  Carre comp(posX-2*rayon, posY-2*rayon, 2*rayon);

  return comp.collision(c);
}*/
