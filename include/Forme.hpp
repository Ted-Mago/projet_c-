#ifndef FORME_HPP
#define FORME_HPP

#include <memory>

class Forme{
protected:
  int posX;
  int posY;
public:

  const int& getPosX() const {return posX;}
  const int& getPosY() const {return posY;}
  int& getPosX(){ return posX;}
  int& getPosY(){ return posY;}


};

typedef std::shared_ptr<Forme> forme_ptr;


#endif
