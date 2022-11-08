#include "PasswordException.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int PasswordException::INVALID_LENGTH = 1;
const int PasswordException::ALPHA_MISSING = 2;
const int PasswordException::DIGIT_MISSING = 3;
const int PasswordException::NO_PASSWORD = 4;


/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par initialisation*******/
PasswordException::PasswordException(const string& m,int c)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de PasswordException"<<endl;
	#endif

	setMessage(m);
	setCode(c);

}

/********constructeur par copie****************/
PasswordException::PasswordException (const PasswordException &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de PasswordException"<<endl;
	#endif

	setMessage(source.message);
	setCode(source.code);


}

/*******destructeur****************************/

PasswordException::~PasswordException()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de PasswordException"<<endl;
	#endif

}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/


int PasswordException::getCode()const
{
	return code;
}

/*********SETTERS***********************/


void PasswordException::setCode(int c)
{
	code = c;
}
