#include "../../include/Ui.hpp"


Ui::Ui(){
  window =new sf::RenderWindow(sf::VideoMode(800, 800), "PACKMAN MORTEL");
  window ->setFramerateLimit(60);
  window->clear(sf::Color::Gray);
}

Ui::~UI(){
  delete window;
}

void Ui::isOpen(){
  return window->isOpen();
}

void Ui::close(){
  window->close();
}

void Ui::afficherObjet(const Objet& o){
  window->draw(o.getImage());
}

void Ui::afficherJoueur(const Joueur& j){
  sf::CircleShape circle(j.getForme()->getRayon());
  circle.setPosition(j.getPosX(), j.getPosY());
  circle.setOutlineColor(sf::Color::Red);
  window->draw(circle);
  window->draw(j.getImage());
}

void Ui::afficherMunition(const Munition& m){
  sf::CircleShape circle(m.getForme()->getRayon());
  circle.setPosition(m.getPosX(), m.getPosY());
  circle.setFillColor(sf::Color::Red);
  window->draw(circle);

}
