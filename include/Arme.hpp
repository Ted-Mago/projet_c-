#ifndef ARME_HPP
#define ARME_HPP
#include "ObjetDynamique.hpp"
#include "Munition.hpp"
#include "Image.hpp"
#include <vector>
#include <ctime>

/**

 * @file	ObjetFixe.hpp
 * @brief	contient la classe des objets fixe;
 * @author Teddy Magoga
 <teddy.magoga@etu.sorbonne-universite.fr>
 * @note fait appel à du SFML pour l'affichage
 * @date	2022
 * @copyright	droits reservés aux élèves de Polytech.
*/

class Arme: public ObjetDynamique{
protected:
    Munition munition;
    int nbr_munitions;
    int direction;
    std::vector<Munition*> projectiles; //bal tiré
    time_t t_entre_tir;
    time_t last_tir; //temps du dernier tir
    int nbr_tir;

public:
    Arme(const int& posx, const int& posy);
    Arme()=default;

    void seDeplacer();
    void seDeplacer(const int& posx, const int& posy);
    bool tir(int i);
    void update();
    void afficher(sf::RenderWindow& r);
    void nbr_plus(){ nbr_munitions=+1;}
    void nbr_moins(){ nbr_munitions-=1;}

    //accecseur
    Munition& getMunition(){ return munition;}
    const Munition& getMunition() const{ return munition;}
    const Munition* getMunition_t(int i) const{return projectiles[i];}

    void setNbr_muni(int nbr){ nbr_munitions=nbr;}
    int getDirection(){return direction;}
    void setDirection(int dir){ direction=dir;}
    int getNbr_tir(){return nbr_tir;}


};

#endif
