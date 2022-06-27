#ifndef OBJET_HPP
#define OBJET_HPP
#include "configuration.hpp"
#include "SFML/Graphics.hpp"
#include "Image.hpp"
#include "Forme.hpp"

/**

 * @file	Objet.hpp
 * @brief	classe dont tous les autres héritent, contient le coordonnées
 * @author Teddy Magoga
 <teddy.magoga@etu.sorbonne-universite.fr>
 * @note fait appel à du SFML pour l'affichage
 * @date	2022
 * @copyright	droits reservés aux élèves de Polytech.
*/

/**
 * @class	Objet
 * @brief	représente un objet
 *
 */


class Objet{

protected:
  int posX;
  int posY;
  float niveauDeVie; //de l'Objet 
  Image image;

public:
  //accesseur et Mutateur
  int getPosX(){return posX;}
  int getPosY(){return posY;}
  const int& getPosX() const{return posX;}
  const int& getPosY() const{ return posY;}

  float getNiveauDeVie() {return niveauDeVie;}
  const float& getNiveauDeVie() const {return niveauDeVie;}

  const Image& getImage() const { return image;}

  //Mutateurs
  void setPosX(const int& posx){this->posX=posx;}
  void setPosY(const int& posy){this->posY=posy;}

  void setNiveauDeVie(const float& ndv){ niveauDeVie=ndv;}



};

/**
 * @typedef	objet_ptr
 * @brief	smart pointer vers Objet
 *
 */

typedef std::shared_ptr<Objet> objet_ptr;

#endif
