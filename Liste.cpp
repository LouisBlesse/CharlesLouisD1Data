#include "Liste.h"
#include <cstddef>

using namespace std;
class Liste {
public:
	/*class Nœud;
	typedef Nœud* elem;
	class Noeud { //Un noeud typique de la liste
	public:
		int el; //L'élément de base de la liste
		Noeud* suivant; //Un pointeur vers le noeud suivant
		Noeud* precedent; //Un pointeur vers le noeud précédent
		Noeud(const int& data_item, Noeud* next_ptr = 0, Noeud* pred_ptr = 0) :
			el(data_item), suivant(next_ptr), precedent(pred_ptr) {}
	};
	elem sommetG; //Pointeur vers le sommet à gauche
	elem sommetD; //...vers le sommet droit
	int cpt; //cardinalité de la liste*/

	struct Node {
		int data;
		struct Node* p;
		struct Node* n;
	};
	struct Node* h = NULL;

	void add(int nb) {
		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->data = nb;
		cout << newnode->data;
		newnode->p = NULL;
		newnode->n = h;
		if (h != NULL) {
			h->p = newnode;
			h = newnode;
			cout << "newhead";
		}
	};
	void print() {
		struct Node* newnode;
		cout << "hi";
		newnode = h;
		while (newnode != NULL) {
			cout << newnode->data << "-->";
			newnode = newnode->n;
		}
	};
private:
};
