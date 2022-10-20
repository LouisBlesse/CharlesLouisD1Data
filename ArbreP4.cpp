#include "ArbreP4.h"

void Placer(NoeudP4*& arbre, NoeudP4* noeud)
{
	NoeudP4* courant = arbre;
	NoeudP4* precedent = NULL;

	if (arbre == NULL)
	{
		arbre = noeud;
		return;
	}
	while (courant)
	{
		precedent = courant;
		if (noeud->annee_naissance < courant->annee_naissance)
			courant = courant->fils_gauche;
		else
			courant = courant->fils_droite;
	}
	if (noeud->annee_naissance < precedent->annee_naissance)
		precedent->fils_gauche = noeud;
	else
		precedent->fils_droite = noeud;
}

void Ajouter(NoeudP4*& arbre, string nom, string prenom, int annee_naissance, string yeux)
{
	NoeudP4* nouveau = new NoeudP4;
	nouveau->nom = nom;
	nouveau->prenon = prenom;
	nouveau->annee_naissance = annee_naissance;
	nouveau->yeux = yeux;
	nouveau->fils_droite = NULL;
	nouveau->fils_gauche = NULL;
	Placer(arbre, nouveau);
}

NoeudP4* Recherche(NoeudP4* arbre, string valeur)
{
	NoeudP4* courant = arbre;
	while (courant)
	{
		if (valeur == courant->yeux)
			return courant;
		else if (valeur < courant->yeux)
			courant = courant->fils_gauche;
		else
			courant = courant->fils_droite;
	}
	return NULL;
}

void Supprimer(NoeudP4* arbre, NoeudP4* noeud)
{
	NoeudP4* droite = noeud->fils_droite;
	NoeudP4* gauche = noeud->fils_gauche;
	NoeudP4* courant = arbre;

	if (noeud == arbre)
	{
		arbre = droite;
		if (gauche) Placer(arbre,gauche);
		delete noeud;
		return;
	}
	while (courant)
	{
		if (courant->fils_droite == noeud
			|| courant->fils_gauche == noeud)
			break;

		if (noeud->annee_naissance >= courant->annee_naissance)
			courant = courant->fils_droite;
		else
			courant = courant->fils_gauche;
	}
	if (courant->fils_droite == noeud)
		courant->fils_droite = droite;
	else
		courant->fils_gauche = droite;

	if (gauche)
		Placer(arbre,gauche);
	delete noeud;
}