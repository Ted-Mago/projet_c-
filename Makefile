CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES=main

all: $(EXES)

main: main.o Image.o Commande.o Arme.o Munition.o Pakupaku.o  Joueur.o Carre.o Cercle.o Mur.o Ennemi.o Personnage.o
	$(CPP) $(CPPFLAGS) main.o Cercle.o Carre.o Arme.o Munition.o Image.o Pakupaku.o  Joueur.o Commande.o Mur.o Ennemi.o Personnage.o -o main $(LIBS)
main.o: main.cpp include/Image.hpp include/Commande.hpp include/Arme.hpp include/Munition.hpp include/Pakupaku.hpp include/Carre.hpp include/Mur.hpp include/Ennemi.hpp include/Personnage.hpp include/Cercle.hpp include/Joueur.hpp
		$(CPP) $(CPPFLAGS) -c main.cpp $(LIBS)
Commande.o: src/logique/Commande.cpp  include/Commande.hpp include/Joueur.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Commande.cpp $(LIBS)
Image.o: src/logique/Image.cpp include/Image.hpp
		$(CPP) $(CPPFLAGS) -c src/logique/Image.cpp $(LIBS)

Joueur.o: src/logique/Joueur.cpp include/Joueur.hpp include/Personnage.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Carre.hpp include/Pakupaku.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Joueur.cpp $(LIBS)
Arme.o: src/logique/Arme.cpp include/Arme.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Carre.hpp include/Munition.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Arme.cpp $(LIBS)
Pakupaku.o: src/logique/Pakupaku.cpp include/Pakupaku.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Pakupaku.cpp $(LIBS)
Munition.o: src/logique/Munition.cpp include/Munition.hpp include/ObjetDynamique.hpp include/Objet.hpp include/Forme.hpp include/Cercle.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Munition.cpp $(LIBS)


Mur.o: src/logique/Mur.cpp include/Mur.hpp include/Carre.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Mur.cpp $(LIBS)
Ennemi.o: src/logique/Ennemi.cpp include/Personnage.hpp include/Ennemi.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Ennemi.cpp $(LIBS)
Personnage.o: src/logique/Personnage.cpp include/Personnage.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Personnage.cpp $(LIBS)

Cercle.o: src/logique/Cercle.cpp include/Cercle.hpp include/Carre.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Cercle.cpp $(LIBS)

Carre.o: src/logique/Carre.cpp include/Carre.hpp
	$(CPP) $(CPPFLAGS) -c src/logique/Carre.cpp $(LIBS)







clean:
	rm -f *.o $(EXES)
