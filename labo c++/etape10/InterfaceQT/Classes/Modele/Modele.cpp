#include "Modele.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
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
	setImage("");
}

Modele::Modele(const char *n, int p, Moteur m, float pdb,string image)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Modele["<<n<<"-"<<p<<"-"<<m<<"-"<<pdb<<"]"<<endl;
	#endif
	nom = NULL;
	setNom(n);
	setPuissance(p);
	setMoteur(m);
	setPrixDeBase(pdb);

	setImage(image);

}

Modele::Modele(const Modele &source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Modele["<<source.getNom()<<"-"<<source.getPuissance()<<"-"<<source.getMoteur()<<"-"<<source.getPrixDeBase()<<--<<source.getImage()"]"<<endl;
	#endif

	nom = NULL;
	setNom(source.getNom());
	setPuissance(source.getPuissance());
	setMoteur(source.getMoteur());
	setPrixDeBase(source.getPrixDeBase());
	setImage(source.getImage());	



}
Modele::~Modele()
{
	#ifdef DEBUG
		cout <<"destructeur de Modele["<<getNom()<<"-"<<getPuissance()<<"-"<<getMoteur()<<"-"<<getPrixDeBase()<<-<<getImage()"]"<<endl;
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
string Modele::getImage()const
{
	return image;
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
void Modele::setImage(string im)
{
	image = im;
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
	
	cout<<"Image : "<<image<<endl;
	cout<<endl;

	
	}
}

/****************************************************************************/
/***** surcharges des operateurs*********************************************/
/****************************************************************************/
Modele& Modele::operator=(const Modele& m)
{
	setNom(m.getNom());
	setPuissance(m.getPuissance());
	setMoteur(m.getMoteur());
	setPrixDeBase(m.getPrixDeBase());
	setImage(m.getImage());
	return (*this);
}




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
	s << "l'image : "<<m.image<<endl;
	return s;
}

istream& operator>> (istream& s, Modele& m)
{
	string nom;
	string puis;
	string pr;
	string chmoteur;
	string image;
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
	cout<<"entrez le nom de l'image : ";
	getline(s,image);
	cout<<endl; 

	return s;
}

void Modele::Save(ofstream & fichierOut)const
{
	int taille,i;
	char* chaine;
	taille = strlen(getNom())+1;
	fichierOut.write((char*)&taille,sizeof(int));
	
	/*for(i=0;i<taille;i++)
	{
		fichierOut.write((char*)&(*(nom+i)),sizeof(char));
	}
*/	
	fichierOut.write((char*)nom,taille); //faut ajouter le0

	fichierOut.write((char*)&puissance,sizeof(int));
	fichierOut.write((char*)&moteur,sizeof(Moteur));
	fichierOut.write((char*)&prixDeBase,sizeof(float));

	taille = image.size();
	fichierOut.write((char*)&taille,sizeof(int));	
	fichierOut.write((char*)image.data(),taille*sizeof(char));
	
}

void Modele::Load(ifstream & fichierIn)
{
	int t,i;
	
	fichierIn.read((char*)&t,sizeof(int));
	
	if(nom != NULL) // ou  if(nom)
		delete [] nom;
	nom = new char[t];
	
	/*for(i=0;i<t;i++)
	{
		fichierIn.read((char*)&(*(nom+i)),sizeof(char));
	}*/
	fichierIn.read((char*)nom,t);
	nom[t] = 0;
	fichierIn.read((char*)&puissance,sizeof(int));	
	fichierIn.read((char*)&moteur,sizeof(Moteur));
	fichierIn.read((char*)&prixDeBase,sizeof(float));

	fichierIn.read((char*)&t,sizeof(int));
	image.resize(t);
	fichierIn.read((char*)image.data(),t*sizeof(char));
	
}