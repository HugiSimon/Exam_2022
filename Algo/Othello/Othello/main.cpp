#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "Menu.h"
#include "Affichage.h"
#include "Verification.h"
#include "Poser.h"

int main() {

	int plateau[8][8] = {};
	plateau[3][3] = 1;
	plateau[4][4] = 1;

	plateau[3][4] = 2;
	plateau[4][3] = 2;

	Menu Home;

	Home.ChoixInit();

	Affichage Affichage(Home.ReturnCouleur(1), Home.ReturnCouleur(2));

	Verification Verif;
	Poser Pose;

	int* possibilite[1024];
	int peutJouer = 0;

	while (Home.Run()) {
		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2), 10, 29);

		Verif.ToutesPossibilte(plateau, 1, possibilite);
		if (Verif.PeutJouer()) {
			Pose.PoserPions(plateau, possibilite, 1);
			peutJouer = 0;
		}
		else {
			peutJouer++;
		}

		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2), 10, 29);

		if (Home.ReturnJoueurBot()) {
			Sleep(1000);
		}
		else {
			Verif.ToutesPossibilte(plateau, 2, possibilite);
			if (Verif.PeutJouer()) {
				Pose.PoserPions(plateau, possibilite, 2);
				peutJouer = 0;
			}
			else {
				peutJouer++;
			}
		}

		if (peutJouer >= 2) {
			Home.ChangeRun(false);
		}
	}

	return 0;
}