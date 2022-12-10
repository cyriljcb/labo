#ifndef VECTEUR_H
#define VECTEUR_H
#include "Client.h"
//#include "Iterateur.h"
#include <string>
#include <iostream>
using namespace std;
template<class T> class Iterateur;
template<class T> class Vecteur
{
	protected: 
		T* v;
		int _sizeMax;
		int _size;
	public: 

		Vecteur();
		Vecteur(int);
		Vecteur(const Vecteur&); //faut peut etre mettre const Vecteur<T> &
		~Vecteur();

		int size()const;
		int sizeMax()const;
		T* getVec()const;
		void insere(const T);
		T retire(int);

		void Affiche()const;
		T operator[](int);
		Vecteur<T> operator=(const Vecteur<T>&);
		friend class Iterateur<T>;
		
};
#endif