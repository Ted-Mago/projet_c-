#include "../../include/Ennemi.hpp"

Ennemi::Ennemi(const int& posx, const int& posy){
  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=1;
  vitesseY=1;
  image= *(new Image(img_name, 0, 0, 0, 0, posX, posY));
  arme=*(new Arme(posX, posY));
  carre_en=*(new Carre(posX, posY, 8));
  //arme
}

void Ennemi::seDeplacer(){
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  int random_variable = std::rand();
  switch (random_variable%4) {
    case 0:
      posX=posX-vitesseX;
      break;
    case 1:
      posX=posX+vitesseX;
      break;
    case 3:
      posY=posY-vitesseY;
        break;
    case 4:
      posY=posY+vitesseY;
      break;

  }
  image.setPosition(posX, posY);


}

void Ennemi::update(){
  this->seDeplacer();
}
