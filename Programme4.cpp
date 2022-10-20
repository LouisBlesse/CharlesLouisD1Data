#include "Programme4.h"


void Afficher(NoeudP4* racine)
{
	if (racine->fils_gauche) Afficher(racine->fils_gauche);
	cout << racine->nom << endl << racine->prenon << endl << racine->annee_naissance << endl << racine->yeux << endl;
	cout << endl;
	if (racine->fils_droite) Afficher(racine->fils_droite);
}

int Taille(NoeudP4* racine) {
	if (racine == NULL)
		return 0;

	int left = Taille(racine->fils_gauche);
	int right = Taille(racine->fils_droite);

	return ((left > right ? left : right) + 1);
}

void Aj(NoeudP4* racine) {
	string nom;
	string prenom;
	int annee;
	string yeux;

	cout << "Quelle est son nom ?" << endl;
	cin >> nom;
	cout << "Quelle est son prenom ?" << endl;
	cin >> prenom;
	cout << "Quelle est son annee de naissance ?" << endl;
	cin >> annee;
	cout << "Quelle est sont la couleur de ses yeux ?" << endl;
	cin >> yeux;
	Ajouter(racine,nom, prenom, annee, yeux);
	Afficher(racine);
}

void Coul_yeux(NoeudP4* racine) {
	string couleur;
	cout << "Quelle est la couleur des yeux que vous voulez cherchez ?" << endl;
	cin >> couleur;
	Afficher(Recherche(racine,couleur));
}

void Avg_age(NoeudP4* racine) {

	int age = 0;
	NoeudP4* courant = racine;
	while (courant)
	{
		age = age + (2022 - racine->annee_naissance);
		if (racine->fils_gauche)
			courant = courant->fils_gauche;
		else
			courant = courant->fils_droite;
	}
	int avg = 0;
	avg = age / Taille(racine);
	cout << endl << "Age moyen = " << avg << endl;
}

void Programme4::Play() {
	cout << "Programme 4 : \n\n";

	NoeudP4* arbre = NULL;

	int rep = 42;
	cout << "Voici arbre genealogique :" << endl;
	Ajouter(arbre,"Monsieur", "Pat", 1999, "Bleu");
	Ajouter(arbre,"Madame", "Zoal", 1998, "Bleu");
	Ajouter(arbre,"Monsieur fils", "Emile", 2010, "Bleu");
	Ajouter(arbre,"Madame fille", "Ana", 2022, "Vert");
	Afficher(arbre);

	while (rep != 0) {
		cout << endl << "Quelle fonction voulez vous lancez ?" << endl << "1 - Calculer la taille de l'abrre" << endl << "3 - Ajouter Membre de la famille" << endl << "4 - Liste couleur yeux" << endl << "6 - Calculer moyenne age" << endl << "0 - Exit" << endl;
		cin >> rep;

		switch (rep)
		{
		case 3:
			Aj(arbre);
		case 4:
			Coul_yeux(arbre);
		case 6:
			Avg_age(arbre);
		case 1:
			cout << "Taille de l'arbre : " << Taille(arbre) << endl;
		case 0:
			break;
		}
	}
}