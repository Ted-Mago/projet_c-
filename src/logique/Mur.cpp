#include "../../include/Mur.hpp"

Mur::Mur(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  niveauDeVie=10000;
  carre_mur=*(new Carre(posX, posY, 100));
  image= *(new Image(img_name, 0, 0, 100, 100, posX, posY));

}
