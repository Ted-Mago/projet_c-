#include "../../include/Carre.hpp"


bool Carre::collision(const Carre& c){
  int L1=getPosX() + getCote()/2;
  int L2=c.getPosX() - c.getCote()/2;
  int T1=getPosX() - getCote()/2;
  int T2=c.getPosX() + c.getCote()/2;
  int H1=getPosY() + getCote()/2;
  int H2=c.getPosY() - c.getCote()/2;
  int R1=c.getPosY() + c.getCote()/2;
  int R2=getPosY() - getCote()/2;


  if((L2-L1>0 || T1-T2>0) && (H2-H1>0 || R2-R1>0 ))
    return false;
  else return true;
}
