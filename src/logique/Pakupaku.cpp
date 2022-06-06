#include "../../include/Pakupaku.hpp"
#include <iostream>

Paku::Paku(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  niveauDeVie=10000;
  cercle_paku=*(new Cercle(posX, posY, size_paku/2));
  image= *(new Image(img_name, 0, 0, size_paku, size_paku, posX, posY));
}

bool Paku::collision(const Mur& m){
  if(cercle_paku.collision(m.getCarre_mur())){
    if(posX+m.getCarre_mur().getCote()<size_win && posY-m.getCarre_mur().getCote()>0){
      setPosX(posX+m.getCarre_mur().getCote());
      setPosY(posY-m.getCarre_mur().getCote());
    }
    else if (posX-m.getCarre_mur().getCote()<0 && posY+m.getCarre_mur().getCote()>size_win){
      setPosX(posX-m.getCarre_mur().getCote());
      setPosY(posY+m.getCarre_mur().getCote());
    }
    else niveauDeVie=0;
    cercle_paku.move(posX, posY);
    image.setPosition(posX, posY);
    return true;
  }
  else return false;
}
