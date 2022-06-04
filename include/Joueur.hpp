#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Personnage.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
//#include "Arme.hpp"
//#include "Commande.hpp"
#include <vector>
//#define img_name "enb.png"


class Joueur: public Personnage{
protected:

  int direction=0;
  //Arme arme;
  const std::string img_name="res/paku.png";
  static std::vector<std::string> vect_joueur;



public:
  Joueur(int posX, int  posY);

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

};


#endif
