#include "Programme5.h"
#include <thread> 
#include <iostream>
using namespace std;

void Programme5::Play() {
	//cout << "hello p5";

	Liste newliste;
	newliste.add(15, &newliste.h);
	newliste.add(16, &newliste.h);
	newliste.add(17, &newliste.h);
	newliste.add(18, &newliste.h);
	newliste.add(19, &newliste.h);
	newliste.add(20, &newliste.h);
	newliste.print();
	cout << "\n";


	for (int i = 0; i < 20; i++) {
		thread calThread(&Programme5::Calcul, this, newliste);
		thread sumThread(&Programme5::sum, this, newliste);

		calThread.join();
		sumThread.join();
	}
	cout << "\n";
}

void Programme5::Calcul(Liste newliste) {


	newliste.send(newliste.h);
	newliste.send(newliste.h->n);
	newliste.send(newliste.h->n->n);
	newliste.send(newliste.h->n->n->n);
	newliste.send(newliste.h->n->n->n->n);
	newliste.send(newliste.h->n->n->n->n->n);

	newliste.send(newliste.h);

	newliste.print();
}

void Programme5::sum(Liste newliste) {
	newliste.sum(newliste.h);
}

