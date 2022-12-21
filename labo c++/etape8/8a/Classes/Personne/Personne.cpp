#include "Personne.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
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

	nom = "pas de nom enregistré";
	prenom = "pas de prénom enregistré";

}

/********constructeur par initialisation*******/
Personne::Personne(string n ,string p)
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


void Personne::setNom (string n)
{
	nom = n;
}

void Personne::setPrenom(string p)
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
/*int Personne::operator<(const Personne& p1)const
{
	int ind;
	if ((ind = strcmp(getNom().c_str(),p1.getNom().c_str()))==0)
	{
		return strcmp(getNom().c_str(),p1.getNom().c_str());
	}
	else
		return ind;
}
int Personne::operator>(const Personne& p1)const
{
	int a;
	if (strcmp(getNom().c_str(),p1.getNom().c_str())==1)
	{
		a = 1;
	}
	else
	{
		if (strcmp(getNom().c_str(),p1.getNom().c_str())==-1)
		{
			a = -1;
		}
		else
		{
			if(strcmp(getPrenom().c_str(),p1.getPrenom().c_str())==1)
			{
				a =1;
			}
			else
			{
				if((strcmp(getPrenom().c_str(),p1.getPrenom().c_str())==-1))
				{
					a = -1;
				}
				else
					a = 0;
			}
		}
	}
	return a;
}*/