#include "OptionException.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/
/********constructeur par défaut****************/

OptionException::OptionException():Exception()
{
	
		cout <<"Constructeur par defaut de OptionException"<<endl;

}

/********constructeur par initialisation*******/
OptionException::OptionException(const string& m):Exception(m)
{
	
		cout <<"Constructeur par initialisation de OptionException"<<endl;
	

}

/********constructeur par copie****************/
OptionException::OptionException (const OptionException &source):Exception(source)
{
	
		cout <<"Constructeur par copie de OptionException"<<endl;
}

/*******destructeur****************************/

OptionException::~OptionException()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de OptionException"<<endl;
	#endif

}

