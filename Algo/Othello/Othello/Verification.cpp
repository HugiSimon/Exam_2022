#include "Verification.h"

Verification::Verification()
{
}

void Verification::ToutesPosition(int plateau[8][8], int Joueur, int* pos[128])
{
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
}

void Verification::ToutesPossibilte(int plateau[8][8], int Joueur, int* futurPos[1024])
{
	int* pos[128];
	ToutesPosition(plateau, Joueur, pos);

	int JoueurAdv = 1;
	if (Joueur == 1) {
		JoueurAdv = 2;
	}

	int k = 0;

	for (int i = 0; i < 128; i=i+2) {
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
						if (plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] == 0) {
							if (*pos[i] + (Vx * SuitX) >= 0 && *pos[i] + (Vx * SuitX) <= 7 && *pos[i + 1] + (Vy * SuitY) >= 0 && *pos[i + 1] + (Vy * SuitY) <= 7) {
								fprintf(stdout, "Joueur%d x : %d - y : %d\n", Joueur, *pos[i] + (Vx * SuitX), *pos[i + 1] + (Vy * SuitY));
								futurPos[k] = (int*)malloc(sizeof(int));
								*futurPos[k] = *pos[i] + (Vx * SuitX);
								k++;
								futurPos[k] = (int*)malloc(sizeof(int));
								*futurPos[k] = *pos[i + 1] + (Vy * SuitY);
								k++;
							}
						}
					}

				}
 			}

		}
	}
    for (int i = k; i < 1024; i++) {
        futurPos[i] = (int*)malloc(sizeof(int));
        *futurPos[i] = -1;
    }
}
