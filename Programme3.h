#pragma once
#include "Arbre.cpp"


class Programme3
{
public:
	void Play();
	Arbre Add(Arbre Tree);
	void Creer(string mot, Arbre::Noeud*& t, int i);
	void insert(string mot, Arbre::Noeud*& t, int i, bool check);
	void print(const Arbre::Noeud* node);
	void print(const string& prefix, const Arbre::Noeud* node, bool isLeft);
	Arbre Delete(Arbre Tree);
	void Afficher(Arbre Tree);
	bool Recherche(Arbre Tree);
	bool SeachNode(Arbre::Noeud*& t, string mot, int i);
};
