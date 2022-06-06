#include "../../include/Pakupaku.hpp"

Paku::Paku(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  niveauDeVie=10000;
  cercle_paku=*(new Cercle(posX, posY, size_paku));
  image= *(new Image(img_name, 0, 0, size_paku, size_paku, posX, posY));
}
