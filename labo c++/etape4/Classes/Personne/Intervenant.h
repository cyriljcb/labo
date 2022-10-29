#ifndef INTERVENANT_H
#define INTERVENANT_H
#include <string>
#include <iostream>
using namespace std;

class Intervenant: public Personne
{
	private: 
		int numero;

	public: 
		virtual string ToString()const = 0;
		virtual string Tuple()const = 0;

		int getNumero()const;
		void setNumero()const;

		Intervenant& operator=(const Intervenant&);


}