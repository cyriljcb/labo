#ifndef VECTEURTRIE_H
#define VECTEURTRIE_H
#include "Vecteur.h"

template<class T> class Iterateur;

template <class T> 
class VecteurTrie: public Vecteur<T>
{
public:
	VecteurTrie();
	VecteurTrie(int);
	VecteurTrie(const VecteurTrie&);
	~VecteurTrie();
	friend class Iterateur<T>;
	void insere(T);
};
#endif