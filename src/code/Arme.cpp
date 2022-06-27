#include "../../include/Arme.hpp"
#include <iostream>

Arme::Arme(const int& posx, const int& posy){

    posX=posx;
    posY=posy;
    nbr_munitions=4;
    munition=*(new Munition(posx, posy));
    image= *(new Image(arm_img_name, 0, 0, size_arm, size_arm, posX, posY));
    time(&last_tir);

};

void Arme::seDeplacer(){
    image.setPosition(posX, posY);
    munition.setPosX(posX);
    munition.setPosY(posY);
}

void Arme::seDeplacer(const int& posx, const int& posy ){

    posX=posx;
    posY=posy;
    seDeplacer();

}


void Arme::update(){


    this->seDeplacer(posX, posY);

    for(int i=0; i<projectiles.size(); i++){
      if(projectiles[i]->getNiveauDeVie()==0){
        delete projectiles[i];
        projectiles.erase(projectiles.begin()+i);
      }

    else  projectiles[i]->update();
    }
}




void Arme::afficher(sf::RenderWindow& r){

    for(int i=0; i<projectiles.size(); i++){
        projectiles[i]->update();
      projectiles[i]->afficher(r);
    }
      r.draw(image.get_sprite());
  }

bool Arme::tir(int i){ //on récupere la direction du personnage

    time(&t_entre_tir);

    if(nbr_munitions>0 && abs(difftime(t_entre_tir, last_tir))>t_pause){ //vérification du dernier tir

      time(&last_tir);
      Munition* projectile=new Munition(munition);

      projectile->setDirection(i);
      projectiles.push_back(projectile);
      nbr_tir++;
      nbr_moins();

      return true;
    }
    else return false;

}
