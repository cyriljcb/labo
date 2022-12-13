#include "Garage.h"


using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/


/********constructeur par défaut****************/
Garage::Garage()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Garage"<<endl;
	#endif
}


void Garage::ajouteModele(const Modele & m)
{
	modeles.insere(m);
}

void Garage::afficheModelesDisponibles() const
{
	modeles.Affiche();
}	

Modele Garage::getModele(int indice)
{

	return Modele(modeles[indice]);
}

void Garage::ajouteOption(const Option & o)
{
	options.insere(o);
}

void Garage::afficheOptionsDisponibles() const
{
	options.Affiche();
}
Option Garage::getOption(int indice)
{
	return Option(options[indice]);
}
void Garage::ajouteClient(string nom,string prenom,string gsm)
{
	Client c;
	c.setNom(nom);
	c.setPrenom(prenom);
	c.setGsm(gsm);
	clients.insere(c);
}
void Garage::afficheClients() const
{
	clients.Affiche();
}
void Garage::supprimeClientParIndice(int ind)
{
	clients.retire(ind);
}
void Garage::supprimeClientParNumero(int num)
{

}

void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction)
{
	Employe e;
	e.setNom(&nom);
	e.setPrenom(&prenom);
	cout<< "employe : "<<e<<endl;
	e.setLogin(&login);
	e.setFonction(&fonction);
	cout<< "employe : "<<e<<endl;
	employes.insere(e);

}
void Garage::afficheEmployes() const
{

}
void Garage::supprimeEmployeParIndice(int ind)
{

}
void Garage::supprimeEmployeParNumero(int num)
{

}