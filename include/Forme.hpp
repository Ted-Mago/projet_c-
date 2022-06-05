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


};

typedef std::shared_ptr<Forme> forme_ptr;


#endif
