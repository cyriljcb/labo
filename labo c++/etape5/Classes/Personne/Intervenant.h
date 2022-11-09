#ifndef INTERVENANT_H
#define INTERVENANT_H
#include "Personne.h"
#include <string>
#include <iostream>
using namespace std;

class Intervenant: public Personne
{
	protected: 

		int numero;

	public: 
		Intervenant();
		Intervenant(string,string,int);
		Intervenant(const Intervenant &);
		~Intervenant();
		virtual string ToString()const = 0;
		virtual string Tuple()const = 0;

		int getNumero()const;
		void setNumero(int);

		Intervenant& operator=(const Intervenant&);


};
#endif