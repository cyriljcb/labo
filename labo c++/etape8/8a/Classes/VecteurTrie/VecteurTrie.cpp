#include "VecteurTrie.h"

using namespace std;

/****************************************************************************/
/***** Constructeurs et destructeurs ****************************************/
/****************************************************************************/

/********constructeur par défaut****************/

template<class T> VecteurTrie<T>::VecteurTrie():Vecteur<T>()
{	
		cout <<"Constructeur par defaut de VecteurTrie"<<endl;
	
	

}

/********constructeur par initialisation*******/
template<class T> VecteurTrie<T>::VecteurTrie(int n):Vecteur<T>(n)
{
	cout <<"Constructeur par initialisation de VecteurTrie"<<endl;
}

/********constructeur par copie****************/
template<class T> VecteurTrie<T>::VecteurTrie(const VecteurTrie &source):Vecteur<T>(source)
{

	cout <<"Constructeur par copie de VecteurTrie"<<endl;
}

/*******destructeur****************************/

template<class T> VecteurTrie<T>::~VecteurTrie()
{
	cout <<"destructeur par copie de VecteurTrie"<<endl;
}

template<class T>
void VecteurTrie<T>::insere(T val)
{
	/*int i,j;
    for(i=1;i<this->_sizeMax;i++)
    {
	    for (j=i-1;j>this->_size && val<(this->v[j]);j--)
	    {
	    		this->v[j+1]=this->v[j];
	    }
	    this->v[j]=val;
    }*/

   /* j =2;
    while(j<=this->_size)
    {
    	i = j-1;
    	while(i>0 && this->v[i]>val)
    	{
    		this->v[i+1]=this->v[i];
    		i--;
    	}
    	this->v[i+1]=val;
    	j++;
    }*/
    int i;
	if(this->_size < this->_sizeMax)
	{
		this->v[this->_size] = val;
		for(i = this->_size-1; i >= 0 && this->v[i] > val; i--){
			this->v[i+1] = this->v[i];
			//cout << "i : " << i << " j : " << j << " v[j+1] : " << this->v[j+1] << endl;
		}
		this->v[i+1] = val;
	}
	this->_size++;

}

/*****instanciation des templates************/
template class VecteurTrie<int>;
template class VecteurTrie<Client>;