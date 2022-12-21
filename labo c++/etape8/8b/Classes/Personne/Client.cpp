#include "Client.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Client::Client():Intervenant()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Client"<<endl;
	#endif
	gsm = "pas de gsm enregistré";

}

/********constructeur par initialisation*******/
Client::Client(string n,string p, int num,string g):Intervenant(n,p,num)
{
	#ifdef DEBUG
	cout <<"Constructeur par initialisation de Client"<<endl;
	#endif
	setGsm(g);

}

/********constructeur par copie****************/
Client::Client (const Client &source):Intervenant(source)
{
	#ifdef DEBUG
	cout <<"Constructeur par copie de Client"<<endl;
	#endif
	setGsm(source.getGsm());
	

}

/*******destructeur****************************/

Client::~Client()
{
	#ifdef DEBUG
	cout <<"destructeur par copie de Client"<<endl;
	#endif
}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Client::getGsm()const
{

	return gsm;

}


/*********SETTERS***********************/


void Client::setGsm (string g)
{
	gsm = g;
}

/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

Client& Client::operator=(const Client& c)
{
	Intervenant::operator=(c);
	setGsm(c.getGsm());
	return (*this);
}

ostream& operator<< (ostream& s, const Client& c)
{	
	s << "le nom : "<<c.nom<<endl;
	s << "le prenom : "<<c.prenom<<endl;
	s << "le numero : "<<c.numero<<endl;
	s << "le numero de tel : "<< c.gsm << endl;
	
	return s;

}

string Client::ToString()const
{
	ostringstream oss;  //sert a creer un flux de sortie
    string tmp="[C";
    oss << getNumero();
 	string str = oss.str();
    tmp+=str;
    tmp+="] ";
    tmp+=getNom();
    tmp+= " ";
    tmp+=getPrenom();
    return tmp;
}

string Client::Tuple()const
{
	ostringstream oss;
	oss << getNumero();
 	string tmp = oss.str();
	string pointv =";";
	tmp += pointv + getNom() + pointv+ getPrenom()+ pointv+getGsm();
	return tmp;
}