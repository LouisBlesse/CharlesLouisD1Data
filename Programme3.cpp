#include "Programme3.h"
#include <iostream>
#include <iostream>
#include <stdexcept>




void Programme3::Play() {
    Arbre::Noeud node1();
    Arbre Tree = Arbre();
    int choix = 0;
    while (choix != 5) {
        cout << "Que voulez vous faire ? \n 1: Ajouter un mot au dictionnaire \n 2: Enlever un mot au dictionnaire \n 3: Afficher le dictionnaire \n 4: Rechercher un mot du dictionnaire\n 5: Partir\n\n";
        cin >> choix;

        if (choix == 1) {
            Tree = Add(Tree);
        }
        else if (choix == 2) {
            Tree = Delete(Tree);
        }
        else if (choix == 3) {
            Afficher(Tree);
        }
        else if (choix == 4) {
            Recherche(Tree);
        }
    }

}

Arbre Programme3::Add(Arbre Tree) {
    string mot;
    cout << "WIP";
    cout << "Quel mot voulez vous ajouter ?\n";
    cin >> mot;
    
    if (Tree.racine == NULL) {
        for (int i = 0; i < mot.length(); i++)
        {
            Creer(mot, Tree.racine, i);
        }
    }
    else {
        for (int i = 0; i < mot.length(); i++)
        {
            insert(mot, Tree.racine, i, true);
        }
    }


    return Tree;
}

void Programme3::Creer(string mot, Arbre::Noeud*& t, int i)
{
    cout << "creer";
    try {
        if (t == NULL) {
            t = new Arbre::Noeud(mot[i]);
            cout << "\n creation, data : " << t->data << "\n";
            if (i == mot.length())
                t->endWord = 1;
        }
        else /*if (t->gauche == NULL)*/ {
            cout << "\ninsert a gauche, data : " << t->data << "\n";
            Creer(mot, t->gauche, i++);
        }
    }
    catch (const std::exception& e) {
            std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}

void Programme3::insert(string mot, Arbre::Noeud*& t, int i, bool check)
{
    cout << "inserrer";
    try {
        if (t == NULL) {
            if (check == true) {
                t = new Arbre::Noeud(mot[i]);
                cout << "\n creation, data : " << t->data << "\n";
                if (i == mot.length())
                    t->endWord = 1;
            }
        }
        else if (i > 0 && t->data == mot[i - 1]) {
                cout << "\ndata : " << t->data << " et mot [i] = " << mot[i] << ", on va a droite et on add\n";
                insert(mot, t->droite, i++, true);
        }
        else if (t->data == mot[i]) {
            cout << "\ndata : " << t->data << " et mot [i] = " << mot[i] << ", on va a droite et on add pas\n";
            insert(mot, t->droite, i++, false);
        }
        else if (t->data != mot[i]) {
            cout << "\ndata : " << t->data << " et mot [i] = " << mot[i] << ", on va a gauche et on add\n";
            insert(mot, t->gauche, i++, true);
        }
        /*else {


            if (i > 0) {
                cout << "data : " << t->gauche->data << "mot - 1 :" << mot[i - 1] << "\n";
                if (mot[i - 1] == t->gauche->data) {
                    cout << "insert a gauche\n";
                    insert(mot, t->gauche, i++);
                }
                else{
                    cout << "data : " << t->data << "insert a droite\n";
                    insert(mot, t->droite, i++);
                }

            }

        }*/

        /*
        if (t == NULL)
            t = new Arbre::Noeud(x);
        else if (x < t->data)
            insert(x, t->gauche);
        else if (t->data < x)
            insert(x, t->droite);*/
    }
    catch (const std::exception& e) {
        cout << "Caught exception \"" << e.what() << "\"\n";
    }
}

void Programme3::print(const string& prefix, const Arbre::Noeud* t, bool isLeft)
{
    if (t != nullptr)
    {
        cout << prefix;
        cout << (isLeft ? "|--" : "L--");
        cout << t->data << endl;
        print(prefix + (isLeft ? "|   " : "    "), t->droite, true);
        print(prefix + (isLeft ? "|   " : "    "), t->gauche, false);
    }
}

void Programme3::print(const Arbre::Noeud* t)
{
    print("", t, false);
}


Arbre Programme3::Delete(Arbre Tree) {
    cout << "WIP";
    return Tree;
}

void Programme3::Afficher(Arbre Tree) {
    //cout << "WIP";
    print(Tree.racine);
}

bool Programme3::Recherche(Arbre Tree) {
    string mot;
    cout << "Quel mot voulez vous rechercher ?";
    cin >> mot;
    for (int i = 0; i < mot.length(); i++)
    {
        SeachNode(Tree.racine, mot, i);
    }

}

bool Programme3::SeachNode(Arbre::Noeud*& t, string mot, int i) {
    /*if (Tree.racine == NULL) {
        Arbre::Noeud t(mot[0]);
    }
    else*/

    return t;
}
