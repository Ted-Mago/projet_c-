#ifndef OBJET_HPP
#define OBJET_HPP
#include "SFML/Graphics.hpp"
#include "Image.hpp"
#include "Forme.hpp"



class Objet{
protected:
  int posX;
  int posY;
  float niveauDeVie;
  Image image;

public:
  //accesseur
  int getPosX(){return posX;}
  int getPosY(){return posY;}
  const int& getPosX() const{return posX;}
  const int& getPosY() const{ return posY;}
  float getNiveauDeVie() {return niveauDeVie;}
  const float& getNiveauDeVie() const {return niveauDeVie;}
  const Image& getImage() const { return image;}
  void setPosX(const int& posx){this->posX=posx;}
  void setPosY(const int& posy){this->posY=posy;}




  //virtual void afficher(sf::RenderWindow &r)=0;
  //virtual void cacher(Ui ui&);

  //methode

  //virtual void update()=0;
  //virtual void afficher()=0;

};

typedef std::shared_ptr<Objet> objet_ptr;

#endif
