#ifndef CARRE_HPP
#define CARRE_HPP
#include "Forme.hpp"
#include <cmath>
#include "SFML/Graphics.hpp"
//class Cercle;
class Carre: public Forme{
protected:
  int cote;
public:
  Carre()=default;
  Carre(int posX, int posY, int cote): cote(cote){ this->posX=posX; this->posY=posY;}
  const int& getCote() const{ return cote;}
  int getCote() { return cote;}
  bool collision(const Carre& c) const;
  bool collision(const Cercle& c) const;
  void afficherC(sf::RenderWindow& r){
    sf::RectangleShape circle;
    circle.setSize(sf::Vector2f(cote, cote));
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(getPosX(), getPosY());
    r.draw(circle);
  }
};


#endif
