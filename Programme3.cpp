#include "Programme3.h"
#include <iostream>
#include <iostream>
#include <stdexcept>




void Programme3::Play() {
    Arbre::Noeud node1();
    Arbre Tree = Arbre();
    int choix = 0;
    while (choix != 5) {
        cout << "Que voulez vous faire ? \n 1: Ajouter un mot au dictionnaire \n 2: Enlever un mot au dictionnaire \n 3: Afficher le dictionnaire \n 4: Rechercher un mot du dictionnaire\n\n";
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
        else if (choix == 5) {
            insert("abas", Tree.racine, 0);
            insert("arbre", Tree.racine, 0);
            insert("arbuste", Tree.racine, 0);
            insert("bas", Tree.racine, 0);
            insert("las", Tree.racine, 0);
            insert("lasse", Tree.racine, 0);
            insert("lit", Tree.racine, 0);

            Afficher(Tree);

            deleteWord(Tree.racine, "abas", 0);
            deleteWord(Tree.racine, "arbre", 0);
            deleteWord(Tree.racine, "arbuste", 0);

            Afficher(Tree);
        }
    }

}

Arbre Programme3::Add(Arbre Tree) {
    string mot;
    cout << "Quel mot voulez vous ajouter ?\n";
    cin >> mot;
    
    if (Tree.racine == NULL) {
        for (int i = 0; i < mot.length(); i++)
        {
            Creer(mot, Tree.racine, i);
        }
    }
    else {
        
        insert(mot, Tree.racine, 0);
        
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
            if (i == mot.length() - 1)
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


void Programme3::insert(string mot, Arbre::Noeud*& t, int i)
{
    if (t == NULL) {
        if (i < mot.length()) {
            t = new Arbre::Noeud(mot[i]);
            cout << "\n creation, data : " << t->data << "\n";
            if (i == mot.length() - 1)
                t->endWord = true;
        }
        return;
    }

    if (i >= mot.length()) {
        return;
    }

    if (t->data == mot[i]) {
        if (t->gauche == nullptr && i + 1 < mot.length()) {
            t->gauche = new Arbre::Noeud(mot[i+1]);
            cout << "\n add, data : " << t->data << "\n";
            if (i + 1 == mot.length() - 1) {
                t->gauche->endWord = 1;
                return;
            }
        }

        insert(mot, t->gauche, ++i);
    }
    else {
        if (t->droite == nullptr) {
            t->droite = new Arbre::Noeud(mot[i]);
            cout << "\n add, data : " << t->data << "\n";
            if (i == mot.length() - 1)
                t->droite->endWord = 1;
        }

        insert(mot, t->droite, i); 
    }

    
}

void Programme3::print(const string& prefix, const Arbre::Noeud* t, bool isLeft)
{
    if (t != nullptr)
    {
        cout << prefix;
        cout << (isLeft ? "|--" : "L--");
        cout << t->data ;
        if (t->endWord == true) {
            cout << "$";
        }
        cout << endl;
        print(prefix + (isLeft ? "|   " : "    "), t->droite, true);
        print(prefix + (isLeft ? "|   " : "    "), t->gauche, false);
    }
}

void Programme3::print(const Arbre::Noeud* t)
{
    print("", t, false);
}


void Programme3::Afficher(Arbre Tree) {
    print(Tree.racine);
}

bool Programme3::Recherche(Arbre Tree) {
    string mot;
    cout << "\nQuel mot voulez vous rechercher ?\n";
    cin >> mot;

    if (SearchNode(Tree.racine, mot, 0)) {
        cout << "\nLe mot est bien dans le dictionaire\n";
    }
    else
        cout << "\nLe mot n'est pas dans le dictionaire\n";
    

    return true;
}

bool Programme3::SearchNode(Arbre::Noeud*& t, string mot, int i) {
    if (t == NULL) {
         return false;
    }
   
    if (t->data == mot[i]) {
        if (i == mot.length()-1 && t->endWord)
            return true;

        return SearchNode(t->gauche, mot, ++i);
    }
    else {
        return SearchNode(t->droite, mot, i);
    }
}


Arbre Programme3::Delete(Arbre Tree) {
    string mot;
    cout << "\nQuel mot voulez vous enlever ?\n";
    cin >> mot;

    if (SearchNode(Tree.racine, mot, 0) == false) {
        cout << "\nLe mot n'est pas dans le dictionaire\n";
    }
    else
    {
        deleteWord(Tree.racine, mot, 0);
    }
    return Tree;
}

bool Programme3::deleteWord(Arbre::Noeud*& t, string mot, int i) {
    if (t == NULL) {
        return false;
    }
   
    if (t->data == mot[i]) {
        if (i+1 == mot.length() - 1 && t->gauche->data == mot[i + 1] && t->gauche->endWord) {
            // fin du mot
            // cas 1 y a une suite -> on retire juste le end
            t->gauche->endWord = false;

            if (t->gauche->gauche != nullptr)
                return false;
        }
        else {
            if (deleteWord(t->gauche, mot, i + 1) == false) {
                return false;
            }
        }
        // remonter
        // cas 2 y a pas de suite on delete
        // suppr t->gauche
        
        // cas 2.0 il est terminale => on stope et false
        if (t->gauche->endWord == true) {
            return false;
        }

        // cas 2.1 il a un right
        if (t->gauche->droite != NULL) {
            // cas 2.1.1 c'est gauche donc s'il a un right devient gauche + stop delete
            Arbre::Noeud* tmp = t->gauche;
            t->gauche = t->gauche->droite;
            delete tmp;
            return false;
        }
        else if (t->gauche->gauche == NULL && t->gauche->droite == NULL) {
            delete t->gauche;
            t->gauche = NULL;
        }   
    }
    else {
        if(deleteWord(t->droite, mot, i) == false) {
            return false;
        }
        // remonter
        // cas 2 y a pas de suite on delete
        // suppr t->droite

        // cas 2.0 il est terminale => on stope et false
        if (t->droite->endWord == true) {
            return false;
        }

        // cas 2.1 il a un right
        if (t->droite->droite != NULL) {
            // cas 2.1.1 c'est droite donc le right devient right  + stop delete
            Arbre::Noeud* tmp = t->droite;
            t->droite = t->droite->droite;
            delete tmp;
            return false;
        }else if (t->droite->gauche == NULL && t->droite->droite == NULL) {
            delete t->droite;
            t->droite = NULL;
            if (t->gauche != NULL)
                return false;
        }
    }

    if (i == 0 && t->gauche == NULL && t->droite != NULL) {
        Arbre::Noeud* tmp = t;
        t = t->droite;
        delete tmp;
        return false;
    }
    return true;
   
}