#ifndef UI_HPP
#define UI_HPP
#include "SFML/Graphics.hpp"
#include <iostream>

  class Joueur;
  class Image;
  class Cercle;
  class Objet;
//  class Ennemi;
  class Munition;

  class Ui{
  public:
    Ui();
    ~Ui();
  //  void waitForExit();

    void afficherObjet(const Objet& o);
    void afficherJoueur(const Joueur& j);
    //void afficherEnnemi(const Ennemi& e);
    void afficherMunition(const Munition& m);
    bool isOpen();
    void close();
  private:
    sf::RenderWindow* window;
  };

  #endif
