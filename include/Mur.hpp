#ifndef MUR_HPP
#define MUR_HPP
#include "Environnement.hpp"
#include "Carre.hpp"





class Mur: public Env{
public:
  Mur(const int& posx, const int& posy);

  Carre getCarre_mur(){return carre_mur;}
  const Carre& getCarre_mur() const{return carre_mur;}
private:
  const std::string img_name="res/mur.png";
  Carre carre_mur;
};
typedef std::shared_ptr<Mur> mur_ptr;

#endif
