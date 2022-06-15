#include "Poser.h"

Poser::Poser()
{
}

void Poser::PoserPions(int plateau[8][8], int *possib[1024], int Joueur)
{
	int x = 0;
	int y = 0;

	do {
		fprintf(stdout, "\nA votre tour Joueur%d\nX : ", Joueur);
		scanf_s("%d", &x);
		fprintf(stdout, "Y : ");
		scanf_s("%d", &y);
	} while (Verification(possib, x, y));
	RetournerPions(plateau, x, y, Joueur);
}

bool Poser::Verification(int *possib[1024], int x, int y)
{
	for (int i = 0; i < 1024; i = i+2) {
		if (*possib[i] != -1) {

			if (*possib[i] == x && *possib[i + 1] == y) {
				return false;
			}

		}
	}
	return true;
}

void Poser::RetournerPions(int plateau[8][8], int x, int y, int Joueur)
{
	int* pos[128];
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (plateau[i][j] == Joueur) {
				pos[k] = (int*)malloc(sizeof(int));
				*pos[k] = i;
				k++;
				pos[k] = (int*)malloc(sizeof(int));
				*pos[k] = j;
				k++;
			}
			else {
				pos[k] = (int*)malloc(sizeof(int));
				*pos[k] = -1;
				k++;
				pos[k] = (int*)malloc(sizeof(int));
				*pos[k] = -1;
				k++;
			}
		}
	}

	plateau[x][y] = Joueur;

	int JoueurAdv = 1;
	if (Joueur == 1) {
		JoueurAdv = 2;
	}

	k = 0;
	for (int i = 0; i < 128; i = i + 2) {
		if (*pos[i] != -1) {

			for (int Vx = -1; Vx <= 1; Vx++) {
				for (int Vy = -1; Vy <= 1; Vy++) {

					int SuitX = 1;
					int SuitY = 1;
					int compteur = 0;

					while (plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] == JoueurAdv) {
						SuitX++;
						SuitY++;
						compteur++;
					}

					if (compteur > 0) {
						fprintf(stdout, "x: %d y: %d\n", *pos[i] + (Vx * SuitX), *pos[i + 1] + (Vy * SuitY));
						if (plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] == Joueur) {

							SuitX = 1;
							SuitY = 1;

							for (int j = 0; j < compteur; j++) {
								plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] = Joueur;
								SuitX++;
								SuitY++;
							}

						}
					}

				}
			}

		}
	}

}
