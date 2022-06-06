#include "../../include/Carre.hpp"
#include "../../include/Cercle.hpp"


bool Carre::collision(const Cercle& c) const{

  return c.collision(*this);}
