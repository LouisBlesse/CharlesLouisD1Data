#include "Arbre.h"
#include <string>

using namespace std;

class Arbre
{
public:
	//..Les méthodes publiques (i.e. les opérateurs)
	class Noeud
	{
	public:
		char data;
		Noeud* gauche;
		Noeud* droite;
		int hauteur;
		bool endWord;
		Noeud(const char& d) : gauche(0), data(d), droite(0), hauteur(0) { }
		Noeud(const Arbre::Noeud& noeud) : gauche(noeud.gauche), data(noeud.data), droite(noeud.droite), hauteur(noeud.hauteur) { }
		//Noeud& operator=(const Noeud& other);
	};
	// Les membres données
	Noeud* racine; //racine de l'arbre
	int cpt; // Nombre de noeuds dans l'arbre
	// Les membres méthodes privés
	//...
private:
};