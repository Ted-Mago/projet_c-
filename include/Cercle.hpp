#ifndef MONDE_HPP
#define MONDE_HPP
#include "Forme.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

//class Carre;
class Cercle: public Forme{
protected:
  int rayon;
public:
  Cercle()=default;
  Cercle(const int& posX, const int& posY, int rayon): rayon(rayon){ this->posX=posX; this->posY=posY;};
  const int& getRayon() const { return rayon;}
  int getRayon() { return rayon;}
  void afficherC(sf::RenderWindow& r){
    sf::CircleShape circle;
    circle.setRadius(getRayon());
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(getPosX(), getPosY());
    r.draw(circle);
    sf::RectangleShape ref;
    ref.setSize(sf::Vector2f(rayon*2, rayon*2));
    ref.setFillColor(sf::Color::Red);
    ref.setPosition(getPosX()-2*rayon, getPosY()-2*rayon);
    r.draw(ref);
  }


  //méthodes
  bool collision(const Cercle& c) const;
  bool collision(const Carre& c) const;

};


#endif
