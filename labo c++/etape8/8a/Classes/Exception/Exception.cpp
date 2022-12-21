#include "Exception.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Exception::Exception()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Exception"<<endl;
	#endif

	message = "";
	

}

/********constructeur par initialisation*******/
Exception::Exception(const string& m)
{

	setMessage(m);

}

/********constructeur par copie****************/
Exception::Exception (const Exception &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Exception"<<endl;
	#endif

	setMessage(source.getMessage());


}

/*******destructeur****************************/

Exception::~Exception()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de Exception"<<endl;
	#endif

}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/
string Exception::getMessage()const
{

	return message;

}

/*********SETTERS***********************/


void Exception::setMessage (const string & m)
{
	message = m;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/
/*void Exception::Affiche()const
{
	cout<<"message :  "<<message<<endl;
}*/
