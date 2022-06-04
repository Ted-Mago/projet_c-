#ifndef ENV_HPP
#define ENV_HPP
#include "ObjetFixe.hpp"

class Env: public ObjetFixe{
public:
  void afficher(sf::RenderWindow& r){r.draw(image.get_sprite());}
};
#endif
