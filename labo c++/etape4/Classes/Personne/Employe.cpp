#include "Employe.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <string.h>
#include "Intervenant.h"
using namespace std;
const string Employe::ADMINISTRATIF = "Administratif";
const string Employe::VENDEUR = "Vendeur";
/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Employe::Employe():Intervenant()
{
		cout <<"Constructeur par defaut de Employe"<<endl;

	login = "pas de login";
	fonction = "pas de fonction";
	motDePasse = NULL;

}

/********constructeur par initialisation*******/
Employe::Employe(const string &n, const string &p, int num, const string & l,const string & f):Intervenant(n,p,num)
{
	cout <<"Constructeur par initialisation de Employe"<<endl;

	setLogin(l);
	motDePasse = NULL;
	setFonction(f);

}

/********constructeur par copie****************/
Employe::Employe (const Employe &source):Intervenant(source)
{

	cout <<"Constructeur par copie de Employe"<<endl;
	setLogin(source.getLogin());
	motDePasse=NULL;
	setMotDePasse(source.getMotDePasse());
	setFonction(source.getFonction());
	

}

/*******destructeur****************************/

Employe::~Employe()
{
	cout <<"destructeur par copie de Employe"<<endl;
	if(motDePasse!=NULL)
		delete motDePasse;
}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/

/********GETTERS*****************************/

string Employe::getLogin()const
{

	return login;

}

string Employe::getMotDePasse()const
{

	return *motDePasse;

}
string Employe::getFonction()const
{
	return fonction;
}



/*********SETTERS***********************/


void Employe::setLogin (const string& l)
{
	login = l;
}

void Employe::setMotDePasse( string m)
{
	if (motDePasse!=NULL)
		delete motDePasse;
	motDePasse = new string;
	*motDePasse = m;
}
void Employe::setFonction(const string& f)
{
	fonction = f;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/
void Employe::ResetMotDePasse()
{
	if(motDePasse!=NULL)
		delete motDePasse;
	motDePasse=NULL;
}

Employe& Employe::operator=(const Employe& e)
{
	setNom(e.getNom());
	setPrenom(e.getPrenom());
	setNumero(e.getNumero());
	setLogin(e.getLogin());
	setMotDePasse(e.getMotDePasse());
	setFonction(e.getFonction());
	return (*this);
}

ostream& operator<< (ostream& s, const Employe& e)
{	

	s << "le nom : "<<e.nom<<endl;
	s << "le prenom : "<<e.prenom<<endl;
	s << "le numero : "<<e.numero<<endl;
	s << "le login : "<< e.login << endl;
	if(e.motDePasse != NULL)
	{
		s << "le mot de passe : "<<e.getMotDePasse()<<endl;

	}
	s << "fonction : "<<e.fonction<<endl;
	return s;

}

string Employe::ToString()const
{
	ostringstream oss;  //sert a creer un flux de sortie
    string tmp="[";
    string role = getFonction();
    if(role == "Vendeur")
    {
    	tmp+="V";
    }
    else
    	tmp+="A";
    oss << getNumero();
 	string str = oss.str();
    tmp+=str;
    tmp+="] ";
    tmp+=getNom();
    tmp+= " ";
    tmp+=getPrenom();
    return tmp;
}

string Employe::Tuple()const
{
	ostringstream oss;
	oss << getNumero();
 	string tmp = oss.str();
	string pointv =";";
	tmp += pointv + getNom() + pointv+ getPrenom()+ pointv+getFonction();
	return tmp;
}