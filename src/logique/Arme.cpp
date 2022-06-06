#include "../../include/Arme.hpp"
#include <iostream>

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
    if(projectiles[i]->getNiveauDeVie()==0){projectiles.erase(projectiles.begin()+i);}
    else  projectiles[i]->update();
    }
}

Arme::Arme(const int& posx, const int& posy, Munition munition, Image image){
posX=posx;
posY=posy;
nbr_munitions=4;
this->munition=munition;
this->image=image;
direction=0;
niveauDeVie=1000;
  time(&last_tir);
}
Arme::Arme(const int& posx, const int& posy){

  posX=posx;
  posY=posy;
  nbr_munitions=4;
  munition=*(new Munition(posx, posy));
  image= *(new Image(arm_img_name, 0, 0, size_arm, size_arm, posX, posY));
  time(&last_tir);

//  delete m;
};

void Arme::afficher(sf::RenderWindow& r){

    for(int i=0; i<projectiles.size(); i++){
        projectiles[i]->update();
      projectiles[i]->afficher(r);
    }
      r.draw(image.get_sprite());
  }

bool Arme::tir(int i){
  time(&t_entre_tir);
  if(nbr_munitions>0 && abs(difftime(t_entre_tir, last_tir))>t_pause){
    time(&last_tir);
    munition_ptr projectile=std::make_shared<Munition>(munition);
    projectile->setDirection(i);
    projectiles.push_back(projectile);

    nbr_moins();
    return true;
  }
  else return false;

}
