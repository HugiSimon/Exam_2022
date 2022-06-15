#include "Menu.h"

Menu::Menu()
{
	this->Running = false;

	this->Joueur2Bot = false;

	this->Joueur1Couleur = 15;
	this->Joueur2Couleur = 240;

	this->nomJoueur1 = "Joueur1";
	this->nomJoueur2 = "Joueur2";

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

bool Menu::Run()
{
	return this->Running;
}

void Menu::ChangeRun(bool run)
{
	this->Running = run;
}

void Menu::ChoixInit()
{
	SetConsoleTextAttribute(this->hConsole, 15);
	fprintf(stdout, "Bienvenue sur Othello !!!\n\n");
	fprintf(stdout, "Veuillez choisir votre mode de jeu\n");
	fprintf(stdout, "Joueur VS Joueur ou Joueur VS BOT -> ");

	SetConsoleTextAttribute(this->hConsole, 240);
	fprintf(stdout, "JvJ");
	SetConsoleTextAttribute(this->hConsole, 15);
	fprintf(stdout, "/");
	SetConsoleTextAttribute(this->hConsole, 240);
	fprintf(stdout, "JvB\n");
	SetConsoleTextAttribute(this->hConsole, 15);

	ChoixMode();

	if (this->Joueur2Bot) {
		fprintf(stdout, "\nUn seul Joueur\n");

		fprintf(stdout, "Quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(1);

		fprintf(stdout, "\nVotre nom de Joueur\n");
		ChoixNom(1);

		this->nomJoueur2 = "Bot";
		this->Joueur2Couleur = 80;
	}
	else {
		fprintf(stdout, "\nDeux Joueur\n");

		fprintf(stdout, "Premier joueur, quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(1);

		fprintf(stdout, "\nDeuxieme joueur, quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(2);

		fprintf(stdout, "\nPremier joueur, votre nom\n");
		ChoixNom(1);

		fprintf(stdout, "\nDeuxieme joueur, votre nom\n");
		ChoixNom(2);
	}

	this->Running = true;
}

void Menu::ChoixMode()
{
	while (true){
		char choix[10];
		fgets(choix, 10, stdin);
		choix[strlen(choix) - 1] = '\0';
		if (strcmp(choix, "JvJ") == 0){
			this->Joueur2Bot = false;
			break;
		}
		else if (strcmp(choix, "JvB") == 0){
			this->Joueur2Bot = true;
			break;
		}
		else{
			fprintf(stdout, "Mauvaise saisie, JvJ ou JvB\n");
		}
	}
}

void Menu::ChoixCouleur(int Joueur)
{
	int tabCouleur[6] = { 15, 240, 16, 32, 64, 96 };
	while (true) {
		char choix[10];
		fgets(choix, 10, stdin);
		choix[strlen(choix) - 1] = '\0';
		if (strcmp(choix, "Noir") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[0];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[0];
				break;
			}
		}
		else if (strcmp(choix, "Blanc") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[1];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[1];
				break;
			}
		}
		else if (strcmp(choix, "Bleu") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[2];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[2];
				break;
			}
		}
		else if (strcmp(choix, "Vert") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[3];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[3];
				break;
			}
		}
		else if (strcmp(choix, "Rouge") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[4];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[4];
				break;
			}
		}
		else if (strcmp(choix, "Jaune") == 0) {
			if (Joueur == 1) {
				this->Joueur1Couleur = tabCouleur[5];
				break;
			}
			else {
				this->Joueur2Couleur = tabCouleur[5];
				break;
			}
		}
		else {
			fprintf(stdout, "Mauvaise saisie");
		}
	}
}

void Menu::ChoixNom(int Joueur)
{
	char choix[10];
	fgets(choix, 10, stdin);
	choix[strlen(choix) - 1] = '\0';
	if (Joueur == 1) {
		this->nomJoueur1 = choix;
	}
	else {
		this->nomJoueur2 = choix;
	}
}

HANDLE Menu::ReturnConsole()
{
	return this->hConsole;
}

int Menu::ReturnCouleur(int J)
{
	if (J == 1) {
		return this->Joueur1Couleur;
	}
	else {
		return this->Joueur2Couleur;
	}
}

std::string Menu::ReturnNom(int J)
{
	if (J==1) {
		return this->nomJoueur1;
	}
	else{
		return this->nomJoueur2;
	}
}

bool Menu::ReturnJoueurBot()
{
	return this->Joueur2Bot;
}
