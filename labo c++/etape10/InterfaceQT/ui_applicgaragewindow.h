/********************************************************************************
** Form generated from reading UI file 'applicgaragewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICGARAGEWINDOW_H
#define UI_APPLICGARAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicGarageWindow
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionQuitter;
    QAction *actionNouveau_modele;
    QAction *actionNouvelle_option;
    QAction *actionNouveau;
    QAction *actionCharger;
    QAction *actionEnregistrer;
    QAction *actionAjouterEmploye;
    QAction *actionSupprimerEmploye_par_numero;
    QAction *actionSupprimerEmploye_selection;
    QAction *actionAjouterClient;
    QAction *actionSupprimerClient_par_numero;
    QAction *actionSupprimerClient_selection;
    QAction *actionReset_Mot_de_passe;
    QWidget *centralwidget;
    QFrame *frame;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLineEdit *lineEditNomProjet;
    QLabel *label_3;
    QLineEdit *lineEditNomModele;
    QLabel *label_4;
    QLineEdit *lineEditPuissance;
    QRadioButton *radioButtonEssence;
    QRadioButton *radioButtonElectrique;
    QRadioButton *radioButtonDiesel;
    QRadioButton *radioButtonHybride;
    QLabel *label_5;
    QLineEdit *lineEditPrixDeBase;
    QComboBox *comboBoxModelesDisponibles;
    QLabel *label_6;
    QPushButton *pushButtonChoisirModele;
    QLabel *label_7;
    QComboBox *comboBoxOptionsDisponibles;
    QPushButton *pushButtonAjouterOption;
    QLabel *label_8;
    QTableWidget *tableWidgetOptions;
    QPushButton *pushButtonSupprimerOption;
    QPushButton *pushButtonReduction;
    QLabel *label_9;
    QLineEdit *lineEditPrix;
    QPushButton *pushButtonOuvrirProjet;
    QPushButton *pushButtonEnregistrerProjet;
    QPushButton *pushButtonNouveauProjet;
    QLabel *label;
    QLabel *label_10;
    QTableWidget *tableWidgetEmployes;
    QLabel *label_11;
    QTableWidget *tableWidgetClients;
    QLabel *label_12;
    QTableWidget *tableWidgetContrats;
    QPushButton *pushButtonNouveauContrat;
    QPushButton *pushButtonSupprimerContrat;
    QPushButton *pushButtonVisualiserVoiture;
    QMenuBar *menubar;
    QMenu *menuConnexion;
    QMenu *menuVoiture;
    QMenu *menuEmployes;
    QMenu *menuClients;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ApplicGarageWindow)
    {
        if (ApplicGarageWindow->objectName().isEmpty())
            ApplicGarageWindow->setObjectName(QString::fromUtf8("ApplicGarageWindow"));
        ApplicGarageWindow->resize(750, 700);
        ApplicGarageWindow->setStyleSheet(QString::fromUtf8(""));
        actionLogin = new QAction(ApplicGarageWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogout = new QAction(ApplicGarageWindow);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionLogout->setEnabled(false);
        actionQuitter = new QAction(ApplicGarageWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionNouveau_modele = new QAction(ApplicGarageWindow);
        actionNouveau_modele->setObjectName(QString::fromUtf8("actionNouveau_modele"));
        actionNouvelle_option = new QAction(ApplicGarageWindow);
        actionNouvelle_option->setObjectName(QString::fromUtf8("actionNouvelle_option"));
        actionNouveau = new QAction(ApplicGarageWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionCharger = new QAction(ApplicGarageWindow);
        actionCharger->setObjectName(QString::fromUtf8("actionCharger"));
        actionEnregistrer = new QAction(ApplicGarageWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionAjouterEmploye = new QAction(ApplicGarageWindow);
        actionAjouterEmploye->setObjectName(QString::fromUtf8("actionAjouterEmploye"));
        actionSupprimerEmploye_par_numero = new QAction(ApplicGarageWindow);
        actionSupprimerEmploye_par_numero->setObjectName(QString::fromUtf8("actionSupprimerEmploye_par_numero"));
        actionSupprimerEmploye_selection = new QAction(ApplicGarageWindow);
        actionSupprimerEmploye_selection->setObjectName(QString::fromUtf8("actionSupprimerEmploye_selection"));
        actionAjouterClient = new QAction(ApplicGarageWindow);
        actionAjouterClient->setObjectName(QString::fromUtf8("actionAjouterClient"));
        actionSupprimerClient_par_numero = new QAction(ApplicGarageWindow);
        actionSupprimerClient_par_numero->setObjectName(QString::fromUtf8("actionSupprimerClient_par_numero"));
        actionSupprimerClient_selection = new QAction(ApplicGarageWindow);
        actionSupprimerClient_selection->setObjectName(QString::fromUtf8("actionSupprimerClient_selection"));
        actionReset_Mot_de_passe = new QAction(ApplicGarageWindow);
        actionReset_Mot_de_passe->setObjectName(QString::fromUtf8("actionReset_Mot_de_passe"));
        centralwidget = new QWidget(ApplicGarageWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 731, 381));
        frame->setStyleSheet(QString::fromUtf8("border-left-color: rgb(138, 226, 52);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 281, 151));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 279, 149));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 10, 64, 21));
        lineEditNomProjet = new QLineEdit(frame);
        lineEditNomProjet->setObjectName(QString::fromUtf8("lineEditNomProjet"));
        lineEditNomProjet->setGeometry(QRect(390, 10, 331, 25));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 50, 64, 21));
        lineEditNomModele = new QLineEdit(frame);
        lineEditNomModele->setObjectName(QString::fromUtf8("lineEditNomModele"));
        lineEditNomModele->setGeometry(QRect(390, 50, 331, 25));
        lineEditNomModele->setReadOnly(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 90, 121, 21));
        lineEditPuissance = new QLineEdit(frame);
        lineEditPuissance->setObjectName(QString::fromUtf8("lineEditPuissance"));
        lineEditPuissance->setGeometry(QRect(420, 90, 91, 25));
        lineEditPuissance->setReadOnly(true);
        radioButtonEssence = new QRadioButton(frame);
        radioButtonEssence->setObjectName(QString::fromUtf8("radioButtonEssence"));
        radioButtonEssence->setEnabled(true);
        radioButtonEssence->setGeometry(QRect(310, 130, 81, 23));
        radioButtonEssence->setCheckable(true);
        radioButtonEssence->setChecked(false);
        radioButtonElectrique = new QRadioButton(frame);
        radioButtonElectrique->setObjectName(QString::fromUtf8("radioButtonElectrique"));
        radioButtonElectrique->setGeometry(QRect(530, 130, 91, 23));
        radioButtonElectrique->setCheckable(true);
        radioButtonDiesel = new QRadioButton(frame);
        radioButtonDiesel->setObjectName(QString::fromUtf8("radioButtonDiesel"));
        radioButtonDiesel->setGeometry(QRect(430, 130, 71, 23));
        radioButtonDiesel->setCheckable(true);
        radioButtonHybride = new QRadioButton(frame);
        radioButtonHybride->setObjectName(QString::fromUtf8("radioButtonHybride"));
        radioButtonHybride->setGeometry(QRect(650, 130, 71, 23));
        radioButtonHybride->setCheckable(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 90, 101, 21));
        lineEditPrixDeBase = new QLineEdit(frame);
        lineEditPrixDeBase->setObjectName(QString::fromUtf8("lineEditPrixDeBase"));
        lineEditPrixDeBase->setGeometry(QRect(630, 90, 91, 25));
        lineEditPrixDeBase->setReadOnly(true);
        comboBoxModelesDisponibles = new QComboBox(frame);
        comboBoxModelesDisponibles->setObjectName(QString::fromUtf8("comboBoxModelesDisponibles"));
        comboBoxModelesDisponibles->setGeometry(QRect(10, 190, 291, 25));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 170, 151, 17));
        pushButtonChoisirModele = new QPushButton(frame);
        pushButtonChoisirModele->setObjectName(QString::fromUtf8("pushButtonChoisirModele"));
        pushButtonChoisirModele->setGeometry(QRect(310, 190, 61, 25));
        pushButtonChoisirModele->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 170, 151, 17));
        comboBoxOptionsDisponibles = new QComboBox(frame);
        comboBoxOptionsDisponibles->setObjectName(QString::fromUtf8("comboBoxOptionsDisponibles"));
        comboBoxOptionsDisponibles->setGeometry(QRect(390, 190, 261, 25));
        pushButtonAjouterOption = new QPushButton(frame);
        pushButtonAjouterOption->setObjectName(QString::fromUtf8("pushButtonAjouterOption"));
        pushButtonAjouterOption->setGeometry(QRect(660, 190, 61, 25));
        pushButtonAjouterOption->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 131, 17));
        tableWidgetOptions = new QTableWidget(frame);
        tableWidgetOptions->setObjectName(QString::fromUtf8("tableWidgetOptions"));
        tableWidgetOptions->setGeometry(QRect(10, 240, 421, 131));
        pushButtonSupprimerOption = new QPushButton(frame);
        pushButtonSupprimerOption->setObjectName(QString::fromUtf8("pushButtonSupprimerOption"));
        pushButtonSupprimerOption->setGeometry(QRect(440, 240, 111, 25));
        pushButtonSupprimerOption->setStyleSheet(QString::fromUtf8("background-color: orange"));
        pushButtonReduction = new QPushButton(frame);
        pushButtonReduction->setObjectName(QString::fromUtf8("pushButtonReduction"));
        pushButtonReduction->setGeometry(QRect(570, 240, 151, 25));
        pushButtonReduction->setStyleSheet(QString::fromUtf8("background-color: lightgreen"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(460, 290, 131, 21));
        lineEditPrix = new QLineEdit(frame);
        lineEditPrix->setObjectName(QString::fromUtf8("lineEditPrix"));
        lineEditPrix->setGeometry(QRect(600, 290, 121, 25));
        lineEditPrix->setReadOnly(true);
        pushButtonOuvrirProjet = new QPushButton(frame);
        pushButtonOuvrirProjet->setObjectName(QString::fromUtf8("pushButtonOuvrirProjet"));
        pushButtonOuvrirProjet->setGeometry(QRect(540, 340, 71, 25));
        pushButtonOuvrirProjet->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        pushButtonEnregistrerProjet = new QPushButton(frame);
        pushButtonEnregistrerProjet->setObjectName(QString::fromUtf8("pushButtonEnregistrerProjet"));
        pushButtonEnregistrerProjet->setGeometry(QRect(632, 340, 91, 25));
        pushButtonEnregistrerProjet->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        pushButtonNouveauProjet = new QPushButton(frame);
        pushButtonNouveauProjet->setObjectName(QString::fromUtf8("pushButtonNouveauProjet"));
        pushButtonNouveauProjet->setGeometry(QRect(440, 340, 83, 25));
        pushButtonNouveauProjet->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 131, 17));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 420, 151, 17));
        tableWidgetEmployes = new QTableWidget(centralwidget);
        tableWidgetEmployes->setObjectName(QString::fromUtf8("tableWidgetEmployes"));
        tableWidgetEmployes->setGeometry(QRect(10, 440, 351, 91));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 540, 64, 17));
        tableWidgetClients = new QTableWidget(centralwidget);
        tableWidgetClients->setObjectName(QString::fromUtf8("tableWidgetClients"));
        tableWidgetClients->setGeometry(QRect(10, 560, 351, 91));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(380, 420, 64, 17));
        tableWidgetContrats = new QTableWidget(centralwidget);
        tableWidgetContrats->setObjectName(QString::fromUtf8("tableWidgetContrats"));
        tableWidgetContrats->setGeometry(QRect(380, 440, 361, 171));
        pushButtonNouveauContrat = new QPushButton(centralwidget);
        pushButtonNouveauContrat->setObjectName(QString::fromUtf8("pushButtonNouveauContrat"));
        pushButtonNouveauContrat->setGeometry(QRect(380, 620, 91, 25));
        pushButtonSupprimerContrat = new QPushButton(centralwidget);
        pushButtonSupprimerContrat->setObjectName(QString::fromUtf8("pushButtonSupprimerContrat"));
        pushButtonSupprimerContrat->setGeometry(QRect(490, 620, 91, 25));
        pushButtonVisualiserVoiture = new QPushButton(centralwidget);
        pushButtonVisualiserVoiture->setObjectName(QString::fromUtf8("pushButtonVisualiserVoiture"));
        pushButtonVisualiserVoiture->setGeometry(QRect(600, 620, 141, 25));
        ApplicGarageWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ApplicGarageWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 22));
        menuConnexion = new QMenu(menubar);
        menuConnexion->setObjectName(QString::fromUtf8("menuConnexion"));
        menuVoiture = new QMenu(menubar);
        menuVoiture->setObjectName(QString::fromUtf8("menuVoiture"));
        menuEmployes = new QMenu(menubar);
        menuEmployes->setObjectName(QString::fromUtf8("menuEmployes"));
        menuClients = new QMenu(menubar);
        menuClients->setObjectName(QString::fromUtf8("menuClients"));
        ApplicGarageWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ApplicGarageWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ApplicGarageWindow->setStatusBar(statusbar);

        menubar->addAction(menuConnexion->menuAction());
        menubar->addAction(menuEmployes->menuAction());
        menubar->addAction(menuClients->menuAction());
        menubar->addAction(menuVoiture->menuAction());
        menuConnexion->addAction(actionLogin);
        menuConnexion->addAction(actionLogout);
        menuConnexion->addSeparator();
        menuConnexion->addAction(actionReset_Mot_de_passe);
        menuConnexion->addSeparator();
        menuConnexion->addAction(actionQuitter);
        menuVoiture->addAction(actionNouveau_modele);
        menuVoiture->addAction(actionNouvelle_option);
        menuEmployes->addAction(actionAjouterEmploye);
        menuEmployes->addSeparator();
        menuEmployes->addAction(actionSupprimerEmploye_par_numero);
        menuEmployes->addAction(actionSupprimerEmploye_selection);
        menuClients->addAction(actionAjouterClient);
        menuClients->addSeparator();
        menuClients->addAction(actionSupprimerClient_par_numero);
        menuClients->addAction(actionSupprimerClient_selection);

        retranslateUi(ApplicGarageWindow);

        QMetaObject::connectSlotsByName(ApplicGarageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ApplicGarageWindow)
    {
        ApplicGarageWindow->setWindowTitle(QApplication::translate("ApplicGarageWindow", "Application Garage", nullptr));
        actionLogin->setText(QApplication::translate("ApplicGarageWindow", "Login", nullptr));
        actionLogout->setText(QApplication::translate("ApplicGarageWindow", "Logout", nullptr));
        actionQuitter->setText(QApplication::translate("ApplicGarageWindow", "Quitter", nullptr));
        actionNouveau_modele->setText(QApplication::translate("ApplicGarageWindow", "Nouveau mod\303\250le", nullptr));
        actionNouvelle_option->setText(QApplication::translate("ApplicGarageWindow", "Nouvelle option", nullptr));
        actionNouveau->setText(QApplication::translate("ApplicGarageWindow", "Nouveau", nullptr));
        actionCharger->setText(QApplication::translate("ApplicGarageWindow", "Ouvrir", nullptr));
        actionEnregistrer->setText(QApplication::translate("ApplicGarageWindow", "Enregistrer", nullptr));
        actionAjouterEmploye->setText(QApplication::translate("ApplicGarageWindow", "Ajouter", nullptr));
        actionSupprimerEmploye_par_numero->setText(QApplication::translate("ApplicGarageWindow", "Supprimer par num\303\251ro", nullptr));
        actionSupprimerEmploye_selection->setText(QApplication::translate("ApplicGarageWindow", "Supprimer s\303\251lection", nullptr));
        actionAjouterClient->setText(QApplication::translate("ApplicGarageWindow", "Ajouter", nullptr));
        actionSupprimerClient_par_numero->setText(QApplication::translate("ApplicGarageWindow", "Supprimer par num\303\251ro", nullptr));
        actionSupprimerClient_selection->setText(QApplication::translate("ApplicGarageWindow", "Supprimer s\303\251lection", nullptr));
        actionReset_Mot_de_passe->setText(QApplication::translate("ApplicGarageWindow", "Reset Mot de passe", nullptr));
        label_2->setText(QApplication::translate("ApplicGarageWindow", "Nom :", nullptr));
        label_3->setText(QApplication::translate("ApplicGarageWindow", "Mod\303\250le :", nullptr));
        label_4->setText(QApplication::translate("ApplicGarageWindow", "Puissance (Ch) :", nullptr));
        radioButtonEssence->setText(QApplication::translate("ApplicGarageWindow", "Essence", nullptr));
        radioButtonElectrique->setText(QApplication::translate("ApplicGarageWindow", "Electrique", nullptr));
        radioButtonDiesel->setText(QApplication::translate("ApplicGarageWindow", "Diesel", nullptr));
        radioButtonHybride->setText(QApplication::translate("ApplicGarageWindow", "Hybride", nullptr));
        label_5->setText(QApplication::translate("ApplicGarageWindow", "Prix de base :", nullptr));
        label_6->setText(QApplication::translate("ApplicGarageWindow", "Mod\303\250les disponibles :", nullptr));
        pushButtonChoisirModele->setText(QApplication::translate("ApplicGarageWindow", "Choisir", nullptr));
        label_7->setText(QApplication::translate("ApplicGarageWindow", "Options disponibles :", nullptr));
        pushButtonAjouterOption->setText(QApplication::translate("ApplicGarageWindow", "Ajouter", nullptr));
        label_8->setText(QApplication::translate("ApplicGarageWindow", "Options choisies :", nullptr));
        pushButtonSupprimerOption->setText(QApplication::translate("ApplicGarageWindow", "Supprimer", nullptr));
        pushButtonReduction->setText(QApplication::translate("ApplicGarageWindow", "Accorder r\303\251duction", nullptr));
        label_9->setText(QApplication::translate("ApplicGarageWindow", "Prix avec options :", nullptr));
        pushButtonOuvrirProjet->setText(QApplication::translate("ApplicGarageWindow", "Ouvrir", nullptr));
        pushButtonEnregistrerProjet->setText(QApplication::translate("ApplicGarageWindow", "Enregistrer", nullptr));
        pushButtonNouveauProjet->setText(QApplication::translate("ApplicGarageWindow", "Nouveau", nullptr));
        label->setText(QApplication::translate("ApplicGarageWindow", "Projet en cours :", nullptr));
        label_10->setText(QApplication::translate("ApplicGarageWindow", "Employ\303\251s du garage :", nullptr));
        label_11->setText(QApplication::translate("ApplicGarageWindow", "Clients :", nullptr));
        label_12->setText(QApplication::translate("ApplicGarageWindow", "Contrats :", nullptr));
        pushButtonNouveauContrat->setText(QApplication::translate("ApplicGarageWindow", "Nouveau", nullptr));
        pushButtonSupprimerContrat->setText(QApplication::translate("ApplicGarageWindow", "Supprimer", nullptr));
        pushButtonVisualiserVoiture->setText(QApplication::translate("ApplicGarageWindow", "Visualiser Voiture", nullptr));
        menuConnexion->setTitle(QApplication::translate("ApplicGarageWindow", "Connexion", nullptr));
        menuVoiture->setTitle(QApplication::translate("ApplicGarageWindow", "Voiture", nullptr));
        menuEmployes->setTitle(QApplication::translate("ApplicGarageWindow", "Employ\303\251s", nullptr));
        menuClients->setTitle(QApplication::translate("ApplicGarageWindow", "Clients", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicGarageWindow: public Ui_ApplicGarageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICGARAGEWINDOW_H
