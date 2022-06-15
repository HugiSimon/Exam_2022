#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>

class Menu
{
public:
	Menu();

	bool Run();
	void ChangeRun(bool run);

	void ChoixInit();
	void ChoixMode();
	void ChoixCouleur(int Joueur);
	void ChoixNom(int Joueur);

	HANDLE ReturnConsole();
	int ReturnCouleur(int J);
	std::string ReturnNom(int J);

private:
	bool Running;

	bool Joueur2Bot;

	int Joueur1Couleur;
	int Joueur2Couleur;

	std::string nomJoueur1;
	std::string nomJoueur2;

	HANDLE  hConsole;
};