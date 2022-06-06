#include "../../include/Carre.hpp"
#include "../../include/Cercle.hpp"

/*Ayant Ce code appartient à Alex Coninx*/

bool Carre::collision(const Carre& c) const{


  float xdist; // This will be the distance between the right edge of the leftmost rectangle and the left edge of the rightmost rectangle
  if(getPosX() < c.getPosX()) // We are the leftmost rectangle
      xdist = (c.getPosX() - c.getCote()/2) - (getPosX() + getCote()/2);
  else // c is the leftmost rectangle
      xdist = (getPosX() - getCote()/2) - (c.getPosX() + c.getCote()/2);

  if(xdist > 0) // no overlap
      return false;

  // Do Y ranges intersect ?
  float ydist; // This will be the distance between the bottom edge of the topmost rectangle and the top edge of the bottommost rectangle
  if(getPosY() < c.getPosY()) // We are the bottom rectangle
      ydist = (c.getPosY() - c.getCote()/2) - (getPosY() + getCote()/2);
  else // c is the bottom rectangle
      ydist = (getPosY() - getCote()/2) - (c.getPosY() + c.getCote()/2);

  if(ydist > 0) // no overlap
      return false;
  else
      return true; // overlap on both coords
}

bool Carre::collision(const Cercle& c) const{

  return c.collision(*this);}
