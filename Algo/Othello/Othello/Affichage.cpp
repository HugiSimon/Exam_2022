#include "Affichage.h"

Affichage::Affichage(int J1, int J2) // Initialisation
{
    this->Joueur1Couleur = J1;
    this->Joueur2Couleur = J2;
}

void Affichage::Plateau(int plato[8][8], HANDLE Console, std::string Joueur1, std::string Joueur2) // Affiche le plateau
{
    int point1 = 0; // Pour compter le nombre de pions
    int point2 = 0;
    for (int i = 0; i < 8; i++) { // Pour chaque ligne
        for (int j = 0; j < 8; j++) { // Pour chaque colonne
            if (plato[i][j] == 1) { // Si le pion est du joueur 1
                SetConsoleTextAttribute(Console, Joueur1Couleur);
                fprintf(stdout, "%s", "X ");
            }
            else if (plato[i][j] == 2){ // Si le pion est du joueur 2
                SetConsoleTextAttribute(Console, Joueur2Couleur);
                fprintf(stdout, "%s", "X ");
            }
            else { // Si la case est vide
                SetConsoleTextAttribute(Console, 15);
                fprintf(stdout, "%s", "O ");
            }
        }
        if (i == 1) { // Si la ligne est la deuxième
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (plato[i][j] == 1) { // Compte le nombre de pions du joueur 1
                        point1++;
                    }
                    else if (plato[i][j] == 2) { // Compte le nombre de pions du joueur 2
                        point2++;
                    }
                }
            }
            Point(Joueur1, point1, this->Joueur1Couleur, Console); // Pour afficher le joueur 1
        }
        if (i == 2) { // Si la ligne est la troisième
            Point(Joueur2, point2, this->Joueur2Couleur, Console); // Pour afficher le joueur 2
        }
        SetConsoleTextAttribute(Console, 15);
        fprintf(stdout, "\n");
    }
}

void Affichage::Point(std::string nom, int point, int couleur, HANDLE Console) // Affiche le nom et le nombre de pions
{
    SetConsoleTextAttribute(Console, 15); // Pour afficher le texte en blanc
    fprintf(stdout, "      ");
    SetConsoleTextAttribute(Console, couleur); // Pour la couleur du joueur
    fprintf(stdout, "%s : %d", nom.c_str(), point); // Affiche le nom et le nombre de pions // nom.c_str() pour convertir le string en char*
}
