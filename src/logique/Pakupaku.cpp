#include "../../include/Pakupaku.hpp"

Paku::Paku(const int& posx, const int& posy){
  posX=posx;
  posY=posy;
  niveauDeVie=10000;
  cercle_paku=*(new Cercle(posX, posY, 16));
  image= *(new Image(img_name, 0, 0, 24, 24, posX, posY));
}

/*void Paku::afficher(sf::RenderWindow& r){
  r.draw(image.get_sprite());
}*/
