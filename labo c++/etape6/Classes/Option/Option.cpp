#include "Option.h"
#include "OptionException.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <cstring>
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
	/*size_t size = c.size() + 1; // + 1 pour le caractère '\0' de fin 
    char * buffer = new char[ size ]; 
    strncpy( buffer, c.c_str(), size ); */
	if(c.size()!=4)
		throw OptionException("le format du code n'est pas correct ");
	code = c;
}

void Option::setIntitule(const string & i)
{
	/*size_t size = i.size() + 1; // + 1 pour le caractère '\0' de fin 
    char * buffer = new char[ size ]; 
    strncpy( buffer, i.c_str(), size ); 
	if(strlen(buffer)==0)*/
	if(i.size()!=0)
		throw OptionException("l'intitule ne peut pas etre vide");
	intitule = i;
}

void Option::setPrix(float p)
{
	if(p<0)
	{
		throw OptionException("Prix inférieur à 0");
	} 
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


/****************************************************************************/
/***** surcharges des operateurs*********************************************/
/****************************************************************************/




ostream& operator<< (ostream& s, const Option& o1)
{	
	s << "le code : "<< o1.code << endl;
	s << "l'intitule : "<<o1.intitule<<endl;
	s << "le prix des options : "<<fixed<<o1.prix<<"f"<<endl;

	//o1.Affiche();
	return s;
}

istream& operator>> (istream& s, Option& o1)
{
	string code;
	string intitule;
	string pr;
	float prix =0.0;
	cout<<"entrez le code : ";
	getline(s,code);
	cout<<"entrez l'intitule : ";
	getline(s,intitule);
	cout<<"entrez le prix : ";
	getline(s,pr);
	prix = stof(pr);

	o1.setCode(code);
	o1.setIntitule(intitule);
	o1.setPrix(prix);

	return s;
}

Option Option::operator--()
{
	/*Option o1(*this);
	float p;
	p= o1.getPrix()- 50.0;
	o1.setPrix(p);
	return o1;*/

	setPrix(getPrix()- 50);
	return *this;
}
Option Option::operator--(int)
{
	/*Option o1(*this);
	float p;
	p= o1.getPrix()- 50.0;		//pas bon car modifie o1 et pas ce que pointe *this
	o1.setPrix(p);
	return o1;*/

	Option o1(*this);
	setPrix(getPrix()- 50);
	return o1;
}