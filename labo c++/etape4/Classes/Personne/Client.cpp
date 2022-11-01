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

Client::Client()
{
		cout <<"Constructeur par defaut de Client"<<endl;
	nom = "";
	prenom = "";
	numero = 0;
	gsm = "";

}

/********constructeur par initialisation*******/
Client::Client(const string& n,const string &p, int num, const string & g)
{
	cout <<"Constructeur par initialisation de Client"<<endl;
	setNom(n);
	setPrenom(p);
	setNumero(num);
	setGsm(g);

}

/********constructeur par copie****************/
Client::Client (const Client &source)
{

	cout <<"Constructeur par copie de Client"<<endl;

	setNom(source.getNom());
	setPrenom(source.getPrenom());
	setNumero(source.getNumero());
	setGsm(source.getGsm());
	

}

/*******destructeur****************************/

Client::~Client()
{
	cout <<"destructeur par copie de Client"<<endl;
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


void Client::setGsm (const string g)
{
	gsm = g;
}

/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

Client& Client::operator=(const Client& c)
{
	setNom(c.getNom());
	setPrenom(c.getPrenom());
	setNumero(c.getNumero());
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