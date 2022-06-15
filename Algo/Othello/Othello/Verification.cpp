#include "Verification.h"

Verification::Verification()
{

}

coordonnees* Verification::ToutPosition(int plateau[8][8], int Joueur)
{
    coordonnees* ToutesPos = new coordonnees[64];
    int i = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (plateau[x][y] == Joueur) {
                ToutesPos[i].x = x;
                ToutesPos[i].y = y;
                i++;
            }
        }
    }
    return ToutesPos;
}

coordonnees* Verification::ToutesPossibilite(int plateau[8][8], int Joueur)
{
    coordonnees* piont = ToutPosition(plateau, Joueur);
	
	coordonnees Possibilite[64 * 8];
	for (int i = 0; i < 64 * 8; i++) {
		Possibilite[i] = { -1, -1 };
	}
	int k = 0;

	int JoueurAdv = 1;
	if (Joueur == 1) {
		JoueurAdv = 2;
	}

	for (int i = 0; i < 64; i++) {
		if (piont[i].x != -1) {

			for (int vX = -1; vX <= 1; vX++) {
				for (int vY = -1; vY <= 1; vY++) {

					int SuitX = 0;
					int SuitY = 0;
					int compteur = 0;
					while (plateau[piont[i].x + (vX * SuitX)][piont[i].y + (vY * SuitY)] == JoueurAdv) {
						compteur++;
						SuitX++;
						SuitY++;
					}

					if (compteur > 0) {
						if (plateau[piont[i].x + (vX * SuitX)][piont[i].y + (vY * SuitY)] == 0) {
							Possibilite[k] = { piont[i].x + (vX * SuitX), piont[i].y + (vY * SuitY) };
							k++;
						}
					}

				}
			}

		}
	}

	return Possibilite;
}


