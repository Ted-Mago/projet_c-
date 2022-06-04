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
  forme_ptr forme;

public:
  //accesseur
  int getPosX(){return posX;}
  int getPosY(){return posY;}
  const int& getPosX() const{return posX;}
  const int& getPosY() const{ return posY;}
  float getNiveauDeVie() {return niveauDeVie;}
  const float& getNiveauDeVie() const {return niveauDeVie;}
  const Image& getImage() const { return image;}
  const forme_ptr getForme() const { return forme;}



  //virtual void afficher(Ui ui&);
  //virtual void cacher(Ui ui&);

  //methode

  //virtual void update()=0;
  //virtual void afficher()=0;

};

typedef std::shared_ptr<Objet> objet_ptr;

#endif
