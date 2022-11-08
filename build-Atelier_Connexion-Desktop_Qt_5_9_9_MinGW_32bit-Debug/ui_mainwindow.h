/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *Nom;
    QLabel *Prenom;
    QLabel *prix;
    QLabel *Code;
    QLineEdit *le_code;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_prix;
    QPushButton *pushButton;
    QWidget *tab_4;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLineEdit *code_mod;
    QLineEdit *nom_mod;
    QLineEdit *prenom_mod;
    QLineEdit *prix_mod;
    QWidget *tab_2;
    QTableView *tab_payement;
    QWidget *tab_3;
    QLabel *label;
    QLineEdit *le_code_supp;
    QPushButton *pb_supprimer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(587, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 20, 481, 321));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 421, 251));
        Nom = new QLabel(groupBox);
        Nom->setObjectName(QStringLiteral("Nom"));
        Nom->setGeometry(QRect(80, 70, 56, 16));
        Prenom = new QLabel(groupBox);
        Prenom->setObjectName(QStringLiteral("Prenom"));
        Prenom->setGeometry(QRect(70, 110, 56, 16));
        prix = new QLabel(groupBox);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setGeometry(QRect(70, 160, 56, 16));
        Code = new QLabel(groupBox);
        Code->setObjectName(QStringLiteral("Code"));
        Code->setGeometry(QRect(80, 30, 56, 16));
        le_code = new QLineEdit(groupBox);
        le_code->setObjectName(QStringLiteral("le_code"));
        le_code->setGeometry(QRect(150, 30, 113, 22));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(150, 70, 113, 22));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(150, 110, 113, 22));
        le_prix = new QLineEdit(groupBox);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(150, 160, 113, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 210, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 451, 271));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 230, 93, 28));
        label1 = new QLabel(groupBox_2);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(50, 30, 56, 16));
        label2 = new QLabel(groupBox_2);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(50, 70, 56, 16));
        label3 = new QLabel(groupBox_2);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(50, 120, 56, 16));
        label4 = new QLabel(groupBox_2);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(50, 180, 56, 16));
        code_mod = new QLineEdit(groupBox_2);
        code_mod->setObjectName(QStringLiteral("code_mod"));
        code_mod->setGeometry(QRect(150, 30, 113, 22));
        nom_mod = new QLineEdit(groupBox_2);
        nom_mod->setObjectName(QStringLiteral("nom_mod"));
        nom_mod->setGeometry(QRect(150, 80, 113, 22));
        prenom_mod = new QLineEdit(groupBox_2);
        prenom_mod->setObjectName(QStringLiteral("prenom_mod"));
        prenom_mod->setGeometry(QRect(150, 130, 113, 22));
        prix_mod = new QLineEdit(groupBox_2);
        prix_mod->setObjectName(QStringLiteral("prix_mod"));
        prix_mod->setGeometry(QRect(150, 180, 113, 22));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_payement = new QTableView(tab_2);
        tab_payement->setObjectName(QStringLiteral("tab_payement"));
        tab_payement->setGeometry(QRect(0, 0, 471, 291));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 120, 101, 31));
        le_code_supp = new QLineEdit(tab_3);
        le_code_supp->setObjectName(QStringLiteral("le_code_supp"));
        le_code_supp->setGeometry(QRect(160, 130, 113, 22));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(340, 130, 93, 28));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 587, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        Nom->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        Prenom->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        prix->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        Code->setText(QApplication::translate("MainWindow", "Code", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter un payement", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Modifer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label1->setText(QApplication::translate("MainWindow", "code", Q_NULLPTR));
        label2->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label3->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label4->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Modifier un payement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les payements", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Code", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer un payement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
