#include "../../include/Mur.hpp"

Mur::Mur(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  niveauDeVie=10000;
  carre_mur=*(new Carre(posX, posY, size_mur));
  image= *(new Image(img_name, 0, 0, size_mur, size_mur, posX, posY));

}
