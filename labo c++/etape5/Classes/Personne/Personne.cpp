#include "Personne.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Personne::Personne()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Personne"<<endl;
	#endif

	nom = "";
	prenom = "";

}

/********constructeur par initialisation*******/
Personne::Personne(const string& n ,const string& p)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Personne"<<endl;
	#endif

	setNom(n);
	setPrenom(p);

}

/********constructeur par copie****************/
Personne::Personne (const Personne &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Personne"<<endl;
	#endif

	setNom(source.getNom());
	setPrenom(source.getPrenom());

}

/*******destructeur****************************/

Personne::~Personne()
{
	#ifdef DEBUG
		cout <<"destructeur par copie de Personne"<<endl;
	#endif

}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Personne::getNom()const
{

	return nom;

}

string Personne::getPrenom()const
{

	return prenom;
}

/*********SETTERS***********************/


void Personne::setNom (const string & n)
{
	nom = n;
}

void Personne::setPrenom(const string & p)
{
	prenom = p;
}


/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/
void Personne::Affiche()const
{
	cout<<"Nom "<<nom<<endl;
	cout<<"prenom : "<<prenom<<endl;
}

Personne& Personne::operator=(const Personne& p1)
{
	setNom(p1.getNom());
	setPrenom(p1.getPrenom());
	return (*this);
}

ostream& operator<< (ostream& s, const Personne& p1)
{	
	s << "le nom : "<< p1.nom << endl;
	s << "le prénom : "<<p1.prenom<<endl;
	return s;

}

istream& operator>> (istream& s,Personne& p)
{

	string nom;
	string prenom;
	string pr;
	
	cout<<"entrez le nom : ";
	getline(s,nom);
	cout<<"entrez le prenom : ";
	getline(s,prenom);
	p.setNom(nom);
	p.setPrenom(prenom);
	

	return s;
}