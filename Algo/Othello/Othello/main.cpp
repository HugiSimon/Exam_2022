#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "Menu.h"
#include "Affichage.h"
#include "Verification.h"
#include "Poser.h"

int main() {

	int plateau[8][8] = {}; // Créer le plateau
	plateau[3][3] = 1; // Position de base
	plateau[4][4] = 1;

	plateau[3][4] = 2;
	plateau[4][3] = 2;

	Menu Home;

	Home.ChoixInit(); // Menu du jeu, pose toutes les questions aux joueurs

	Affichage Affichage(Home.ReturnCouleur(1), Home.ReturnCouleur(2)); // Créer l'affichage avec les couleurs des joueurs

	Verification Verif;
	Poser Pose;

	int* possibilite[1024]; // Créer le tableau où tout les mouvements possibles seront stockés

	int peutJouer = 0; // Variable s'incrément à chaque fois qu'un joueur peut pas jouer et se reset à chaque fois qu'on peut jouer

	while (Home.Run()) { // Boucle principal du gameplay
		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2)); // Affiche le plateau // Home.ReturnConsole() pour avoir la console et Hole.ReturnNom pour les noms des joueurs

		Verif.ToutesPossibilte(plateau, 1, possibilite); // Créer le tableau des mouvements possibles pour le joueur 1
		if (Verif.PeutJouer()) { // Si le joueur 1 peut jouer
			Pose.PoserPions(plateau, possibilite, 1); // Pose les pions
			peutJouer = 0;
		}
		else {
			peutJouer++;
		}
		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2)); // Reaffiche le plateau

		Verif.ToutesPossibilte(plateau, 2, possibilite); // Créer le tableau des mouvements possibles pour le joueur 2
		if (Verif.PeutJouer()) { // Si le joueur 2 peut jouer
			peutJouer = 0;

			if (Home.ReturnJoueurBot()) { // Si le joueur 2 est un bot
				Pose.PoserBot(plateau, possibilite); // Pose le pion du bot
			}
			else {
				Pose.PoserPions(plateau, possibilite, 2); // Pose les pions
			}
		}
		else {
			peutJouer++;
		}

		if (peutJouer >= 2) { // Si les deux joueurs ne peuvent pas jouer
			Home.ChangeRun(false); // Arrête le jeu
		}
	}

	return 0;
}