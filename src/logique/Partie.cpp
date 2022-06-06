#include "../../include/Partie.hpp"
#include <iostream>

void Partie::creerCarte(){
  /*initialisation des murs de cloture*/
 for(int i=0; i<8; i++){
   mur_ptr mur=std::make_shared<Mur>(size_mur*i, 0-2*size_mur/3);
   mes_murs.push_back(mur);
 }
 for(int i=0; i<8; i++){
   mur_ptr mur=std::make_shared<Mur>( 0-2*size_mur/3,size_mur*i);
   mes_murs.push_back(mur);
 }
 for(int i=0; i<8; i++){
   mur_ptr mur=std::make_shared<Mur>( size_win-size_mur/4,size_mur*i);
   mes_murs.push_back(mur);
 }
 for(int i=0; i<8; i++){
   mur_ptr mur=std::make_shared<Mur>(size_mur*i,  size_win-size_mur/4);
   mes_murs.push_back(mur);
 }
 /*mur aleatoire et paku*/


 for(int i=0; i<3; i++){

   mur_ptr mur=std::make_shared<Mur>((i+1)*2*size_mur, size_mur*2);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*3+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
 }

 for(int i=0; i<5; i++){

   mur_ptr mur=std::make_shared<Mur>((3/2+i)*3*size_mur/2, size_mur*4);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*5+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
 }

 for(int i=0; i<3; i++){

   mur_ptr mur=std::make_shared<Mur>((i+1)*2*size_mur, size_mur*6);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*7+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
 }
 for(int i=0; i< 3; i++){
    paku_ptr paku= std::make_shared<Paku>((i+2)*size_mur, size_mur);
    mes_paku.push_back(paku);
 }
}
void Partie::init() {
  creerCarte();

  /*création fantomes*/

  for( int i=0; i<6; i++){
    en_ptr fantome=std::make_shared<Ennemi>((i+1)*2*size_mur, size_mur*3);
    mes_fantomes.push_back(fantome);
  }





}

void Partie::collision(){
  mes_joueurs[0]->collision(*mes_joueurs[1]);

  for(int i=0; i<mes_joueurs.size(); i++){

    for(int j=0; j<mes_murs.size(); j++)
      mes_joueurs[i]->collision(*mes_murs[j]);

    for(int j=0; j<mes_paku.size(); j++){
      if(mes_joueurs[i]->collision(*mes_paku[j]))
        nbr_paku--;
        std::cout<<nbr_paku<<std::endl;
    }

    for(int j=0; j<mes_fantomes.size(); j++){
      mes_joueurs[i]->collision(*mes_fantomes[j]);
    }

  }




}

void Partie::update(){
  for(int i=0; i<mes_paku.size(); i++){
    if(mes_paku[i]->getNiveauDeVie()<=0)
      mes_paku.erase(mes_paku.begin()+i);
    ;}
  for(int i=0; i<mes_fantomes.size(); i++){

     mes_fantomes[i]->update();
  }
  for(int i=0; i<mes_joueurs.size(); i++){
    if(mes_joueurs[i]->getNiveauDeVie()<=0)
      nbr_j=0;
      else mes_joueurs[i]->update();
  }
  nbr_j=mes_joueurs.size();

}

bool Partie::encours(){
  if(mes_joueurs[0]->getNiveauDeVie()<=0 || mes_joueurs[1]->getNiveauDeVie()<=0 || nbr_paku<=0)
    return false;
  else return true;

}

void Partie::fin(sf::RenderWindow &r){
  sf::Font font;
  font.loadFromFile("res/arial.ttf");
  if(nbr_paku<=0){
    r.clear();
    sf::Text text;

    text.setFont(font);
    text.setString("Win Win!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    r.draw(text);
  }
   else {
     r.clear();
     sf::Text text;

     text.setFont(font);
     text.setString("LOOSERS");
     text.setCharacterSize(24);
     text.setFillColor(sf::Color::Red);
     r.draw(text);
   }


}
void Partie::afficher(sf::RenderWindow& r){
  if(mes_paku.size()>0)
  for(int i=0; i<mes_paku.size(); i++){
    mes_paku[i]->afficher(r);}
  for(int i=0; i<mes_murs.size(); i++){
    mes_murs[i]->afficher(r);}
  for(int i=0; i<mes_fantomes.size(); i++){
    mes_fantomes[i]->afficher(r);
  }
  for(int i=0; i<mes_joueurs.size(); i++){
    mes_joueurs[i]->afficher(r);
  }

}

void Partie::action1(){
  mes_cmd[0].actionned(*mes_joueurs[0]);

}
void Partie::action2(){
  mes_cmd[1].actionned(*mes_joueurs[1]);
}

void Partie::partie(sf::RenderWindow& r){
  if(_status){
    r.clear();
    action1();
    action2();
    collision();
    update();
    _status=encours();
    afficher(r);
    r.display();
    } else{
  
  r.clear();
  fin(r);
  r.display();
  }

}
