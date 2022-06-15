#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>

typedef struct coordonnees {

	int x;
	int y;

} coordonnees;

class Verification
{
public:
	Verification();

	coordonnees* ToutPosition(int plateau[8][8], int Joueur);
	coordonnees* ToutesPossibilite(int plateau[8][8], int Joueur);

private:
	coordonnees* pos[64];

};