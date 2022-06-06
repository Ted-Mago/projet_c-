#include "../../include/Ennemi.hpp"

Ennemi::Ennemi(const int& posx, const int& posy){
  this->posX=posx;
  this->posY=posy;
  niveauDeVie=100;
  vitesseX=1;
  vitesseY=1;
  image= *(new Image(img_name, 0, 0, size_en, size_en, posX, posY));
  arme=*(new Arme(posX+size_en, posY+size_en));
  carre_en=*(new Carre(posX, posY, size_en));
  //arme
}

void Ennemi::seDeplacer(){
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  int random_variable = std::rand();
  switch (random_variable%4) {
    case 0:
      if(posX>0)
        posX=posX-vitesseX;
      else posX=size_win;
      break;
    case 1:
      if(posX<size_win)
        posX=posX+vitesseX;
      else posX=0;
      break;
    case 3:
      if(posY>0)
        posY=posY-vitesseY;
      else posY=size_win;
      break;
    case 4:
      if(posY<size_win)
        posY=posY+vitesseY;
      else posY=0;
      break;

  }

  image.setPosition(posX, posY);
  arme.seDeplacer(posX+size_en, posY+size_en);
  carre_en.move(posX, posY);


}

void Ennemi::update(){
  this->seDeplacer();
}
