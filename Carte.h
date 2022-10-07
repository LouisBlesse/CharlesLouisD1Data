#pragma once
#include <string>

using namespace std;
class Carte
{
public:
	int numero;
	int bonus;
	string couleur;

	Carte(int numero, int bonus, string couleur);
	Carte() {};
};
