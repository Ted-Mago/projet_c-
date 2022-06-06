#ifndef PAKU_HPP
#define  PAKU_HPP
#include "Recompense.hpp"
#include "Mur.hpp"
#include <memory>



class Paku: public Recompense{
public:
  Paku(const int& posx, const int& posy);
  Cercle& getCercle_paku(){ return cercle_paku;}
  const Cercle& getCercle_paku() const { return cercle_paku;}
// void afficher(sf::RenderWindow& r);
  bool collision(const Mur& m);


private:
  const std::string img_name="res/paku.png";
  Cercle cercle_paku;

};

typedef std::shared_ptr<Paku> paku_ptr;


#endif
