#include "Employe.h"
#include "PasswordException.h"
using namespace std;
const string Employe::ADMINISTRATIF = "Administratif";
const string Employe::VENDEUR = "Vendeur";
/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

Employe::Employe():Intervenant()
{
	#ifdef DEBUG
		cout <<"Constructeur par defaut de Employe"<<endl;
	#endif
	login = "";
	fonction = "";
	motDePasse=NULL;

}

/********constructeur par initialisation*******/
Employe::Employe(string n,string p, int num, string l,string f):Intervenant(n,p,num)
{
	#ifdef DEBUG
		cout <<"Constructeur par initialisation de Employe"<<endl;
	#endif
	setLogin(l);
	motDePasse = NULL;
	setFonction(f);

}

/********constructeur par copie****************/
Employe::Employe (const Employe &source):Intervenant(source)
{
	#ifdef DEBUG
		cout <<"Constructeur par copie de Employe"<<endl;
	#endif
	setLogin(source.getLogin());
	if(source.motDePasse==NULL)
	{
		motDePasse = NULL;
	}
	else
	{
		setMotDePasse(source.getMotDePasse());
	}
	
	setFonction(source.getFonction());
	

}


/*******destructeur****************************/

Employe::~Employe()
{
	if(motDePasse!=NULL)
	{
		delete motDePasse;
	}
	motDePasse = NULL;
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
	if(motDePasse==NULL)
		throw PasswordException("le mot de passe est vide",PasswordException::NO_PASSWORD);
	return *motDePasse;

}
string Employe::getFonction()const
{
	return fonction;
}



/*********SETTERS***********************/


void Employe::setLogin (string l)
{
	login = l;
}

void Employe::setMotDePasse(string m)
{
	if(motDePasse!=NULL)
		delete motDePasse;
	motDePasse = new string;

	/*int taille=m.length();
	if(taille ==0)
		throw PasswordException("le mot de passe est vide",PasswordException::NO_PASSWORD);
	if(taille <6)
    	throw PasswordException("le mot de passe ne contient pas au moins 6 caracteres",PasswordException::INVALID_LENGTH);
*/

	size_t size = m.size() + 1; // + 1 pour le caractère '\0' de fin 
    char * buffer = new char[ size ]; 
    strncpy( buffer, m.c_str(), size ); 
    buffer[size]=0;
    int i,cptchi = 0, cptlet = 0;

    if(size <=6)
    	throw PasswordException("le mot de passe ne contient pas au moins 6 caracteres",PasswordException::INVALID_LENGTH);
	for(i=0;i<size-1;i++)
	{
		if(buffer[i]>='0'&& buffer[i]<='9')
			cptchi++;

		if(buffer[i]>='a'&& buffer[i]<='z'||buffer[i]>='A'&& buffer[i]<='Z')
			cptlet++;
	}
	if(cptlet ==0 )
		throw PasswordException("le mot de passe ne contient pas de lettre",PasswordException::ALPHA_MISSING);
	else
	{
		if(cptchi ==0 )
			throw PasswordException("le mot de passe ne contient pas de chiffre",PasswordException::DIGIT_MISSING);
		else
		{	
			*motDePasse = m;
		}		
	}
	delete buffer;

    


}
void Employe::setFonction(string f)
{
	fonction = f;
}



/****************************************************************************/
/***** Méthodes publiques ***************************************************/
/****************************************************************************/
void Employe::ResetMotDePasse()
{
	if (motDePasse!=NULL)
		delete motDePasse;
	motDePasse=NULL;
}

Employe& Employe::operator=(const Employe& e)
{
	Intervenant::operator=(e);
	setLogin(e.getLogin());
	if(e.motDePasse!=NULL)
	{
		setMotDePasse(e.getMotDePasse());
	}
	else
	{
		ResetMotDePasse();
	}

	
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
	else
	{
		s<<"pas de mdp"<<endl;
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