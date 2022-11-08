#include "Modele.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>

//#define DEBUG

using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

Modele::Modele()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Modele"<<endl;
	#endif

	puissance = 0;
	prixDeBase = 0;
	moteur = Essence;
	//nom = NULL; --> pas l'idéal pour débuggué, donc on fera plutôt :
	//nom = new char[50];    --> attention, mettre des accolades
	//strcpy(nom, "Modele sans nom"); --> setNom reste cependant plus efficace

	nom = NULL; // pour ne pas supprimer une zone mémoire où nom aurait été instanciée
				// qui n'a rien avoir avec notre programme
	setNom("Modele sans nom");
}

Modele::Modele(const char *n, int p, Moteur m, float pdb)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Modele["<<n<<"-"<<p<<"-"<<m<<"-"<<pdb<<"]"<<endl;
	#endif
	nom = NULL;
	setNom(n);
	setPuissance(p);
	setMoteur(m);
	setPrixDeBase(pdb);

}

Modele::Modele(const Modele &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Modele["<<source.getNom()<<"-"<<source.getPuissance()<<"-"<<source.getMoteur()<<"-"<<source.getPrixDeBase()<<"]"<<endl;
	#endif

	nom = NULL;
	setNom(source.getNom());
	setPuissance(source.getPuissance());
	setMoteur(source.getMoteur());
	setPrixDeBase(source.getPrixDeBase());		


}
Modele::~Modele()
{
	#ifdef DEBUG
		cout <<"destructeur de Modele["<<getNom()<<"-"<<getPuissance()<<"-"<<getMoteur()<<"-"<<getPrixDeBase()<<"]"<<endl;
	#endif

	if(nom)
		delete[]nom;

}

/****************************************************************************/
/***** Getters et Setters ***************************************************/
/****************************************************************************/




/********GETTERS*****************************/


char* Modele::getNom()const
{
	return nom;
}

int Modele::getPuissance()const
{
	return puissance;
}
	
Moteur Modele::getMoteur()const
{
	return moteur;

}

float Modele::getPrixDeBase()const
{
	return prixDeBase;
}



/*********SETTERS***********************/


void Modele::setNom(const char *n)
{
	if(nom != NULL) // ou  if(nom)
		delete [] nom;
	nom = new char[strlen(n)+1];
	strcpy(nom, n);
}

void Modele::setPuissance(int p)
{
	if(p>=0)
		puissance = p;

}

void Modele::setMoteur(Moteur m)
{
	moteur = m;

}

void Modele::setPrixDeBase(float pdb)
{
	if(pdb>=0)
		prixDeBase = pdb;

}


/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/

void Modele::Affiche()const
{
	cout<<"Nom : "<<nom<<endl;
	cout<<"Puissance : "<<puissance<<endl;
	cout<<"Prix : "<<fixed<<prixDeBase<<"f"<<endl;
	cout<<"Moteur : ";
	switch(moteur){
		case Essence : 
			cout<<"Essence "<<endl;
		break;
		case Diesel : 
			cout<<"Diesel"<<endl;
		break;
		case Electrique : 
			cout<<"Electrique"<<endl;
		break;
		case Hybride : 
			cout<<"Hybride"<<endl;
		break;
	cout<<endl;
	
	}
}

/****************************************************************************/
/***** surcharges des operateurs*********************************************/
/****************************************************************************/

ostream& operator<< (ostream& s, const Modele& m)
{	
	s << "le nom : "<< m.nom << endl;
	s << "la puissance : "<<m.puissance<<endl;
	s << "le prix de base : "<<fixed<<m.prixDeBase<<"f"<<endl;
	s << "le moteur : ";
	switch(m.getMoteur()){
		case Essence : 
			s<<"Essence "<<endl;
		break;
		case Diesel : 
			s<<"Diesel"<<endl;
		break;
		case Electrique : 
			s<<"Electrique"<<endl;
		break;
		case Hybride : 
			s<<"Hybride"<<endl;
		break;
	}
	//m.Affiche();
	return s;
}

istream& operator>> (istream& s, Modele& m)
{
	string nom;
	string puis;
	string pr;
	string chmoteur;
	int puissance;
	float prix =0.0;
	int choixMoteur;

	cout<<"entrez le nom : ";
	getline(s,nom);
	size_t size = nom.size() + 1;
	char  n[size];
	strncpy( n, nom.c_str(), size );
	m.setNom(n);
	cout<<"entrez la puissance : ";
	getline(s,puis);
	
	puissance = stoi(puis);

	m.setPuissance(puissance);
	cout<<"entrez le prix : ";
	getline(s,pr);
	prix = stof(pr);
	m.setPrixDeBase(prix);
	cout << "pour selectionner le moteur, entrez "<<endl;
	cout << "1 pour essence"<<endl<<"2 pour diesel"<<endl<<"3 pour Electrique"<<endl<<"4 pour hybride"<<endl;
	cout << "Que choississez-vous : "<<endl;
	s >> choixMoteur;
	switch(choixMoteur){
		case 1 : 
			m.setMoteur(Essence);
		break;
		case 2 : 
			m.setMoteur(Diesel);
		break;
		case 3 : 
			m.setMoteur(Electrique);
		break;
		case 4 : 
			m.setMoteur(Hybride);
		break;
	}

	return s;
}