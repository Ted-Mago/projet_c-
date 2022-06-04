#ifndef OBJETF_HPP
#define OBJETF_HPP
#include "SFML/Graphics.hpp"
#include "Objet.hpp"

class ObjetFixe: public Objet{

public:
//  virtual void update()=0;
  //void addObF(objetF_ptr o);

};

typedef std::shared_ptr<ObjetFixe> objetF_ptr;

#endif
