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
	 c.setNumero(c.numCourant);
	 c.numCourant++;

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
	int i=0;
	while(i<employes.size() && clients[i].getNumero()!=num)		//pas juste car faut utiliser l'itérateur
	{
		i++;
	}
	if(i<clients.size())
		clients.retire(i);
}

void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction)
{
	Employe e;
	e.setNom(nom);
	e.setPrenom(prenom);
	e.setNumero(e.numCourant);
	e.setLogin(login);
	e.setFonction(fonction);
	e.numCourant++;
	employes.insere(e);

}
void Garage::afficheEmployes() const
{
	employes.Affiche();
}
void Garage::supprimeEmployeParIndice(int ind)
{
	employes.retire(ind);
}
void Garage::supprimeEmployeParNumero(int num)
{
	int i;
	while(i<employes.size() && employes[i].getNumero()!=num)
	{
		i++;
	}
	if(i<employes.size())
		employes.retire(i);
}

Garage& Garage::getInstance()
{
	return Instance;
}

Garage Garage::Instance = Garage();

Voiture& Garage::getProjetEnCours()
{
	return projetEnCours;
}

void Garage::resetProjetEnCours()
{
	getProjetEnCours() = Voiture();
}

Voiture Garage::projetEnCours = Voiture();