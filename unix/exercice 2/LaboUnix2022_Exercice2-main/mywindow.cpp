#include "mywindow.h"
#include "ui_mywindow.h"

#include <stdio.h>
#include "FichierClient.h"

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    // Configuration de la table des clients (ne pas modifier)
    ui->tableWidgetClients->setColumnCount(2);
    ui->tableWidgetClients->setRowCount(0);
    QStringList labelsTableClients;
    labelsTableClients << "Nom" << "Hash du mot de passe";
    ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
    ui->tableWidgetClients->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidgetClients->horizontalHeader()->setVisible(true);
    ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(300);
    ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetClients->verticalHeader()->setVisible(false);
    ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Exemples d'utilisation (à supprimer)
    setResultat(" ---- Bonjour !!! ---- ");
    ajouteTupleTableClients("wagner",10);
}

MyWindow::~MyWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles : ne pas modifier /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setNom(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditNom->clear();
    return;
  }
  ui->lineEditNom->setText(Text);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* MyWindow::getNom()
{
  strcpy(_nom,ui->lineEditNom->text().toStdString().c_str());
  return _nom;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setMotDePasse(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditMotDePasse->clear();
    return;
  }
  ui->lineEditMotDePasse->setText(Text);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* MyWindow::getMotDePasse()
{
  strcpy(_motDePasse,ui->lineEditMotDePasse->text().toStdString().c_str());
  return _motDePasse;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MyWindow::isNouveauClientChecked()
{
  if (ui->checkBoxNouveauClient->isChecked()) return 1;
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::setResultat(const char* Text)
{
  if (strlen(Text) == 0 )
  {
    ui->lineEditResultat->clear();
    return;
  }
  ui->lineEditResultat->setText(Text);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Clients (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::ajouteTupleTableClients(const char* nom,int hash)
{
    char Hash[20];
    sprintf(Hash,"%d",hash);

    // Ajout
    int nbLignes = ui->tableWidgetClients->rowCount();
    nbLignes++;
    ui->tableWidgetClients->setRowCount(nbLignes);
    ui->tableWidgetClients->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    auto flags = item->flags();
    flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
    item->setFlags(flags);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(nom);
    ui->tableWidgetClients->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    flags = item->flags();
    flags.setFlag(Qt::ItemIsEditable, false).setFlag(Qt::ItemIsSelectable, false);
    item->setFlags(flags);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Hash);
    ui->tableWidgetClients->setItem(nbLignes-1,1,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::videTableClients()
{
    ui->tableWidgetClients->setRowCount(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::on_pushButtonLogin_clicked()
{
  // Récupération nom et mot de passe
  char nom[20],motDePasse[20];
  int nouveauClient,status;
  strcpy(nom,getNom());
  strcpy(motDePasse,getMotDePasse());
  nouveauClient = isNouveauClientChecked();
  if (nouveauClient){
       if ((status = estPresent(nom)) >= 1)
            setResultat("Client déja existant !");
       else if (status == 0 || status == -1){
            ajouteClient(nom, motDePasse);
            setResultat("Nouveau client créé : bienvenue !"); 
       }
    }
    else{
        if ((status = estPresent(nom)) == 0)
            setResultat("Client inconnu...");
        else{
            if (verifieMotDePasse(status, motDePasse))
                setResultat("Re-bonjour cher client !");
            else
                setResultat("Mot de passe incorrect...");
                
        }
   }
  // TO DO
  printf("Clic sur bouton LOGIN\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MyWindow::on_pushButtonAfficheFichier_clicked()
{
  
  CLIENT *clients = new CLIENT[100];
    int clients_count = 0;
    int i;

    clients_count = listeClients(clients);
    
    videTableClients();
    
    for (i = 0; i < clients_count; i++)
        ajouteTupleTableClients(clients[i].nom, clients[i].hash);
  // TO DO
  printf("Clic sur bouton AFFICHER\n");
}
