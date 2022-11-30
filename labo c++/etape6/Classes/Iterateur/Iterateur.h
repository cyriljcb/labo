#ifndef ITERATEUR_H
#define ITERATEUR_H
using namespace std;
#include "Vecteur.h"
template <class T>
class Iterateur
{
private: 
	Vecteur<T>& p; //pointeur vers l'objet containeur
	T *pData;
public:
	Iterateur(Vecteur<T>&);
	bool end() const;
	void reset();
	bool operator++();
	bool operator++(int);
	operator T() const;
};
#endif