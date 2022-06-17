#include "Menu.h"

Menu::Menu()
{
	this->Running = false;

	this->Joueur2Bot = false;

	this->Joueur1Couleur = 15;
	this->Joueur2Couleur = 240;

	this->nomJoueur1 = "Joueur1";
	this->nomJoueur2 = "Joueur2";

	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Pour afficher les couleurs
}

bool Menu::Run() 
{
	return this->Running;
}

void Menu::ChangeRun(bool run) // Pour lancer ou arrêter le jeu
{
	this->Running = run;
}

void Menu::ChoixInit() // Demande toutes les questions aux joueurs
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

	ChoixMode(); // Demande le mode de jeu

	if (this->Joueur2Bot) { // Si le joueur 2 est un bot
		fprintf(stdout, "\nUn seul Joueur\n");

		fprintf(stdout, "Quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(1); // Demande la couleur du joueur 1

		fprintf(stdout, "\nVotre nom de Joueur\n");
		ChoixNom(1); // Demande le nom du joueur 1

		this->nomJoueur2 = "Bot";
		this->Joueur2Couleur = 80; // Le bot est violet
	}
	else { // Si le joueur 2 est un humain
		fprintf(stdout, "\nDeux Joueur\n");

		fprintf(stdout, "Premier joueur, quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(1); // Demande la couleur du joueur 1

		fprintf(stdout, "\nDeuxieme joueur, quel couleur voulez vous prendre ? Noir, Blanc, Bleu, Vert, Rouge ou Jaune\n");
		ChoixCouleur(2); // Demande la couleur du joueur 2

		fprintf(stdout, "\nPremier joueur, votre nom\n");
		ChoixNom(1); // Demande le nom du joueur 1

		fprintf(stdout, "\nDeuxieme joueur, votre nom\n");
		ChoixNom(2); // Demande le nom du joueur 2
	}

	this->Running = true; // Lance le jeu
}

void Menu::ChoixMode() // Pour le mode de jeu, 2 joueurs ou 1 joueur
{
	while (true){ // Tant que l'utilisateur n'a pas choisi
		char choix[10]; // Pour stocker le choix du joueur
		fgets(choix, 10, stdin); // On lit le choix du joueur
		choix[strlen(choix) - 1] = '\0'; 
		if (strcmp(choix, "JvJ") == 0){ // Si le joueur choisi JvJ
			this->Joueur2Bot = false;
			break;
		}
		else if (strcmp(choix, "JvB") == 0){ // Si le joueur choisi JvB
			this->Joueur2Bot = true;
			break;
		}
		else{
			fprintf(stdout, "Mauvaise saisie, JvJ ou JvB\n"); // Si le joueur n'a pas choisi JvJ ou JvB
		}
	}
}

void Menu::ChoixCouleur(int Joueur) // Choix de la couleur
{
	int tabCouleur[6] = { 15, 240, 16, 32, 64, 96 }; // Tableau de couleur // Noir, Blanc, Bleu, Vert, Rouge ou Jaune
	while (true) {
		char choix[10];
		fgets(choix, 10, stdin);
		choix[strlen(choix) - 1] = '\0';
		if (strcmp(choix, "Noir") == 0) { // Si le joueur choisi Noir
			if (Joueur == 1) { // Si c'est le joueur 1
				this->Joueur1Couleur = tabCouleur[0];
				break;
			}
			else { // Si c'est le joueur 2
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

void Menu::ChoixNom(int Joueur) // Pour le nom du joueur
{
	char choix[10];
	fgets(choix, 10, stdin);
	choix[strlen(choix) - 1] = '\0';
	if (Joueur == 1) { // Si c'est le joueur 1
		this->nomJoueur1 = choix;
	}
	else { // Si c'est le joueur 2
		this->nomJoueur2 = choix;
	}
}

HANDLE Menu::ReturnConsole() // Pour return la console
{
	return this->hConsole;
}

int Menu::ReturnCouleur(int J) // Return la couleur
{
	if (J == 1) {
		return this->Joueur1Couleur;
	}
	else {
		return this->Joueur2Couleur;
	}
}

std::string Menu::ReturnNom(int J) // Return le nom
{
	if (J==1) {
		return this->nomJoueur1;
	}
	else{
		return this->nomJoueur2;
	}
}

bool Menu::ReturnJoueurBot() // Return le bool du 2ème joueur
{
	return this->Joueur2Bot;
}
