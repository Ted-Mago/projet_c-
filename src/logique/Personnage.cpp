#include "../../include/Personnage.hpp"

void Personnage::afficher(sf::RenderWindow &r){
  r.draw(image.get_sprite());
  this->getArme().afficher(r);
}
