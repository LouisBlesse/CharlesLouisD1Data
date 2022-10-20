#pragma once
#include <iostream>
using namespace std;

template<typename T>
class File
{
public: // constructeurs et destructeurs:
	File();
	File(const File&);
	~File();
	// modificateurs
	T enfiler(const T&);
	T defiler();
	// s�lecteurs 
	int taille() const;
	bool estVide() const;
	bool estPleine() const;
	const T& premier() const; // t�te de la file
	const T& dernier() const; // queue de la file
	// surcharges d'op�rateurs
	const File<T>& operator = (const File<T>&) throw (bad_alloc);
	template <typename U> friend std::ostream& operator <<
		(std::ostream& f, const File<U>& q);
private:
	T* tab;
	int tete;
	int queue;
	int tailleMax;
	int cpt; // ...Mod�le d'implantation
};