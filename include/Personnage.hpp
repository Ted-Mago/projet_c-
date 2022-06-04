#pragma region include
#ifndef PERSO_HPP
#define PERSO_HPP
#include "Arme.hpp"
#include "ObjetDynamique.hpp"
#define size_perso 100
#pragma endregion include

class Personnage: public ObjetDynamique{
protected:
  //Arme arme;
public:
//  virtual afficher(Ui ui&);
  virtual void seDeplacer()=0;
  virtual void update()=0;
  //virtual void cacher()=0;
};

#endif
