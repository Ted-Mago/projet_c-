#ifndef MUNITION_HPP
#define MUNITION_HPP
#include "ObjetDynamique.hpp"
#include "SFML/Graphics.hpp"
#include "Cercle.hpp"
#include "Mur.hpp"




class Munition: public ObjetDynamique {
protected:
  float chargeDest;
  Cercle cercle_min;
  int direction;
  bool coll=false;
public:

  Munition(const int& posx, const int& posy);
  Munition(const Munition& m);
  Munition()=default;

  void seDeplacer();
  void update();
  void afficher(sf::RenderWindow &r);
  bool collision(const Mur& m);
  bool collision(Munition& m);


  const Cercle& getCercle_min() const{return cercle_min;}
  Cercle getCercle_min(){return cercle_min;}

  int getDirection(){ return direction;}
  const int& getDirection() const{ return direction;}

  void setDirection(int i){direction=i;};

  float getChargeDest(){return chargeDest;}
  const float& getChargeDest() const{ return chargeDest;}

  void setColl(bool b){ coll=b;}

  bool getColl(){ return coll;}


};

typedef std::shared_ptr<Munition> munition_ptr;



#endif
