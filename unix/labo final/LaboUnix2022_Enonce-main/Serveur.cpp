#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "protocole.h" // contient la cle et la structure d'un message

int idQ,idShm,idSem;
int fdPipe[2];
TAB_CONNEXIONS *tab;

void afficheTab();
int testlogin(MESSAGE);
int testmdp(MESSAGE,int);
void fctlogin(MESSAGE,MESSAGE,TAB_CONNEXIONS*);
void fctconnect(MESSAGE,TAB_CONNEXIONS*);
void fctdeconnect(MESSAGE,TAB_CONNEXIONS*);
void fctlogout(MESSAGE,TAB_CONNEXIONS*);
void fctuptable_pub(MESSAGE,TAB_CONNEXIONS*);


void Handler_SIGINT(int);

int main()
{
  
  
  // Armement des signaux
  struct sigaction sigint;
  sigint.sa_flags=0;
  sigint.sa_handler = Handler_SIGINT;
  sigemptyset(&sigint.sa_mask);
  sigaction(SIGINT,&sigint,NULL); 

  // Creation des ressources
  // Creation de la file de message
  fprintf(stderr,"(SERVEUR %d) Creation de la file de messages\n",getpid());
  if ((idQ = msgget(CLE,IPC_CREAT | IPC_EXCL | 0600)) == -1)  // CLE definie dans protocole.h
  {
    perror("(SERVEUR) Erreur de msgget");
    exit(1);
  }

  fprintf(stderr,"idQ %d\n",idQ);

  fprintf(stderr,"(SERVEUR %d) Creation de la memoire partagée\n",getpid());

  if ((idShm = shmget(CLE,52,IPC_CREAT | IPC_EXCL | 0600)) == -1)//51+1 pour le \0 voir consigne etape 2
  {
    perror("Erreur de shmget");
    exit(1);
  }

  // TO BE CONTINUED

  // Creation du pipe
  // TO DO

  // Initialisation du tableau de connexions
  tab = (TAB_CONNEXIONS*) malloc(sizeof(TAB_CONNEXIONS)); 

  for (int i=0 ; i<6 ; i++)
  {
    tab->connexions[i].pidFenetre = 0;
    strcpy(tab->connexions[i].nom,"");
    tab->connexions[i].pidCaddie = 0;
  }
  tab->pidServeur = getpid();
  tab->pidPublicite = 0;

  afficheTab();

  // Creation du processus Publicite (étape 2)
  int fpub;
  fpub=fork();
  fprintf(stderr,"fork avec la pub %d\n",fpub);
  if(fpub==0)
  {
    if(execlp("Publicite","Publicite",NULL)==-1)
    {
      fprintf(stderr,"Erreur de l'exec de Publicite\n \n");
      exit(1);
    }
    fprintf(stderr,"fork avec la pub %d après l'exec\n",fpub);

  }

  // Creation du processus AccesBD (étape 4)
  // TO DO
  MESSAGE m;
  MESSAGE reponse;

  while(1)
  {
  	fprintf(stderr,"(SERVEUR %d) Attente d'une requete...\n",getpid());
    if (msgrcv(idQ,&m,sizeof(MESSAGE)-sizeof(long),1,0) == -1)
    {
      perror("(SERVEUR) Erreur de msgrcv");
      msgctl(idQ,IPC_RMID,NULL);
      exit(1);
    }

    switch(m.requete)
    {
      case CONNECT :  // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete CONNECT reçue de %d\n",getpid(),m.expediteur);
    
                      fctconnect(m,tab);
                      break;

      case DECONNECT : // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete DECONNECT reçue de %d\n",getpid(),m.expediteur);
                      fctdeconnect(m,tab);
                      break;
      case LOGIN :    // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete LOGIN reçue de %d : --%d--%s--%s--\n",getpid(),m.expediteur,m.data1,m.data2,m.data3);
                        fctlogin(m,reponse,tab);
                      break; 

      case LOGOUT :   // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete LOGOUT reçue de %d\n",getpid(),m.expediteur);
                      fctlogout(m,tab);
                      break;

      case UPDATE_PUB :  // TO DO
                      fprintf(stderr,"reception du message de UPDATE_PUB\n");
                      i=0;
                      while(tab->connexions[i].pidFenetre!= 0&&i<6)
                      {
                        //fprintf(stderr,"tab connexions %d est egal %d\n",i,tab->connexions[i].pidFenetre);
                        if(tab->connexions[i].pidFenetre==0)
                        {

                          tab->connexions[i].pidFenetre=m.expediteur;
                          i=6;
                        }
                        fprintf(stderr,"envoie du kill a %d\n ",tab->connexions[i].pidFenetre);
                        kill(tab->connexions[i].pidFenetre,SIGUSR2);

                        i++;
                      }
                      break;

      case CONSULT :  // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete CONSULT reçue de %d\n",getpid(),m.expediteur);
                      break;

      case ACHAT :    // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete ACHAT reçue de %d\n",getpid(),m.expediteur);
                      break;

      case CADDIE :   // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete CADDIE reçue de %d\n",getpid(),m.expediteur);
                      break;

      case CANCEL :   // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete CANCEL reçue de %d\n",getpid(),m.expediteur);
                      break;

      case CANCEL_ALL : // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete CANCEL_ALL reçue de %d\n",getpid(),m.expediteur);
                      break;

      case PAYER : // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete PAYER reçue de %d\n",getpid(),m.expediteur);
                      break;

      case NEW_PUB :  // TO DO
                      fprintf(stderr,"(SERVEUR %d) Requete NEW_PUB reçue de %d\n",getpid(),m.expediteur);
                      break;
    }
    afficheTab();
  }
}

