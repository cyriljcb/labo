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
	//ptrEmploye = NULL;
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


/*Option*/

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

/*client*/

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
	while(i<clients.size() && clients[i].getNumero()!=num)
	{
		i++;
	}
	if(i<clients.size())
		clients.retire(i);
	/*Iterateur<Client>::it(client);
	for(i=0,it.reset();!it.end()&& clients[i].getNumero()!=num ;it++;i++)
	{

	}
	if(i<clients.size())
		clients.retire(i);*/

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
	int i=0;
	while(i<employes.size() && employes[i].getNumero()!=num) //pas juste car il faut utiliser l'itérateur
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





void Garage::importeModeles(string nomFichier)
{
	
	filebuf fichier;
	if(!fichier.open(nomFichier,ios::in))
	{
		cout<<"erreur d'ouverture du fichier..."<<endl;
		exit(0);
	}
	istream flux(&fichier);
	char chaine[100];
	flux.getline(chaine,100);
	const char * ptr = strtok(chaine,";");
	while(ptr!=NULL)
	    {
	    	ptr = strtok(NULL, ";");		//pour ne pas afficher la premiere ligne
	    }

	while(!flux.eof())
	{
		Modele m;
		flux.getline(chaine,100);
	    ptr = strtok(chaine,";");
	    m.setNom(ptr);
	    ptr = strtok(NULL,";");

	    int puis = atoi(ptr);
	    m.setPuissance(puis);
	    //cout << puis<<endl;
		ptr = strtok(NULL,";");
		//cout<<ptr<<endl;

	    if(strcmp(ptr,"essence")==0)
	    {
			m.setMoteur(Essence);	
	    }
	    else
	    {
	    	if(strcmp(ptr,"diesel")==0)
	    	{
	    		m.setMoteur(Diesel);
	    	}	
	    	else
	    	{
	    		if(strcmp(ptr,"electrique")==0)
	    		{
	    			m.setMoteur(Electrique);
	    		}
	    		else
	    		{
	    			m.setMoteur(Hybride);
	    		}

	    	}
	    }
	    //cout<<"le moteur : "<<m.getMoteur()<<endl;
	    ptr = strtok(NULL,";");
	    
	    m.setImage(ptr);
	    ptr = strtok(NULL,";");

	    float prix = atof(ptr);
	    m.setPrixDeBase(prix);
	    m.Affiche();   //a enlever
	    modeles.insere(m);
	    cout<<endl<<endl;
	}
	fichier.close();

}

void Garage::importeOptions(string nomFichier)
{
	
}

Vecteur<Client>& Garage::getClient()
{
	return clients;
}

Vecteur<Employe>& Garage::getEmploye()
{
	return employes;
}