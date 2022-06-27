#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include "Personnage.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "Ennemi.hpp"
#include "Pakupaku.hpp"
#include "Munition.hpp"
#include "Mur.hpp"
#include <ctime>
#include <vector>

/**

 * @file	ObjetFixe.hpp
 * @brief	contient la classe des objets fixe;
 * @author Teddy Magoga
 <teddy.magoga@etu.sorbonne-universite.fr>
 * @note fait appel à du SFML pour l'affichage
 * @date	2022
 * @copyright	droits reservés aux élèves de Polytech.
*/

class Joueur: public Personnage{
protected:

  int direction=0;
  int score;
  int last_dir=0;
  //Pour tirer
  Cercle cercle_j;
  time_t last_col;
  time_t col_time;





public:

  Joueur(int posX, int  posY, std::string s);

  void seDeplacer();

  bool attaquer();

  void update();

//collision
  bool collision(Joueur& j);
  bool collision(const Ennemi& e);
  bool collision(Munition& m);
  bool collision(const Mur& m);
  bool collision(Paku& p);

//accesseur
  void setDirection(const int& direction){ this->direction=direction;}
  int getDirection(){ return direction;}
  Cercle getCercle_j(){return cercle_j;}
  const Cercle& getCercle_j() const { return cercle_j;}
  const int& getScore() const{ return score;}

};
typedef std::shared_ptr<Joueur> joueur_ptr;



#endif
