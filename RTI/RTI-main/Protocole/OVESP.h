#ifndef OVESP_H
#define OVESP_H

#define NB_MAX_CLIENTS 100
#define NUMARTICLEMAX 21
#define TAILLE_MAX 500

void AccesBD_OVESP(char* requete, char * reponse,int socket,char* lArticle);


#endif
