#ifndef COMMANDE_HPP
#define COMMANDE_HPP
#include "SFML/Graphics.hpp"
#include "Joueur.hpp"

//clase pour la commande des Joueur


class Commande{
protected:
  sf::Keyboard::Key left;
  sf::Keyboard::Key right;
  sf::Keyboard::Key up;
  sf::Keyboard::Key down;
  sf::Keyboard::Key attack;
public:
  Commande(sf::Keyboard::Key l, sf::Keyboard::Key r, sf::Keyboard::Key u, sf::Keyboard::Key d, sf::Keyboard::Key a)
  : left(l), right(r), up(u), down(d), attack(a){};
  void actionned(Joueur &j);
  std::string bouton();

};

#endif
