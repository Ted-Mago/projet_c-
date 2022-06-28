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
/*

 for(int i=0; i<3; i++){

   mur_ptr mur=std::make_shared<Mur>((i+1)*2*size_mur, size_mur*2);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*3+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
   nbr_paku++;
 }

 for(int i=0; i<5; i++){

   mur_ptr mur=std::make_shared<Mur>((3/2+i)*3*size_mur/2, size_mur*4);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*5+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
    nbr_paku++;
 }

 for(int i=0; i<3; i++){

   mur_ptr mur=std::make_shared<Mur>((i+1)*2*size_mur, size_mur*6);
   paku_ptr paku= std::make_shared<Paku>((i+1)*size_mur, size_mur*7+2*size_paku);
   mes_murs.push_back(mur);
   mes_paku.push_back(paku);
    nbr_paku++;
 }
 for(int i=0; i< 6; i++){
    paku_ptr paku= std::make_shared<Paku>((i+2)*size_mur, size_mur);
    mes_paku.push_back(paku);
    nbr_paku++;
 }*/


 for( int i=0; i<5; i++)
  for(int j=0; j<5; j++){
    if(j%2==0 )
    {mur_ptr mur=std::make_shared<Mur>(20+i*170, 20+j*170);
  //  else   mur_ptr mur=std::make_shared<Mur>(60+i*170, 60+j*170);
    nbr_paku++;
    mes_murs.push_back(mur);}

    else if(j%2==1 && i%2==1){
      mur_ptr mur=std::make_shared<Mur>(20+i*170, 20+j*170);
      nbr_paku++;
      mes_murs.push_back(mur);

    }
  }

}
void Partie::init() {
  creerCarte();

  /*création fantomes*/

  for( int i=0; i<6; i++){
    en_ptr fantome=std::make_shared<Ennemi>(size_mur+i*size_mur, size_mur*i-size_jo*i%2);
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

    }

    for(int j=0; j<mes_fantomes.size(); j++){
      mes_joueurs[i]->collision(*mes_fantomes[j]);
    }



  }

  for(int j=0; j<mes_joueurs[0]->getArme().getNbr_tir(); j++){
    mes_joueurs[1]->collision(mes_joueurs[0]->getArme().getMunition_t(j));
  }

  for(int j=0; j<mes_joueurs[1]->getArme().getNbr_tir(); j++){
    mes_joueurs[0]->collision(mes_joueurs[1]->getArme().getMunition_t(j));
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
    sf::Text score;
    score.setFont(font);
    if(mes_joueurs[0]->getScore()>mes_joueurs[1]->getScore())
      score.setString(std::to_string(mes_joueurs[0]->getScore()));
    else score.setString(std::to_string(mes_joueurs[1]->getScore()));
    sf::Text text;

    text.setFont(font);
    text.setString("Win Win!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    score.setCharacterSize(16);
    score.setFillColor(sf::Color::Yellow);
    score.setPosition(100,100);

    r.draw(text);
    r.draw(score);
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
    mes_murs[i]->afficher(r);
 //mes_murs[i]->getCarre_mur().afficher(r);
  }
  for(int i=0; i<mes_fantomes.size(); i++){
    mes_fantomes[i]->afficher(r);
   //mes_fantomes[i]->getCarre_en().afficher(r);

  }
  for(int i=0; i<mes_joueurs.size(); i++){
    mes_joueurs[i]->afficher(r);
  //mes_joueurs[i]->getCercle_j().afficher(r);
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
