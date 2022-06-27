#ifndef REC_HPP
#define REC_HPP
#include "ObjetFixe.hpp"
#include "Cercle.hpp"


/**

 * @file	ObjetFixe.hpp
 * @brief	contient la classe des objets fixe;
 * @author Teddy Magoga
 <teddy.magoga@etu.sorbonne-universite.fr>
 * @note fait appel à du SFML pour l'affichage
 * @date	2022
 * @copyright	droits reservés aux élèves de Polytech.
*/

class Recompense: public ObjetFixe {
protected:
  int val;
public:
  int getVal(){ return val;}
  const int& getVal() const {return val;}
  //virtual void addRec(const int& posx, const int& posy)=0;


};

#endif
