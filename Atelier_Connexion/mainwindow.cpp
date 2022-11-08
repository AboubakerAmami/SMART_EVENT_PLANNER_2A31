#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include "payement.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_payement->setModel(P.afficher());
    ui->le_code->setValidator(new QIntValidator(0,9999999, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int code=ui->le_code->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    float prix=ui->le_prix->text().toFloat();
    Payement P(code,nom,prenom,prix);

    bool test=P.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_payement->setModel(P.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}


void MainWindow::on_pb_supprimer_clicked()
{
    Payement P1; P1.Set_code(ui->le_code_supp->text().toInt());
    bool test=P1.supprimer(P1.Get_code());
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_payement->setModel(P.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int code=ui->code_mod->text().toInt();
    QString nom=ui->nom_mod->text();
    QString prenom=ui->prenom_mod->text();
    float prix=ui->prix_mod->text().toFloat();
    Payement P(code,nom,prenom,prix);

    bool test=P.modifier(code);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("modification successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_payement->setModel(P.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("modification failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
