#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Personnage.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "Arme.hpp"
//#include "Commande.hpp"
#include <vector>


class Joueur: public Personnage{
protected:

  int direction=0;
  Arme arme;
  static std::vector<std::string> numero_joueur;


public:
  Joueur(int posX, int  posY,std::string s);

  void seDeplacer();

  void attaquer();
//  void afficher(Ui ui&);
  //void seBlesser( Munition m&);
  void update();
  //void cacher();
//  void changerArme(Arme a);


//accesseur
void setDirection(const int& direction){ this->direction=direction;}
int getDirection(){ return direction;}
Arme getArme(){ return arme;}

};


#endif
