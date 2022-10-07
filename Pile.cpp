#include "Pile.h"
#include <windows.h>
#include <iostream>

//enum { MAX_PILE };

template <typename T>
class Pile
{

public:
	int sommetPile;
	T* tab;
	int MAX_PILE;

	// constructeurs et destructeurs
	Pile(int max); //constructeur
	Pile(const Pile&); //constructeur copie
	~Pile(); //destructeur
	// Modificateurs
	void empiler(const T&);
	T depiler();
	//Sélecteurs
	bool estVide()const;
	int taille() const;
	const T& sommet() const; // consulte l’élément au sommet
	const Pile<T>& operator=(const Pile<T>& p);
	//surcharge d'opérateurs
	const Pile<T>& operator = (const Pile <T>);
	template <typename U> friend std::ostream& operator<<
		(std::ostream&, const Pile<U>&);
private: //Modèle d’implantation
};

template <typename T>
Pile<T> ::Pile(int max) {
	std::cout << "max ="<<max;
	tab = new T[max];
	sommetPile = -1;
	MAX_PILE = max;
}

template <typename T>
Pile<T> ::Pile(const Pile<T>& p) {
	tab = new T[p.MAX_PILE];
	MAX_PILE = p.MAX_PILE;
	for (int i = 0; i < MAX_PILE; i += 1)
		tab[i] = p.tab[i];
	sommetPile = p.sommetPile;
}

template <class T>
Pile<T> :: ~Pile() {
	delete[] tab;
}

template <typename T>
void Pile<T> ::empiler(const T& e) {
	if (sommetPile + 1 < MAX_PILE)
	{
		sommetPile += 1; // a += b  a = a+ b
		tab[sommetPile] = e;
	}
	else
		std::cout << "Empiler:la pile est pleine\n";
}

template <typename T>
T Pile<T> ::depiler() {
	if (!estVide()) return tab[sommetPile--];
	else
		std::cout << "Depiler: la pile est vide!";
}

template <typename T>
bool Pile<T> ::estVide() const
{
	return (sommetPile == -1);
}

template <typename T>
int Pile<T> ::taille() const
{
	return (MAX_PILE);
}

template <typename T>
const T& Pile<T> ::sommet() const
{
	return (sommetPile);
}

template <typename T>
const Pile<T>& Pile<T> :: operator = (const Pile<T>& p) {
	if (tab != 0) delete[] tab; //on nettoie l’objet qu’on veux écraser
	tab = new T[p.MAX_PILE];
	MAX_PILE = p.MAX_PILE;
	for (int i = 0; i < MAX_PILE; i += 1)
		tab[i] = p.tab[i];
	sommetPile = p.sommetPile;
	return (*this);
	//retourner : une référence sur l ’objet courant
}