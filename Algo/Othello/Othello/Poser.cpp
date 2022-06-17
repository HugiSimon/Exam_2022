#include "Poser.h"

Poser::Poser() // Rien à initialiser :'(
{
}

void Poser::PoserPions(int plateau[8][8], int *possib[1024], int Joueur) // Boucle pour poser le pions
{
	int x = 0;
	int y = 0;

	do { // Tant que le pions a poser à une place valide
		fprintf(stdout, "\nA votre tour Joueur%d\nX : ", Joueur);
		scanf_s("%d", &x);
		fprintf(stdout, "Y : ");
		scanf_s("%d", &y);
	} while (Verification(possib, x, y)); // Verifie la position
	RetournerPions(plateau, x, y, Joueur); // Retourne les pions
}

bool Poser::Verification(int *possib[1024], int x, int y) // Permet de vérifier que le joueur n'est pas débile
{
	for (int i = 0; i < 1024; i = i+2) { // Pour chaque possibilité
		if (*possib[i] != -1) { // Si la possibilité n'est pas vide

			if (*possib[i] == x && *possib[i + 1] == y) { // Si la possibilité correspond à la position du pion
				return false; // C'est bon
			}

		}
	}
	return true; // Le joueur c'est pas lire ou il est débile :'(
}

void Poser::RetournerPions(int plateau[8][8], int x, int y, int Joueur) // Retoune tout les pions qu'il faut (et pas plus !)
{
	int* pos[128]; 
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (plateau[i][j] == Joueur) { //Récupère tout les pions du joueur
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

	plateau[x][y] = Joueur; // Pose le pion initiale

	int JoueurAdv = 1; // Pour connaitre le joueur adverse
	if (Joueur == 1) {
		JoueurAdv = 2;
	}

	k = 0;

	for (int Vx = -1; Vx <= 1; Vx++) { // Pour chaque direction en x
		for (int Vy = -1; Vy <= 1; Vy++) { // Pour chaque direction en y

			int SuitX = 1; // Le nombre de fois qu'on decale en x
			int SuitY = 1; 
			int compteur = 0; // Le nombre de pions à retourner

			while (plateau[x + (Vx * SuitX)][y + (Vy * SuitY)] == JoueurAdv) { // Tant que le pion est de la couleur adverse
				SuitX++;
				SuitY++;
				compteur++;
			}

			if (compteur > 0) { // Si il y a au moins un pion à retourner
				if (plateau[x + (Vx * SuitX)][y + (Vy * SuitY)] == Joueur) { // Si le pion est de la couleur du joueur

					SuitX = 1;
					SuitY = 1;

					for (int j = 0; j < compteur; j++) { // Pour chaque pion à retourner 
						plateau[x + (Vx * SuitX)][y + (Vy * SuitY)] = Joueur;
						SuitX++;
						SuitY++;
					}

				}
			}

		}
	}
	free(*pos);
}

void Poser::PoserBot(int plateau[8][8], int* possib[1024]) // Le coup du bot
{
	fprintf(stdout, "\nAu bot de Jouer"); // Fait croire qu'il réfléchit
	Sleep(300);
	fprintf(stdout, ".");
	Sleep(300);
	fprintf(stdout, ".");
	Sleep(300);
	fprintf(stdout, ".\n");
	Sleep(300);

	int i = 0;
	while (*possib[i] != -1) { // Compte le nombre de possibilité
		i++;
	}

	int alea = rand() % i; // Choisit une possibilité aléatoire
	alea -= alea % 2; // Prend une valeur pair

	RetournerPions(plateau, *possib[alea], *possib[alea + 1], 2); // Retourne les pions
}
