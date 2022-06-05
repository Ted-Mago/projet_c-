#ifndef FORME_HPP
#define FORME_HPP

#include <memory>

class Cercle;
class Carre;

class Forme{
protected:
  int posX;
  int posY;
public:

  const int& getPosX() const {return posX;}
  const int& getPosY() const {return posY;}
  int& getPosX(){ return posX;}
  int& getPosY(){ return posY;}
  bool collision(const Cercle& c) const;
  bool collision(const Carre& c) const;
  void setPosX(const int& posx){posX=posx;}
  void setPosY(const int& posy){ posY=posy;}
  void move(const int& posx, const int& posy){posX=posx; posY=posy;}


};

typedef std::shared_ptr<Forme> forme_ptr;


#endif
