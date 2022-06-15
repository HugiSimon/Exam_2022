#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "Menu.h"
#include "Affichage.h"
#include "Verification.h"

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

	while (Home.Run()) {
		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2), 10, 29);
		Verif.ToutesPossibilite(plateau, 1);
	}

	return 0;
}