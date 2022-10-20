#include "Programme2.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
//#include "File.h"
//#include "File.cpp"
#include <queue>
using namespace std;

float time_total = 0;
float time_tete = 0;
float time_jupe = 0;
float time_axe = 0;

void MT(queue<string> queue_tete) {
	while (!queue_tete.empty()) {
		int n = (rand() % 100);
		time_tete += 2;
		if (n < 25) {
			int random = 5 + (rand() % 5);
			time_tete += random;
		}
		queue_tete.pop();
	}
}

void MJ(queue<string> queue_jupe) {
	while (!queue_jupe.empty()) {
		int n = (rand() % 100);
		time_jupe += 3;
		if (n < 25) {
			int random = 5 + (rand() % 5);
			time_jupe += random;
		}
		queue_jupe.pop();
	}
}

void MA(queue<string> queue_axe) {
	while (!queue_axe.empty()) {
		int n = (rand() % 100);
		time_axe += 2.5;
		if (n < 25) {
			int random = 5 + (rand() % 5);
			time_axe += random;
		}
		queue_axe.pop();
	}
}

void MP() {
	int n = (rand() % 100);
	time_total += 1;
	if (n < 25) {
		int random = 5 + (rand() % 5);
		time_total += random;
	}
}

void Programme2::Play() {
	cout << "Programme 2 :\n\n";
	int piston = 0;

	queue<string> carton;
	for (int i = 0; i < 1000; i++) {
		int random = 1 + (rand() % 3);
		if (random == 1)
			carton.push("tete");
		if (random == 2)
			carton.push("jupe");
		if (random == 3)
			carton.push("axe");
	}

	queue<string> queue_tete;
	queue<string> queue_jupe;
	queue<string> queue_axe;

	while (!carton.empty()) {
		if (carton.front() == "tete") {
			queue_tete.push(carton.front());
			carton.pop();
		}
		if (carton.front() == "jupe") {
			queue_jupe.push(carton.front());
			carton.pop();
		}
		if (carton.front() == "axe") {
			queue_axe.push(carton.front());
			carton.pop();
		}
		else
			carton.pop();
	}

	MT(queue_tete);
	cout << endl << "Temps de la machine MT :" << time_tete << " min" << endl;
	MJ(queue_jupe);
	cout << endl << "Temps de la machine MJ :" << time_jupe << " min" << endl;
	MA(queue_axe);
	cout << endl << "Temps de la machine MA :" << time_axe << " min" << endl;

	if (time_tete > time_jupe && time_tete > time_axe)
		time_total = time_tete;
	if (time_jupe > time_axe && time_jupe > time_tete)
		time_total = time_jupe;
	if (time_axe > time_jupe && time_axe > time_tete)
		time_total = time_axe;

	while (!queue_tete.empty() && !queue_jupe.empty() && !queue_axe.empty() && piston < 100) {
		MP();
		queue_tete.pop();
		queue_jupe.pop();
		queue_axe.pop();
		piston += 1;
	}
	cout << endl << "Temps de la machine MP :" << time_total << " min" << endl;
	cout << endl << "Nombre de piston :" << piston << endl;
}
