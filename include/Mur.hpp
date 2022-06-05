#ifndef MUR_HPP
#define MUR_HPP
#include "Environnement.hpp"
#include "Carre.hpp"

class Mur: public Env{
public:
  Mur(const int& posx, const int& posy);
  Carre carre_mur;
private:
  const std::string img_name="res/mur.png";
};

#endif
