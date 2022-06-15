#include "Affichage.h"

Affichage::Affichage(int J1, int J2)
{
    this->Joueur1Couleur = J1;
    this->Joueur2Couleur = J2;
}

void Affichage::Plateau(int plato[8][8], HANDLE Console, std::string Joueur1, std::string Joueur2)
{
    int point1 = 0;
    int point2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (plato[i][j] == 1) {
                SetConsoleTextAttribute(Console, Joueur1Couleur);
                fprintf(stdout, "%s", "X ");
            }
            else if (plato[i][j] == 2){
                SetConsoleTextAttribute(Console, Joueur2Couleur);
                fprintf(stdout, "%s", "X ");
            }
            else {
                SetConsoleTextAttribute(Console, 15);
                fprintf(stdout, "%s", "O ");
            }
        }
        if (i == 1) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (plato[i][j] == 1) {
                        point1++;
                    }
                    else if (plato[i][j] == 2) {
                        point2++;
                    }
                }
            }
            Point(Joueur1, point1, this->Joueur1Couleur, Console);
        }
        if (i == 2) {
            Point(Joueur2, point2, this->Joueur2Couleur, Console);
        }
        SetConsoleTextAttribute(Console, 15);
        fprintf(stdout, "\n");
    }
}

void Affichage::Point(std::string nom, int point, int couleur, HANDLE Console)
{
    SetConsoleTextAttribute(Console, 15);
    fprintf(stdout, "      ");
    SetConsoleTextAttribute(Console, couleur);
    fprintf(stdout, "%s : %d", nom.c_str(), point);
}