void afficheTab()
{
  fprintf(stderr,"Pid Serveur   : %d\n",tab->pidServeur);
  fprintf(stderr,"Pid Publicite : %d\n",tab->pidPublicite);
  fprintf(stderr,"Pid AccesBD   : %d\n",tab->pidAccesBD);
  for (int i=0 ; i<6 ; i++)
    fprintf(stderr,"%6d -%20s- %6d\n",tab->connexions[i].pidFenetre,
                                                      tab->connexions[i].nom,
                                                      tab->connexions[i].pidCaddie);
  fprintf(stderr,"\n");
}

//////////////////////////////////////
void fctconnect(MESSAGE m,TAB_CONNEXIONS *tab)
{
  int i=0;
  fprintf(stderr,"test %d\n",m.expediteur);
  while((tab->connexions[i].pidFenetre)!= 0&&i<6)
  {
    if((tab->connexions[i].pidFenetre)==0)
    {

      (tab->connexions[i].pidFenetre)=m.expediteur;
      i=6;
    }

    i++;
  }
  if((tab->connexions[i].pidFenetre)==0)
  {

      ((tab->connexions[i].pidFenetre))=m.expediteur;
      
  }
}
//////////////////////////////////////////
void fctdeconnect(MESSAGE m,TAB_CONNEXIONS *tab)
{
  int i=0;
  while(tab->connexions[i].pidFenetre!= 0&&i<6)
  {
    //fprintf(stderr,"tab connexions %d est egal %d",i,tab->connexions[i].pidFenetre);
    if(tab->connexions[i].pidFenetre==m.expediteur)
    {

      tab->connexions[i].pidFenetre=0;
      i=6;
    }

    i++;
  }
}
//////////////////////////////////////////
int testlogin(MESSAGE msg)
{
  int fd,test,pt=0;
  MESSAGE atester;
  if((fd=open("Client.dat",O_CREAT|O_RDONLY| O_APPEND,0644))==-1)
  {
    perror("Erreur de open pour Client.dat");
    return -1;
  }
   while((test=read(fd, &atester, sizeof(MESSAGE)))== sizeof(MESSAGE))
  {
    if(strcmp(atester.data2, msg.data2)==0)
    {
      close(fd);
      return(pt);
    }
    pt++;
  }
  pt==-1;
  close(fd);
  return pt;

}
int testmdp(MESSAGE msg,int pos)
{
  int fd;
  MESSAGE tmdp;

  if ((fd = open("Client.dat", O_RDONLY)) == -1)
      return -1;
    
  lseek(fd, sizeof(MESSAGE)*(pos), SEEK_SET);

  read(fd, &tmdp, sizeof(MESSAGE));
    
  if (msg.data3 == tmdp.data3)
      return 1;
  close(fd);
  
  return 0;
}


void fctlogin(MESSAGE m,MESSAGE reponse,TAB_CONNEXIONS *tab)
{
  int test,i=0;
  reponse.type=1;
  reponse.expediteur=getpid();
   while(tab->connexions[i].pidFenetre!= m.expediteur&&i<6)
  {   
    i++;
  }
  
  if(tab->connexions[i].pidFenetre== m.expediteur)
  {
    
    strcpy(tab->connexions[i].nom,m.data2);
  }
  if(m.data1==0)
  {
    test = testlogin(m);
    if(test==-1)
    {
      strcpy(reponse.data4,"Client inconnu");
    }
    else
    {
      if(testmdp(m,test)==0)
      {
        strcpy(reponse.data4,"mauvais mot de passe");
      }
      else
      {
        strcpy(reponse.data4,"Re-bonjour cher client");
      }
    }
  }
  else
  {
    if(testlogin(m)==1)
    {
      strcpy(reponse.data4,"Client déjà existant");
    }
    else
    {
      strcpy(reponse.data4,"nouveau client créé : bienvenue !"); 
      int fd;
      fd = open("Client.dat", O_CREAT | O_APPEND | O_WRONLY, 0644);
      write(fd, &m.data2, sizeof(m.data2));
      write(fd, &m.data3, sizeof(m.data3));
      close(fd);

    }
  }
    if(msgsnd(idQ,&reponse,sizeof(MESSAGE)-sizeof(long),0)==-1)
    {
      perror("(SERVEUR) Erreur de msgsnd");
      exit(1);
    }
}


void fctlogout(MESSAGE m, TAB_CONNEXIONS* tab)
{
  int i = 0;
  while(tab->connexions[i].pidFenetre!= m.expediteur&&i<6)
  {   
    i++;
  }
  if(tab->connexions[i].pidFenetre== m.expediteur)
  {
                          
    strcpy(tab->connexions[i].nom,"");
  }
}

void fctuptable_pub(MESSAGE m, TAB_CONNEXIONS* tab)
{
  fprintf(stderr,"reception du message de UPDATE_PUB\n");
   int i=0;
    while(tab->connexions[i].pidFenetre!= 0&&i<6)
    {
      fprintf(stderr,"tab connexions %d est egal %d\n",i,tab->connexions[i].pidFenetre);
      if(tab->connexions[i].pidFenetre==0)
      {

        tab->connexions[i].pidFenetre=m.expediteur;
        i=6;
      }
      fprintf(stderr,"envoie du kill a %d\n ",tab->connexions[i].pidFenetre);
      kill(tab->connexions[i].pidFenetre,SIGUSR2);

      i++;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Handler_SIGINT(int sig)
{
  fprintf(stderr, "\nNettoyage de la file\n");
  if (msgctl(idQ, IPC_RMID, NULL) != 0){
    perror("Suppression de file impossible !\n");
  }
  if (shmctl(idShm,IPC_RMID,NULL) == -1)
  {
    perror("Erreur de shmctl");
  }

  exit(1);
}