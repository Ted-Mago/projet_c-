#include "../../include/Ennemi.hpp"

Ennemi::Ennemi(const int& posx, const int& posy){
  this->posX=posX;
  this->posY=posY;
  niveauDeVie=100;
  vitesseX=1;
  vitesseY=1;
  image= *(new Image(img_name, 0, 0, 0, 0, posX, posY));
  arme=*(new Arme(posX+26, posY+26));
  carre_en=*(new Carre(posX, posY, 8));
  //arme
}

void Ennemi::seDeplacer(){
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  int random_variable = std::rand();
  switch (random_variable%4) {
    case 0:
      if(posX>0)
        posX=posX-vitesseX;
      else posX=800;
      break;
    case 1:
      if(posX<800)
        posX=posX+vitesseX;
      else posX=0;
      break;
    case 3:
      if(posY>0)
        posY=posY-vitesseY;
      else posY=800;
      break;
    case 4:
      if(posY<800)
        posY=posY+vitesseY;
      else posY=0;
      break;

  }

  image.setPosition(posX, posY);
  arme.seDeplacer(posX+26, posY+26);
  carre_en.move(posX, posY);


}

void Ennemi::update(){
  this->seDeplacer();
}
