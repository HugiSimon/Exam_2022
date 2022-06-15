#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <random>

class Poser
{
public:
	Poser();

	void PoserPions(int plateau[8][8], int *possib[1024], int Joueur);
	bool Verification(int *possib[1024], int x, int y);
	void RetournerPions(int plateau[8][8], int x, int y, int Joueur);
	void PoserBot(int plateau[8][8], int* possib[1024]);

private:

};