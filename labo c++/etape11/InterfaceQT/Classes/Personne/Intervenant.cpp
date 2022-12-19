#include "Intervenant.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/
int Intervenant::numCourant = 1;
/********constructeur par défaut****************/

Intervenant::Intervenant():Personne()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Intervenant"<<endl;
	#endif

	numero = 0;

}

/********constructeur par initialisation*******/
Intervenant::Intervenant(string n, string p,int num):Personne(n,p)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Intervenant"<<endl;
	#endif

	setNumero(num);

}

/********constructeur par copie****************/
Intervenant::Intervenant (const Intervenant &source):Personne(source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Intervenant"<<endl;
	#endif
	setNumero(source.getNumero());
}

/*******destructeur****************************/

Intervenant::~Intervenant()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de Intervenant"<<endl;
	#endif

}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

int Intervenant::getNumero()const
{

	return numero;

}



/*********SETTERS***********************/


void Intervenant::setNumero (int n)
{
	numero = n;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

Intervenant& Intervenant::operator=(const Intervenant& i1)
{
	Personne::operator=(i1);
	setNumero(i1.getNumero());
	return (*this);
}
