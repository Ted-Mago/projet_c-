#include "../../include/Commande.hpp"

void Commande::actionned(Joueur &j){


  if(sf::Keyboard::isKeyPressed(left))
    j.setDirection(1);
  else if(sf::Keyboard::isKeyPressed(right))
    j.setDirection(2);
  else if(sf::Keyboard::isKeyPressed(up))
    j.setDirection(3);
  else if(sf::Keyboard::isKeyPressed(down))
    j.setDirection(4);
  if(sf::Keyboard::isKeyPressed(attack))
      j.attaquer();

}
