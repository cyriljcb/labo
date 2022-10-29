#include "Intervenant.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Intervenant::Intervenant()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Intervenant"<<endl;
	#endif

	numero = 0;

}

/********constructeur par initialisation*******/
Intervenant::Intervenant(int n)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Intervenant"<<endl;
	#endif

	setNumero(n);

}

/********constructeur par copie****************/
Intervenant::Intervenant (const Intervenant &source)
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


void Personne::setNumero (const int n)
{
	numero = n;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

Intervenant& operator=(const Intervenant& i1)
{
	setNumero(i1.getNumero());
	return (*this);
}

 ///!\ faut initialiser pour ien to =string dans client et dans employe sinon il va bouder.