#include "mainwindowex3.h"
#include "ui_mainwindowex3.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

MainWindowEx3::MainWindowEx3(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindowEx3)
{
    ui->setupUi(this);
}

MainWindowEx3::~MainWindowEx3()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowEx3::setGroupe1(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe1->clear();
    return;
  }
  ui->lineEditGroupe1->setText(Text);
}

void MainWindowEx3::setGroupe2(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe2->clear();
    return;
  }
  ui->lineEditGroupe2->setText(Text);
}

void MainWindowEx3::setGroupe3(const char* Text)
{
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditGroupe3->clear();
    return;
  }
  ui->lineEditGroupe3->setText(Text);
}

void MainWindowEx3::setResultat1(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat1->clear();
    return;
  }
  ui->lineEditResultat1->setText(Text);
}

void MainWindowEx3::setResultat2(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat2->clear();
    return;
  }
  ui->lineEditResultat2->setText(Text);
}

void MainWindowEx3::setResultat3(int nb)
{
  char Text[20];
  sprintf(Text,"%d",nb);
  fprintf(stderr,"---%s---\n",Text);
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat3->clear();
    return;
  }
  ui->lineEditResultat3->setText(Text);
}

bool MainWindowEx3::recherche1Selectionnee()
{
  return ui->checkBoxRecherche1->isChecked();
}

bool MainWindowEx3::recherche2Selectionnee()
{
  return ui->checkBoxRecherche2->isChecked();
}

bool MainWindowEx3::recherche3Selectionnee()
{
  return ui->checkBoxRecherche3->isChecked();
}

const char* MainWindowEx3::getGroupe1()
{
  if (ui->lineEditGroupe1->text().size())
  { 
    strcpy(groupe1,ui->lineEditGroupe1->text().toStdString().c_str());
    return groupe1;
  }
  return NULL;
}

const char* MainWindowEx3::getGroupe2()
{
  if (ui->lineEditGroupe2->text().size())
  { 
    strcpy(groupe2,ui->lineEditGroupe2->text().toStdString().c_str());
    return groupe2;
  }
  return NULL;
}

const char* MainWindowEx3::getGroupe3()
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
int MainWindowEx3::StartJob(bool isSelected, const char *group)
{
  int idFils;
  if(isSelected && group != NULL)
  {
      if((idFils= fork() ) == 0)
      {
        //processus fils1
        
        if(execlp("Lecture","Lecture",group,NULL) ==-1)
        {
          perror("erreur de execl()");
          exit(1);
        }
    
      }
  }
  return idFils;
}

void MainWindowEx3::on_pushButtonLancerRecherche_clicked()
{
  fprintf(stderr,"Clic sur le bouton Lancer Recherche\n");
  // TO DO
  int idFils1,idFils2,idFils3,status,id;
  char buf[10];
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
  
  idFils1 = StartJob(recherche1Selectionnee(), getGroupe1());
  idFils2 = StartJob(recherche2Selectionnee(), getGroupe2());
  idFils3 = StartJob(recherche3Selectionnee(), getGroupe3());

  

  //processus pere
  while((id = wait(&status)) !=-1)
  {
    
    if(WIFEXITED(status))
    {
      if(id ==idFils1)
      {
        sprintf(buf,"%d",WEXITSTATUS(status));
        ui->lineEditResultat1->setText(buf);
      }
      else
      {
        if(id == idFils2)
        {
          sprintf(buf,"%d",WEXITSTATUS(status));
          ui->lineEditResultat2->setText(buf);
        }
        else
        {
          if(id ==idFils3)
          {
            sprintf(buf,"%d",WEXITSTATUS(status));
            ui->lineEditResultat3->setText(buf);
          }
        }
      }

    }
  }
}



void MainWindowEx3::on_pushButtonVider_clicked()
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

void MainWindowEx3::on_pushButtonQuitter_clicked()
{
  fprintf(stderr,"Clic sur le bouton Quitter\n");
  exit(0);
}
