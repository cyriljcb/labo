#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <string.h>
#include "protocole.h" // contient la cle et la structure d'un message
#include <unistd.h>

int idQ;
int pid1,pid2;

int main()
{
  MESSAGE requete;
  pid_t destinataire;
  const char* srv = "(SERVEUR) ";
  char buffer[100];
  
  // Armement du signal SIGINT
  // TO DO (etape 6)

  // Creation de la file de message
  fprintf(stderr,"(SERVEUR) Creation de la file de messages\n");
  // TO DO (etape 2)
  if ((idQ = msgget(CLE, IPC_CREAT | IPC_EXCL | 0600)) == -1)
  {    //si pas = a -1 : création de la file de message
      perror("Erreur de msgget");
      exit(1);
  }

  // Attente de connection de 2 clients
  fprintf(stderr,"(SERVEUR) Attente de connection d'un premier client...\n");
  // TO DO (etape 5)
  fprintf(stderr,"(SERVEUR) Attente de connection d'un second client...\n");
  // TO DO (etape 5)

  while(1) 
  {
    // TO DO (etapes 3, 4 et 5)
  	fprintf(stderr,"(SERVEUR) Attente d'une requete...\n");
    if(msgrcv(idQ,&requete,sizeof(MESSAGE)-sizeof(long),1,0)==-1)
    {
      perror("(SERVEUR) Erreur de msgrcv");
      msgctl(idQ,IPC_RMID,NULL);
      exit(1);
    }
    fprintf(stderr,"(SERVEUR) Requete recue de %d : --%s--\n",requete.expediteur,requete.texte);
    strcpy(buffer,srv);
    strcat(buffer,requete.texte);
    strcpy(requete.texte,buffer);
    /*printf("idQ : %d\n",idQ);
    printf("type : %d\n",requete.type);
    printf("expediteur : %d\n",requete.expediteur);*/
    requete.type = requete.expediteur;
    

    fprintf(stderr,"(SERVEUR) Envoi de la reponse a %d\n",destinataire);
    if(msgsnd(idQ,&requete,sizeof(MESSAGE)-sizeof(long),0)==-1)
    {
      perror("(SERVEUR) Erreur de msgsnd");
      msgctl(idQ,IPC_RMID,NULL);
      exit(1);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TO DO (etape 6)
