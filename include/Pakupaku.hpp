#ifndef PAKU_HPP
#define  PAKU_HPP
#include "Recompense.hpp"
#include <memory>
#define VAL_PAKU 2


class Paku: public Recompense{
public:
  Paku(const int& posx, const int& posy);
  Cercle cercle_paku;
// void afficher(sf::RenderWindow& r);
private:
  const std::string img_name="res/paku.png";
};

#endif
