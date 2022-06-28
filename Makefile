CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES=main

all: $(EXES)

main: main.o Image.o Commande.o Arme.o Munition.o Pakupaku.o  Joueur.o Carre.o Cercle.o Mur.o Ennemi.o Personnage.o Partie.o
	$(CPP) $(CPPFLAGS) main.o Cercle.o Carre.o Arme.o Munition.o Image.o Pakupaku.o  Joueur.o Commande.o Mur.o Ennemi.o Personnage.o Partie.o -o main $(LIBS)
main.o: main.cpp include/Image.hpp include/Commande.hpp include/Arme.hpp include/Munition.hpp include/Pakupaku.hpp include/Carre.hpp include/Mur.hpp include/Ennemi.hpp include/Personnage.hpp include/Cercle.hpp include/Joueur.hpp include/configuration.hpp include/Partie.hpp
		$(CPP) $(CPPFLAGS) -c main.cpp $(LIBS)
Commande.o: src/code/Commande.cpp  include/Commande.hpp include/Joueur.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Commande.cpp $(LIBS)
Image.o: src/code/Image.cpp include/Image.hpp include/configuration.hpp
		$(CPP) $(CPPFLAGS) -c src/code/Image.cpp $(LIBS)

Joueur.o: src/code/Joueur.cpp include/Joueur.hpp include/Personnage.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Carre.hpp include/Pakupaku.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Joueur.cpp $(LIBS)
Arme.o: src/code/Arme.cpp include/Arme.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Carre.hpp include/Munition.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Arme.cpp $(LIBS)
Pakupaku.o: src/code/Pakupaku.cpp include/Pakupaku.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Pakupaku.cpp $(LIBS)
Munition.o: src/code/Munition.cpp include/Munition.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Cercle.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Munition.cpp $(LIBS)


Mur.o: src/code/Mur.cpp include/Mur.hpp include/Carre.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Mur.cpp $(LIBS)
Ennemi.o: src/code/Ennemi.cpp include/Personnage.hpp include/Ennemi.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Ennemi.cpp $(LIBS)
Personnage.o: src/code/Personnage.cpp include/Personnage.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Personnage.cpp $(LIBS)

Cercle.o: src/code/Cercle.cpp include/Cercle.hpp include/Carre.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Cercle.cpp $(LIBS)

Carre.o: src/code/Carre.cpp include/Carre.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Carre.cpp $(LIBS)
Partie.o: src/code/Partie.cpp include/Partie.hpp include/configuration.hpp
	$(CPP) $(CPPFLAGS) -c src/code/Partie.cpp $(LIBS)








clean:
	rm -f *.o $(EXES)
