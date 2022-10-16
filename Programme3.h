#pragma once
#include "Arbre.cpp"


class Programme3
{
public:
	void Play();
	Arbre Add(Arbre Tree);
	void Creer(string mot, Arbre::Noeud*& t, int i);
	void insert(string mot, Arbre::Noeud*& t, int i, bool check);
	void printBT(const Arbre::Noeud* node);
	void printBT(const string& prefix, const Arbre::Noeud* node, bool isLeft);
	Arbre Delete(Arbre Tree);
	void Afficher(Arbre Tree);
	bool Recherche(Arbre Tree);
	//Arbre::Noeud SeachNode(Arbre Tree, string mot);
};
