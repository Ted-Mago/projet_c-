#ifndef MONDE_HPP
#define MONDE_HPP
#include "Forme.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>




class Cercle: public Forme{
protected:
  int rayon;
public:
  Cercle()=default;
  Cercle(const int& posX, const int& posY, int rayon): rayon(rayon){ this->posX=posX; this->posY=posY;};
  //accecseur
  const int& getRayon() const { return rayon;}
  int getRayon() { return rayon;}



  //méthodes
  bool collision(const Cercle& c) const;
  bool collision(const Carre& c) const;
  void afficher(sf::RenderWindow& r){  sf::CircleShape circle(rayon); // Create circle
  circle.setPosition(posX, posY); //  We must convert the center position to the top left point position

  r.draw(circle); }

};


#endif
