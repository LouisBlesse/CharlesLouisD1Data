#include "Programme5.h"
#include "Liste.cpp"
#include <iostream>
using namespace std;

void Programme5::Play() {
	cout << "hello p5";

	Liste newliste;
	newliste.add(5);
	newliste.add(6);
	newliste.add(7);
	newliste.print();
}