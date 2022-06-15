#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "Menu.h"

class Affichage
{
public:
	Affichage(int J1, int J2);

	void Plateau(int plato[8][8], HANDLE Console, std::string Joueur1, std::string Joueur2);
	void Point(std::string nom, int point, int couleur, HANDLE Console);

private:
	int Joueur1Couleur;
	int Joueur2Couleur;

};