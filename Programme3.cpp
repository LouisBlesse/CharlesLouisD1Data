#include "Programme3.h"
#include <iostream>
#include "Arbre.cpp"
using namespace std;

void Programme3::Play() {
    Arbre::Noeud node1();
    Arbre Tree;
    int choix = 0;
    while (choix != 5) {
        cout << "Que voulez vous faire ? \n 1: Ajouter un mot au dictionnaire \n 2: Enlever un mot au dictionnaire \n 3: Afficher le dictionnaire \n 4: Rechercher un mot du dictionnaire\n 5: Partir\n\n";
        cin >> choix;

        if (choix == 1) {
            Add();
        }
        else if (choix == 2) {
            //Arbre Tree = Delete(Tree);
        }
        else if (choix == 3) {
            //Arbre Tree = Afficher(Tree);
        }
    }

}

void Programme3::Add() {
    cout << "WIP";
}
/*
Arbre Programme3::Delete(Arbre Tree) {
    cout << "WIP";
    return Tree;
}

Arbre Programme3::Afficher(Arbre Tree) {
    cout << "WIP";
    return Tree;
}*/