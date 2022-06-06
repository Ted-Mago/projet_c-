#include "SFML/Graphics.hpp"
#include "include/Image.hpp"
#include "include/Commande.hpp"
#include "include/Arme.hpp"
#include "include/Munition.hpp"
#include "include/Joueur.hpp"
#include "include/Pakupaku.hpp"
#include "include/Mur.hpp"
#include "include/Ennemi.hpp"
#include <ctime>



int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 800), "Partie");
    app.setFramerateLimit(60);

    // Load a sprite to display
    int x=120;
    int y=230;

   time_t t;
   time(&t);
   Paku pp(650, 650);
   Mur mm(600, 600);
   Munition muni(12, 600);
   Munition munii(400, 600);
   Cercle cc1(120, 99, 110);
   Cercle cc2(200, 100, 100);
   Cercle cc3(0, 1, 8);
   Carre car(120, 100, 100);
   Carre car1(300, 100, 100);
   Carre cr(0, 0, 8);
   Joueur joueur1(470, 208);
   Joueur joueur2(12, 200);
   Ennemi en(23, 200);


   Commande commande(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::A );
   Commande commande2(sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Z, sf::Keyboard::W, sf::Keyboard::S );

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();


        }
      commande.actionned(joueur1);

      //  std::cout<<joueur1.getPosX() << " "<< joueur1.getPosY()<<std::endl;
        commande2.actionned(joueur2);
          //std::cout<<joueur2.getPosX() << " "<< joueur2.getPosY()<<std::endl;
        // Clear screen
        en.update();
        app.clear();

        // Draw the sprite


        mm.afficher(app);
        pp.afficher(app);
        en.afficher(app);
        joueur1.collision(joueur2);
        joueur1.collision(en);
        joueur1.collision(muni);
        joueur1.collision(mm);
        joueur1.collision(pp);
        joueur1.afficher(app);
        joueur1.getCercle_j().afficherC(app);
        joueur2.getCercle_j().afficherC(app);
        joueur1.update();
        //joueur2.getArme().nbr_plus();
        joueur2.getArme().tir(2);
        muni.collision(munii);
        pp.collision(mm);
        mm.getCarre_mur().afficherC(app);
        car.afficherC(app);
        car1.afficherC(app);
        cr.afficherC(app);

          joueur2.afficher(app);
          muni.setDirection(2);
          muni.seDeplacer();
          muni.afficher(app);
          muni.getCercle_min().afficherC(app);




        //joueur1.getImage().setPosition(x, y);

      // std::cout<<cc1.collision(cc2)<<" "<<cc2.collision(cc1)<<" "<<cc3.collision(cc1)<<std::endl;
    //   std::cout<<car1.collision(car)<<" "<<car1.collision(car)<<" "<<car.collision(cr)<<std::endl;


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
