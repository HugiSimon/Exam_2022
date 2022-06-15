#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include "Menu.h"
#include "Affichage.h"

int main() {

	int plateau[8][8] = {};
	plateau[3][3] = 1;
	plateau[4][4] = 1;
	plateau[3][4] = 2;
	plateau[4][3] = 2;

	Menu Home;

	Home.ChoixInit();

	Affichage Affichage(Home.ReturnCouleur(1), Home.ReturnCouleur(2));

	while (Home.Run()) {
		system("cls");
		Affichage.Plateau(plateau, Home.ReturnConsole(), Home.ReturnNom(1), Home.ReturnNom(2), 10, 29);
		Sleep(3000);
	}

	return 0;
}