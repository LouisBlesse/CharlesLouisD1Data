#pragma once
#ifndef ARBREP4
#define ARBREP4

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NoeudP4
{
	string nom;
	string prenon;
	int annee_naissance;
	string yeux;
	NoeudP4* fils_droite;
	NoeudP4* fils_gauche;
}NoeudP4;

void Placer(NoeudP4*& arbre, NoeudP4* noeud);
void Ajouter(NoeudP4*& arbre,string nom, string prenom, int annee_naissance, string yeux);
NoeudP4* Recherche(NoeudP4* arbre,string valeur);
void Supprimer(NoeudP4* arbre,NoeudP4* noeud);

#endif // !ARBREP4



