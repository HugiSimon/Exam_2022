#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>

class Verification
{
public:
	Verification();

	void ToutesPosition(int plateau[8][8], int Joueur, int *pos[128]);
	void ToutesPossibilte(int plateau[8][8], int Joueur, int *futurPos[1024]);

private:

};