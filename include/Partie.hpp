#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "SFML/Graphics.hpp"
#include "configuration.hpp"
#include "Image.hpp"
#include "Objet.hpp"
#include "ObjetDynamique.hpp"
#include "ObjetFixe.hpp"
#include "Personnage.hpp"
#include "Recompense.hpp"
#include "Commande.hpp"
#include "Arme.hpp"
#include "Munition.hpp"
#include "Joueur.hpp"
#include "Pakupaku.hpp"
#include "Mur.hpp"
#include "Ennemi.hpp"
#include <vector>
#include <ctime>



class Partie{
private:
  std::vector<joueur_ptr> mes_joueurs;
  std::vector<paku_ptr> mes_paku;
  std::vector<mur_ptr> mes_murs;
  std::vector<Commande> mes_cmd;
  std::vector<en_ptr> mes_fantomes;
  //std::vector<munition_ptr>&mes_munitions;
  bool _status;
  int nbr_j;
  int nbr_paku=14;

public:
  Partie(){
    /*création commande*/
    Commande cmd(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::M );
      mes_cmd.push_back(cmd);
    Commande cmd2(sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z, sf::Keyboard::W, sf::Keyboard::A );

    mes_cmd.push_back(cmd2);

    joueur_ptr j1=std::make_shared<Joueur>(550,240, j1_img);
    joueur_ptr j2=std::make_shared<Joueur>(40,240, j2_img );
    mes_joueurs.push_back(j1);
    mes_joueurs.push_back(j2);
    nbr_j=2;
    _status=true;



  }


  void init();
  void creerCarte();
  bool encours();
  void afficher(sf::RenderWindow &r);
  void update();
  void fin(sf::RenderWindow& r);
  void collision();
  void action1();
  void action2();
  void partie(sf::RenderWindow& r);


};

#endif
