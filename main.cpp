#include "SFML/Graphics.hpp"
#include "include/Image.hpp"
#include "include/Commande.hpp"
#include "include/Arme.hpp"
#include "include/Munition.hpp"
#include "include/Joueur.hpp"
#include "include/Pakupaku.hpp"
#include "include/Mur.hpp"
#include "include/Ennemi.hpp"
#include "include/Partie.hpp"
#include <ctime>



int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(size_win, size_win), "Partie");
    app.setFramerateLimit(60);

    Partie *p= new Partie();
    Partie par=*p;
    par.init();





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
        par.partie(app);
    }
    delete p;
    return EXIT_SUCCESS;
}
