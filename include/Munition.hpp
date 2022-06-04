#ifndef MUNITION_HPP
#define MUNITION_HPP
#include "ObjetDynamique.hpp"
#include "SFML/Graphics.hpp"
#include "Cercle.hpp"


//class Joueur;
class Munition: public ObjetDynamique {
protected:
  float chargeDest;
public:
  Munition(int posX, int posY, float chargeDest){
    this->posX=posX;
    this->posY=posY;
    this->chargeDest=chargeDest;
    this->forme=std::make_shared<Cercle>(posX, posY, 5);
  };

  Munition();
  //~Munition();
  void seDeplacer();
  void update();

//  void blesserEnnemi(Joueur j);


};

typedef std::shared_ptr<Munition> munition_ptr;



#endif
