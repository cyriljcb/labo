#include "Option.h"
#include <iostream>
using namespace std;


/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/


/********constructeur par défaut****************/

Option::Option()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Option"<<endl;
	#endif

	code = "";
	intitule = "";
	prix=0.0f;

}

/********constructeur par initialisation*******/
Option::Option(const string & c ,const string & i,float p)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Option"<<endl;
	#endif

	setCode(c);
	setIntitule(i);
	setPrix(p); 

}



/********constructeur par copie****************/
Option::Option (const Option &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Option"<<endl;
	#endif

	setCode(source.getCode());
	setIntitule(source.getIntitule());
	setPrix(source.getPrix());

}


/*******destructeur****************************/

Option::~Option()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de Option"<<endl;
	#endif

}







/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Option::getCode()const
{

	return code;

}

string Option::getIntitule()const
{

	return intitule;
}

float Option::getPrix()const
{

	return prix;
}


/*********SETTERS***********************/


void Option::setCode (const string & c)
{
	code = c;
}

void Option::setIntitule(const string & i)
{
	intitule = i;
}

void Option::setPrix(float p)
{
	prix = p;
}




/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/


void Option::Affiche()const
{
	cout<<"Code : "<<code<<endl;
	cout<<"Intitule : "<<intitule<<endl;
	cout<<"prix des options : "<<fixed<<prix<<"f"<<endl;
}