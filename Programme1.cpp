#include "Programme1.h"
#include "Carte.h"
#include "Pile.cpp"
#include <iostream>
using namespace std;

void Programme1::Play() {

    int nbrCartes = 51;
    while (nbrCartes <= 1 || nbrCartes >= 50) {
        cout << "Avec combien de cartes par joueurs voulez vous jouer ? (max 50) \n\n";
        cin >> nbrCartes;
    }

    Pile<Carte> deck(nbrCartes*2);

    for (int i = 0; i < nbrCartes * 2; i++) {
        //génération de la carte :
        int num = rand() % 10 + 1;
        int bonus = rand() % 4 + 1;
        int col = rand() % 2;
        string color;
        if (col == 1) color = "rouge";
        else color = "noire";
        Carte carte(num, bonus, color);
        deck.empiler(carte);
        //cout <<"\n"<< carte.bonus;
        //cout <<"deck :\n"<< deck.sommetPile;
    }

    Pile<Carte> deckP1(nbrCartes);
    Pile<Carte> deckP2(nbrCartes);

    //remplissage des decks des deux joueurs :
    for (int i = 0; i < nbrCartes; i++) {
        Carte newCarteP1 = deck.depiler();
        deckP1.empiler(newCarteP1);
        Carte newCarteP2 = deck.depiler();
        deckP2.empiler(newCarteP2);
    }

    cout << "deckP1 :\n" << deckP1.sommetPile;
    cout << "deckP2 :\n" << deckP2.sommetPile;

    Pile<Carte> deckP1Win(nbrCartes*2);
    Pile<Carte> deckP2Win(nbrCartes*2);

    for (int i = 0; i < nbrCartes; i++) {
        Carte CarteP1 = deckP1.depiler();
        Carte CarteP2 = deckP2.depiler();

        cout << "\nCarte joueur 1 : numero : " << CarteP1.numero << " couleur : "<< CarteP1.couleur<< " bonus : "<< CarteP1.bonus;
        cout << "\nCarte joueur 2 : numero : " << CarteP2.numero << " couleur : "<< CarteP2.couleur<< " bonus : "<< CarteP2.bonus<<"\n\n";

        if (CarteP1.numero > CarteP2.numero) {
            cout << " Victoire du joueur 1\n";
            deckP1Win.empiler(CarteP1);
            deckP1Win.empiler(CarteP2);
        }
        else if (CarteP1.numero < CarteP2.numero) {
            cout << " Victoire du joueur 2\n";
            deckP2Win.empiler(CarteP1);
            deckP2Win.empiler(CarteP2);
        }
        else if (CarteP1.numero == CarteP2.numero) {
            cout << " Les numeros sont egaux, on joue avec la couleur !\n";
            if ((CarteP1.couleur == "rouge") && (CarteP2.couleur == "noire")) {
                cout << " Victoire du joueur 1\n";
                deckP1Win.empiler(CarteP1);
                deckP1Win.empiler(CarteP2);
            }
            else if ((CarteP2.couleur == "rouge") && (CarteP1.couleur == "noire")) {
                cout << " Victoire du joueur 2\n";
                deckP2Win.empiler(CarteP1);
                deckP2Win.empiler(CarteP2);
            }
            else {
                cout << " Egalite !\n";
                deckP1Win.empiler(CarteP1);
                deckP2Win.empiler(CarteP2);
            }
        }
    }

    float scoreP1 = 0;

    while (!deckP1Win.estVide()) {
        Carte carte = deckP1Win.depiler();
        float tmp = carte.numero;
        if (carte.couleur == "rouge") {
            tmp = tmp * 1,5;
        }
        tmp = tmp * carte.bonus;
        scoreP1 += tmp;
    }
    cout << "\nScore joueur 1 : " << scoreP1<<"\n";

    float scoreP2 = 0;

    while (!deckP2Win.estVide()) {
        Carte carte = deckP2Win.depiler();
        float tmp = carte.numero;
        if (carte.couleur == "rouge") {
            tmp = tmp * 1, 5;
        }
        tmp = tmp * carte.bonus;
        scoreP2 += tmp;
    }
    cout << "\nScore joueur 2 : " << scoreP2<<"\n";

    if (scoreP1> scoreP2) cout << "\nLe joueur 1 a gagne la partie !!";
    else if (scoreP1< scoreP2) cout << "\nLe joueur 2 a gagne la partie !!";
    else cout << "\nEgalite !!";
}



