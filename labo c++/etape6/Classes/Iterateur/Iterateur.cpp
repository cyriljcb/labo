#include "Iterateur.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

template<class T>
Iterateur<T>::Iterateur(Vecteur<T>& vec) : p(vec),pData(vec.getVec()) 
{

}

template <class T>
bool Iterateur<T>::end() const
{
	if(pData-p.getVec()>=p.size())
		return true;
	else
		return false;
}

template <class T>
void Iterateur<T>::reset()
{
	pData= p.getVec();
}

template <class T>
bool Iterateur<T>::operator++()
{
	if(!end())
	{
		pData++;
		return true;
	}
	else return false;

}

template <class T>
bool Iterateur<T>::operator++(int num)
{
	return operator++();
}

template <class T>
Iterateur<T>::operator T() const
{
	return *pData;
}

/*****instanciation des templates************/
template class Iterateur<int>;
template class Iterateur<Client>;