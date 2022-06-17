#include "Verification.h"

Verification::Verification()
{
	this->peutJouer = true;
}

void Verification::ToutesPosition(int plateau[8][8], int Joueur, int* pos[128]) // Récupère toutes les positions du joueurs
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

void Verification::ToutesPossibilte(int plateau[8][8], int Joueur, int* futurPos[1024]) // La grosse fonction qui calcule toutes les possibilités
{
	int* pos[128];
	ToutesPosition(plateau, Joueur, pos); // Récupère toutes les positions du joueur

	int JoueurAdv = 1; // Pour connaitre le joueur adverse
	if (Joueur == 1) {
		JoueurAdv = 2;
	}

	int k = 0;
	int peutJouer = 0;

	for (int i = 0; i < 128; i=i+2) { // Pour chaque position du joueur
		if (*pos[i] != -1) { // Si la position n'est pas vide

			for (int Vx = -1; Vx <= 1; Vx++) { // Pour chaque direction en x
				for (int Vy = -1; Vy <= 1; Vy++) { // Pour chaque direction en y

					int SuitX = 1; // Le nombre de fois qu'on decale en x
					int SuitY = 1;
					int compteur = 0; 

					while (plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] == JoueurAdv) { // Tant que la case est le joueur adverse
						SuitX++;
						SuitY++;
						compteur++;
					}

					if (compteur > 0) { // Si il y a au moins une case du joueur adverse
						if (plateau[*pos[i] + (Vx * SuitX)][*pos[i + 1] + (Vy * SuitY)] == 0) { // Si la case est vide
							if (*pos[i] + (Vx * SuitX) >= 0 && *pos[i] + (Vx * SuitX) <= 7 && *pos[i + 1] + (Vy * SuitY) >= 0 && *pos[i + 1] + (Vy * SuitY) <= 7) { // Si la case est dans le plateau
								fprintf(stdout, "Joueur%d x : %d - y : %d\n", Joueur, *pos[i] + (Vx * SuitX), *pos[i + 1] + (Vy * SuitY)); // Affiche le coup possible
								peutJouer++; // Incrémente le nombre de coup possible
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
	if (peutJouer == 0) { // Si il n'y a pas de coup possible
		this->peutJouer = false;
	}
	free(*pos);
}

bool Verification::PeutJouer() // Savoir si il peut jouer
{
	if (this->peutJouer) {
		return true;
	}
	else {
		this->peutJouer = true;
		return false;
	}
}
