#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Personnage.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "Ennemi.hpp"
#include "Pakupaku.hpp"
#include "Munition.hpp"
#include "Mur.hpp"
//#include "Arme.hpp"
//#include "Commande.hpp"
#include <vector>
//#define img_name "enb.png"


class Joueur: public Personnage{
protected:

  int direction=0;
  int score;
  int last_dir=0;
  //Arme arme;
  const std::string img_name="res/player.png";
  static std::vector<std::string> vect_joueur;
  Cercle cercle_j;



public:
  Joueur(int posX, int  posY);

  void seDeplacer();

  void attaquer();
//  void afficher(Ui ui&);
  //void seBlesser( Munition m&);
  void update();
  //void cacher();
//  void changerArme(Arme a);
//collision
  bool collision(const Joueur& j);
  bool collision(const Ennemi& e);
  bool collision(Munition& m);
  bool collision(const Mur& m);
  bool collision(Paku& p);

//accesseur
  void setDirection(const int& direction){ this->direction=direction;}
  int getDirection(){ return direction;}
  Cercle getCercle_j(){return cercle_j;}
  const Cercle& getCercle_j() const { return cercle_j;}

};


#endif
