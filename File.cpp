#include "File.h"

template <typename T>
File<T>::File(const File&) throw (std::bad_alloc)
{
	int max = 100;
	tab = new T[max];
	tete = 0;
	queue = 0;
	cpt = 0;
	tailleMax = max;
}

template <class X>
File<X> ::~File()
{
	delete[] tab;
}

template <typename T>
T File<T>::defiler() throw (std::logic_error)
{
	if (cpt != 0)
	{
		T elementaDefiler = tab[tete];
		tete = (tete + 1) % tailleMax; //permet de « boucler » si on dépasse
		cpt--;
		return elementaDefiler;
	}
	else
		throw logic_error("Defiler: la file est vide!");
}

template <typename T>
T File<T>::enfiler(const T& e) throw (std::length_error)
{
	if (cpt < tailleMax)
	{
		tab[queue] = e;
		queue = (queue + 1) % tailleMax;
		cpt++;
	}
	else
		throw length_error("Enfiler : la file est pleine!");
}