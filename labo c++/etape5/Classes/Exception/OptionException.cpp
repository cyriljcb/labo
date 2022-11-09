#include "OptionException.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par initialisation*******/
OptionException::OptionException(const string& m):Exception(m)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de OptionException"<<endl;
	#endif

}

/********constructeur par copie****************/
OptionException::OptionException (const OptionException &source):Exception(source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de OptionException"<<endl;
	#endif
}

/*******destructeur****************************/

OptionException::~OptionException()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de OptionException"<<endl;
	#endif

}

