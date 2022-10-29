#include "mainwindowex4.h"
#include "ui_mainwindowex4.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


extern MainWindowEx4 *w;

int idFils1, idFils2, idFils3;

// TO DO : HandlerSIGCHLD
void HandlerSIGCHLD(int);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindowEx4::MainWindowEx4(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindowEx4)
{
  ui->setupUi(this);
  ui->pushButtonAnnulerTous->setVisible(false);
  struct sigaction A;
  // armement de SIGCHLD
  // TO DO
  A.sa_handler = HandlerSIGCHLD;
  sigemptyset(&A.sa_mask);
  A.sa_flags = 0;

  if (sigaction(SIGCHLD, &A, NULL) == -1){
      perror("Erreur de sigaction !");
      exit(1);
    }
}

MainWindowEx4::~MainWindowEx4()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx4::setGroupe1(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe1->clear();
    return;
  }
  ui->lineEditGroupe1->setText(Text);
}

void MainWindowEx4::setGroupe2(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe2->clear();
    return;
  }
  ui->lineEditGroupe2->setText(Text);
}

void MainWindowEx4::setGroupe3(const char* Text)
{
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe3->clear();
    return;
  }
  ui->lineEditGroupe3->setText(Text);
}

void MainWindowEx4::setResultat1(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat1->clear();
    return;
  }
  ui->lineEditResultat1->setText(Text);
}

void MainWindowEx4::setResultat2(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat2->clear();
    return;
  }
  ui->lineEditResultat2->setText(Text);
}

void MainWindowEx4::setResultat3(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  //fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat3->clear();
    return;
  }
  ui->lineEditResultat3->setText(Text);
}

bool MainWindowEx4::traitement1Selectionne()
{
  return ui->checkBoxTraitement1->isChecked();
}

bool MainWindowEx4::traitement2Selectionne()
{
  return ui->checkBoxTraitement2->isChecked();
}

bool MainWindowEx4::traitement3Selectionne()
{
  return ui->checkBoxTraitement3->isChecked();
}

const char* MainWindowEx4::getGroupe1()
{
  if (ui->lineEditGroupe1->text().size())
  { 
    strcpy(groupe1,ui->lineEditGroupe1->text().toStdString().c_str());
    return groupe1;
  }
  return NULL;
}

const char* MainWindowEx4::getGroupe2()
{
  if (ui->lineEditGroupe2->text().size())
  { 
    strcpy(groupe2,ui->lineEditGroupe2->text().toStdString().c_str());
    return groupe2;
  }
  return NULL;
}

const char* MainWindowEx4::getGroupe3()
{
  if (ui->lineEditGroupe3->text().size())
  { 
    strcpy(groupe3,ui->lineEditGroupe3->text().toStdString().c_str());
    return groupe3;
  }
  return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowEx4::StartJob(bool isSelected, const char *group)
{
  int idFils;
  char buff[50];
  if(isSelected && group != NULL)
  {
      if((idFils= fork() ) == 0)
      {
        //processus fils1
        sprintf(buff, "%d", 200);
        
        if(execlp("Taitement","TraitementFils1",group,buff,NULL) ==-1)
        {
          perror("erreur de execl()");
          exit(1);
        }
    
      }
  }
  return idFils;
}

void MainWindowEx4::on_pushButtonDemarrerTraitements_clicked()
{
  fprintf(stderr,"Clic sur le bouton Demarrer Traitements\n");
  // TO DO
  char buff[50];
  int fd;

  

  fd = open("Trace.log", O_CREAT | O_APPEND | O_WRONLY, 0666);
  if(fd == -1)
  {
    perror("erreur d'ouverture");
  }
  if(dup2(fd,2)==-1)
  {
    perror("erreur de duplication du descripteur");
    exit(1);
  }

  /*if(sigaction(SIGCHLD,&A,NULL)==-1)
  {
      perror("erreur de sigaction");
      exit(1);
  }*/


  /*idFils1 = StartJob(traitement1Selectionne(), getGroupe1());
  idFils2 = StartJob(traitement2Selectionne(), getGroupe2());
  idFils3 = StartJob(traitement3Selectionne(), getGroupe3());*/

  if(traitement1Selectionne() && getGroupe1() != NULL)
  {
    if((idFils1 = fork()) == 0)
    {
      sprintf(buff, "%d", 200);
      if(execl("Traitement","TraitementFils1",getGroupe1(),buff,NULL) == -1)
      {
        perror("erreur de execl()");
        exit(1);
      }
    }
  }
  if(traitement2Selectionne() && getGroupe2() != NULL)
  {
    if((idFils2 = fork()) == 0)
    {
      sprintf(buff, "%d", 450);
      if(execl("Traitement","TraitementFils2",getGroupe2(),buff,NULL) == -1)
      {
        perror("erreur de execl()");
        exit(1);
      }
    }
  }
  if(traitement3Selectionne()&& getGroupe3() != NULL)
  {
    if((idFils3 = fork()) == 0)
    {
      sprintf(buff, "%d", 700);
      if(execl("Traitement","TraitementFils3",getGroupe3(),buff,NULL) == -1)
      {
        perror("erreur de execl()");
        exit(1);
      }
    }
  }



}

void MainWindowEx4::on_pushButtonVider_clicked()
{
  fprintf(stderr,"Clic sur le bouton Vider\n");
  // TO DO
  ui->lineEditGroupe1->setText("");
  ui->lineEditGroupe2->setText("");
  ui->lineEditGroupe3->setText("");
  ui->lineEditResultat1->setText("");
  ui->lineEditResultat2->setText("");
  ui->lineEditResultat3->setText("");
}

void MainWindowEx4::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  exit(0);
}

void MainWindowEx4::on_pushButtonAnnuler1_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler1\n");
  if(traitement1Selectionne()&&getGroupe1()!=NULL)
  {
    if(kill(idFils1,0)==0)
    {
      kill(idFils1,SIGUSR1);
    }
    else
    {
      perror("erreur du kill");
    }
  }
}

void MainWindowEx4::on_pushButtonAnnuler2_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler2\n");
  if(traitement2Selectionne()&&getGroupe2()!=NULL)
  {
    if(kill(idFils2,0)==0)
    {
      kill(idFils2,SIGUSR1);

    }
    else
    {
      perror("erreur du kill");
    }
  }
}

void MainWindowEx4::on_pushButtonAnnuler3_clicked()
{
  fprintf(stderr,"Clic sur le bouton Annuler3\n");
  if(traitement3Selectionne()&&getGroupe3()!=NULL)
  {
    if(kill(idFils3,0)==0)
    {
      kill(idFils3,SIGUSR1);
    }
    else
    {
      perror("erreur du kill");
    }
  }
}

void MainWindowEx4::on_pushButtonAnnulerTous_clicked()
{
  // fprintf(stderr,"Clic sur le bouton Annuler tout\n");
  // NOTHING TO DO --> bouton supprimé
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////// Handlers de signaux //////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TO DO : HandlerSIGCHLD
void HandlerSIGCHLD(int Sig)
{
  int id, status;  
   if ((id = wait(&status)) != -1)
   {
    if (WIFEXITED(status))
    {
      if (id == idFils1)
        w->setResultat1(WEXITSTATUS(status));
      else if (id == idFils2)
        w->setResultat2(WEXITSTATUS(status));
      else if (id == idFils3)
        w->setResultat3(WEXITSTATUS(status));
    }
  }
  
}