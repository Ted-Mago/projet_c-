#ifndef OBJETF_HPP
#define OBJETF_HPP
#include "SFML/Graphics.hpp"
#include "Objet.hpp"

class ObjetFixe: public Objet{

public:

  //void addObF(objetF_ptr o);
  void afficher(sf::RenderWindow& r){
    r.draw(image.get_sprite());
  }
};

typedef std::shared_ptr<ObjetFixe> objetF_ptr;

#endif
