#ifndef PERSO_HPP
#define PERSO_HPP
#include "Arme.hpp"
#include "ObjetDynamique.hpp"

/**

 * @file	ObjetFixe.hpp
 * @brief	contient la classe des objets fixe;
 * @author Teddy Magoga
 <teddy.magoga@etu.sorbonne-universite.fr>
 * @note fait appel à du SFML pour l'affichage
 * @date	2022
 * @copyright	droits reservés aux élèves de Polytech.
*/


class Personnage: public ObjetDynamique{
protected:
  Arme arme;
public:
  void afficher(sf::RenderWindow &r);


  virtual void seDeplacer()=0;
  virtual void update()=0;
  //virtual void cacher()=0;

  //accesseur
  Arme& getArme(){ return arme;}

};

#endif
