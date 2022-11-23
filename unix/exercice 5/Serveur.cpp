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
void Handler_SIGINT(int signum);

int main()
{
  MESSAGE requete;
  pid_t destinataire;
  const char* srv = "(SERVEUR) ";
  char buffer[100];
  
  // Armement du signal SIGINT
   struct sigaction sigint;

  sigint.sa_flags = 0;
  sigint.sa_handler = Handler_SIGINT;
  sigemptyset(&sigint.sa_mask);
  sigaction(SIGINT, &sigint, NULL);

  // Creation de la file de message
  fprintf(stderr,"(SERVEUR) Creation de la file de messages\n");
  if ((idQ = msgget(CLE, IPC_CREAT | IPC_EXCL | 0600)) == -1)
  {    //si pas = a -1 : création de la file de message
      perror("(SERVEUR) Erreur de msgget");
      exit(1);
  }

  // Attente de connection de 2 clients
  fprintf(stderr,"(SERVEUR) Attente de connection d'un premier client...\n");
   if (msgrcv(idQ, &requete, sizeof(MESSAGE)-sizeof(long), 1, 0) == -1)
   {
    perror("Impossible d'obtenir le PID du client 1 !\n");
    exit(1);
  }
  pid1 = requete.expediteur;
  fprintf(stderr, "Client %s (%d) connecte \n",requete.texte, requete.expediteur);
  

  fprintf(stderr,"(SERVEUR) Attente de connection d'un second client...\n");
  if (msgrcv(idQ, &requete, sizeof(MESSAGE)-sizeof(long), 1, 0) == -1)
  {
    perror("Impossible d'obtenir le PID du client 2 !\n");
    exit(1);
  }
  pid2 = requete.expediteur;
  fprintf(stderr, "Client %s (%d) connecte \n", requete.texte, requete.expediteur);
  

  while(1) 
  {

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
    destinataire=requete.expediteur;
    
    if(destinataire==pid1)
    {
      requete.type = pid2;
    }
    else
      requete.type = pid1;

    if(destinataire==pid1)
    {
      destinataire = pid2;
    }
    else
      destinataire = pid1;
    

     fprintf(stderr,"(SERVEUR) Envoi de la reponse a %d\n",destinataire);
    if(msgsnd(idQ,&requete,sizeof(MESSAGE)-sizeof(long),0)==-1)
    {
      perror("(SERVEUR) Erreur de msgsnd");
      msgctl(idQ,IPC_RMID,NULL);
      exit(1);
    }
    kill(destinataire,SIGUSR1);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Handler_SIGINT(int signum)
{
  fprintf(stderr, "\nNettoyage de la file\n");
  if (msgctl(idQ, IPC_RMID, NULL) != 0){
    perror("Suppression de file impossible !\n");
  }
  exit(1);
}
