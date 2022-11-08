#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_id->setValidator( new QIntValidator(0,99999999, this));
    ui->lineEdit_budget->setValidator( new QIntValidator(0, 999999, this));
    ui->lineEdit_nom->setMaxLength(8);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt(); //convertir en entier
    QString nom=ui->lineEdit_nom->text();
    int budget=ui->lineEdit_budget->text().toInt();
    QDate date_debut=ui->dateEdit_debut->date();
    QDate date_fin=ui->dateEdit_fin->date();
    sponsor S(id,nom,budget,date_debut,date_fin);
        bool test=S.ajoutersponsor();
        if(test)
              {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                            QObject::tr("ajout successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->tableView_sponsor->setModel(S.affichersponsor());//mise a jour ecran
              }
                            else
                                QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                            QObject::tr("ajout failed.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

             ui->lineEdit_id->clear();
             ui->lineEdit_nom->clear();
             ui->lineEdit_budget->clear();
}

void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tableView_sponsor->setModel(S.affichersponsor());
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    sponsor S1;
    S1.setid_sponsor(ui->lineEdit_id->text().toInt());
    bool test=S1.supprimersponsor(S1.getid_sponsor());
    QMessageBox msgBox;
    if (ui->lineEdit_id->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                           QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
    }
    else if (test)
    {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                           QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView_sponsor->setModel(S.affichersponsor());
    }

    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_budget->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt(); //convertir en entier
    QString nom=ui->lineEdit_nom->text();
    int budget=ui->lineEdit_budget->text().toInt();
    QDate date_debut=ui->dateEdit_debut->date();
    QDate date_fin=ui->dateEdit_fin->date();

    sponsor S(id,nom,budget,date_debut,date_fin);

    bool test=S.modifiersponsor(S.getid_sponsor(),S.getnom_sponsor(),S.getbudget(),S.getdatedebut(),S.getdatefin());

    QMessageBox msgBox;

    if(test)
    {
        QMessageBox::information(this, QObject::tr("Modification Succes"),
                           QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
        ui->tableView_sponsor->setModel(S.affichersponsor());

    }
    else
    {

        QMessageBox::critical(this, QObject::tr("Modification Erreur"),
                           QObject::tr("Erreur de Modifications"), QMessageBox::Cancel);

    }


    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_budget->clear();


}

void MainWindow::on_tableView_sponsor_clicked(const QModelIndex &index)
{
    ui->lineEdit_id->setText(ui->tableView_sponsor->model()->data(ui->tableView_sponsor->model()->index(index.row(),0)).toString());
    ui->lineEdit_nom->setText(ui->tableView_sponsor->model()->data(ui->tableView_sponsor->model()->index(index.row(),1)).toString());
    ui->lineEdit_budget->setText(ui->tableView_sponsor->model()->data(ui->tableView_sponsor->model()->index(index.row(),2)).toString());

}
