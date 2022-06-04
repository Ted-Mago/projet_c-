#include "../../include/Commande.hpp"

bool Commande::actionned(Joueur &j){

  if(sf::Keyboard::isKeyPressed(left))
    j.setDirection(1);
  else if(sf::Keyboard::isKeyPressed(right))
    j.setDirection(2);
  else if(sf::Keyboard::isKeyPressed(up))
    j.setDirection(3);
  else if(sf::Keyboard::isKeyPressed(down))
    j.setDirection(4);
  else if(sf::Keyboard::isKeyPressed(attack))
    j.setDirection(5);

  if(    j.getDirection()!=0){
    if( j.getDirection()==5)
    //  j.attaquer(); if
     j.setDirection(12);
    else j.seDeplacer();
    return true;
  }


  else return false;

}
