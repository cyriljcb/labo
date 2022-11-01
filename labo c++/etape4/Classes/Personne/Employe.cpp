#include "Employe.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Employe::Employe()
{
		cout <<"Constructeur par defaut de Employe"<<endl;

	nom = "";
	prenom = "";
	numero = 0;
	login = "";
	*mdp = NULL;

}

/********constructeur par initialisation*******/
Employe::Employe(const string &n, const string &p, int num, const string & l, const string & m)
{
	cout <<"Constructeur par initialisation de Employe"<<endl;

	setNom(n);
	setPrenom(p);
	setNumero(num);
	setLogin(l);
	setMotDePasse(m);

}

/********constructeur par copie****************/
Employe::Employe (const Employe &source)
{

	cout <<"Constructeur par copie de Employe"<<endl;

	setNom(source.getNom());
	setPrenom(source.getPrenom());
	setNumero(source.getNumero());
	setLogin(source.getLogin());
	setMotDePasse(source.getMotDePasse());
	

}

/*******destructeur****************************/

Employe::~Employe()
{
	cout <<"destructeur par copie de Employe"<<endl;
}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Employe::getLogin()const
{

	return login;

}

string* Employe::getMotDePasse()const
{

	return mdp;

}



/*********SETTERS***********************/


void Employe::setLogin (const string l)
{
	login = l;
}

void Employe::setMotDePasse(const string& m)
{
	mdp = m;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

Employe& Employe::operator=(const Employe& e)
{
	setLogin(e.getLogin());
	setMDP(e.getMDP());
	return (*this);
}

ostream& operator<< (ostream& s, const Employe& e)
{	
	s << "le login : "<< e.login << endl;
	s << "le mot de passe : "<<e.motDePasse<<endl;
	return s;

}