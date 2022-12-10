#include "Vecteur.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

template<class T> Vecteur<T>::Vecteur()
{	
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Vecteur"<<endl;
	#endif
	_sizeMax =10;
	_size = 0;
	v = new T [_sizeMax];
	

}

/********constructeur par initialisation*******/
template<class T> Vecteur<T>::Vecteur(int n)
{
	cout <<"Constructeur par initialisation de Vecteur"<<endl;
	_sizeMax = n;
	v = new T [_sizeMax];
	_size = 0;

}

/********constructeur par copie****************/
template<class T> Vecteur<T>::Vecteur (const Vecteur &source)
{

	cout <<"Constructeur par copie de Vecteur"<<endl;
	int i;
	_sizeMax = source._sizeMax;
	_size = source._size;
	v=new T [_sizeMax];
	// memset(v,*source.v,_sizeMax*sizeof(T));
	for(i=0;i<_size;i++)
	{
		
		v[i]= (source.v[i]);
		

	}
}

/*******destructeur****************************/

template<class T> Vecteur<T>::~Vecteur()
{
	cout <<"destructeur par copie de Vecteur"<<endl;
	if(v!=NULL)
	{
		delete []v;
	}
}


/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

template<class T>
int  Vecteur<T>:: size()const
{
	return _size;
}

template<class T>
int  Vecteur<T>::sizeMax()const
{
	return _sizeMax;
}
template<class T>
T*  Vecteur<T>::getVec()const
{
	return v;
}

template<class T>
void Vecteur<T>::Affiche() const
{
	for (unsigned i=0; i<_sizeMax; i++)
    cout<<v[i]<<" | ";
}

template<class T>
void Vecteur<T>::insere(const T val)
{
	int ind = size();
	v[ind]=val;
	_size++;
}

template<class T>
T Vecteur<T>::retire(int ind)
{
	T test = v[ind];
	//cout<<v[ind]<<endl;
	if(ind < _size)
	{
		for(unsigned int i = ind+1; i < _sizeMax; i++)
		{
			v[i-1]=v[i];
		}
		_size--;
	}
	
	return test;
}




/*****surcharge des operateurs***************/
template<class T>
T Vecteur<T>::operator[](int i)
{
	return (v[i]);

}

template<class T>
Vecteur<T> Vecteur<T>::operator=(const Vecteur<T> &vec)
{
	int i;

	_sizeMax = vec._sizeMax;
	_size = vec._size;
	if(v!=NULL)
		delete []v;
	
	v=new T [_sizeMax];
	for(i=0;i<_size;i++)
	{
		v[i]=(vec.v[i]);
		
	}
	 return (*this);
}


/*****instanciation des templates************/
template class Vecteur<int>;
template class Vecteur<Client>;



