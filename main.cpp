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
   Image *a= new Image("arme.png", 0,56, 48, 48, x, y);
   Image *b=new Image ("arme2.png",45,0, 48, 48, y, x);
   Image i("pelose.jpg", 0, 0, 800, 800, 0, 0);

   time_t t;
   Image &ref_a=*a;
   time(&t);
   Paku pp(100, 100);
   Mur mm(500, 200);
   Munition muni(12, 600);
   Cercle cc1(11, 100, 8);
   Cercle cc2(12, 100, 5);
   Cercle cc3(100, 1, 8);
   Joueur joueur1(0, 100);
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
        if( commande.actionned(joueur1) )

        std::cout<<joueur1.getPosX() << " "<< joueur1.getPosY()<<std::endl;
        if(commande2.actionned(joueur2))
          std::cout<<joueur2.getPosX() << " "<< joueur2.getPosY()<<std::endl;
        // Clear screen
        en.update();
        app.clear();

        // Draw the sprite
        app.draw(i.get_sprite());
        pp.afficher(app);
        mm.afficher(app);
        app.draw(en.getImage().get_sprite());

        joueur1.afficher(app);
          app.draw(joueur2.getImage().get_sprite());
          muni.afficher(app);

        app.draw(b->get_sprite());

        //joueur1.getImage().setPosition(x, y);

        std::cout<<cc1.collision(cc2)<<" "<<cc2.collision(cc1)<<" "<<cc3.collision(cc1)<<std::endl;


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
