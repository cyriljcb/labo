#include "windowclient.h"
#include "ui_windowclient.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

extern WindowClient *w;

#include "protocole.h" // contient la cle et la structure d'un message

extern char nomClient[40];
int idQ; // identifiant de la file de message
void handlerSIGUSR1(int sig);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
WindowClient::WindowClient(QWidget *parent):QMainWindow(parent),ui(new Ui::WindowClient)
{
  ui->setupUi(this);
  setWindowTitle(nomClient);

  // Recuperation de l'identifiant de la file de messages
  fprintf(stderr,"(CLIENT %s %d) Recuperation de l'id de la file de messages\n",nomClient,getpid());
    if ((idQ = msgget(CLE, 0)) == -1)
    {
      perror("Errur de recuperatoin de la cle");
      exit(1);
    }

  // Envoi d'une requete d'identification
   MESSAGE pid;

  pid.type = 1;
  pid.expediteur = getpid();
  strcpy(pid.texte, nomClient);

  if (msgsnd(idQ, &pid, sizeof(MESSAGE)-sizeof(long), 0) == -1){
    perror("Probleme de reception du pid\n");
    exit(1);
  }

  // Armement du signal SIGUSR1
  struct sigaction sigusr;
  sigusr.sa_handler = handlerSIGUSR1;
  sigusr.sa_flags = 0;
  sigemptyset(&sigusr.sa_mask);
  sigaction(SIGUSR1,&sigusr,NULL);
}

WindowClient::~WindowClient()
{
  delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::setRecu(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditRecu->clear();
    return;
  }
  ui->lineEditRecu->setText(Text);
}

void WindowClient::setAEnvoyer(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditEnvoyer->clear();
    return;
  }
  ui->lineEditEnvoyer->setText(Text);
}

const char* WindowClient::getAEnvoyer()
{
  if (ui->lineEditEnvoyer->text().size())
  { 
    strcpy(aEnvoyer,ui->lineEditEnvoyer->text().toStdString().c_str());
    return aEnvoyer;
  }
  return NULL;
}

const char* WindowClient::getRecu()
{
  if (ui->lineEditRecu->text().size())
  { 
    strcpy(recu,ui->lineEditRecu->text().toStdString().c_str());
    return recu;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WindowClient::on_pushButtonEnvoyer_clicked()
{
  fprintf(stderr,"Clic sur le bouton Envoyer\n");
  
  MESSAGE msg;
 
  msg.type = 1;
  strcpy(msg.texte, getAEnvoyer());
  msg.expediteur = getpid();

      if (msgsnd(idQ, &msg, sizeof(MESSAGE) - sizeof(long), 0) == -1)
    {
        perror("Erreur de msgsend");
        exit(1);
    }
    


}

void WindowClient::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  exit(1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Handlers de signaux ////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void handlerSIGUSR1(int sig)
{
  MESSAGE recv;
  fprintf(stderr,"(Traitement %d) Reception du signal SIGALRM (%d)\n",getpid(),sig);
    if (msgrcv(idQ, &recv, sizeof(MESSAGE)- sizeof(long), getpid(), 0) == -1)
    {
          perror("Erreur de msgrecv");
          exit(1);
    }
  w->setRecu(recv.texte);
}