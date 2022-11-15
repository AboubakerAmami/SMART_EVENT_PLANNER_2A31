#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QApplication>
#include <QPixmap>


#include<QPieSlice >
#include<QPieSeries>
#include<QtCharts>
#include <QSqlQuery>
#include "notification.h"

//
notification N;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Afficher_clicked()
{
    ui->tableView_employe->setModel(E.afficherEmploye());
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    int id=ui->lineEdit_id->text().toInt(); //convertir en entier
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    int num_tel=ui->lineEdit_telephone->text().toInt();
    QString email=ui->lineEdit_email->text();
    Employe E(id,nom,prenom,num_tel,email);
        bool test=E.ajouterEmploye();
        if(test)
              {
                N.notification_ajoutemploye();
                QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                            QObject::tr("ajout successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                             ui->tableView_employe->setModel(E.afficherEmploye());
              }
                            else
                                QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                            QObject::tr("ajout failed.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

             ui->lineEdit_id->clear();
             ui->lineEdit_nom->clear();
             ui->lineEdit_prenom->clear();
             ui->lineEdit_telephone->clear();
             ui->lineEdit_email->clear();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    Employe E1;
       E1.setid(ui->lineEdit_id->text().toInt());
       bool test=E1.supprimerEmploye(E1.getid());
       QMessageBox msgBox;
       if (ui->lineEdit_id->text()=="")
       {
           QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                              QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
       }
       else if (test)
       {
           N.notification_supprimeremploye();
           QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                              QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
           ui->tableView_employe->setModel(E.afficherEmploye());
       }

       ui->lineEdit_id->clear();
       ui->lineEdit_nom->clear();
       ui->lineEdit_prenom->clear();
       ui->lineEdit_telephone->clear();
       ui->lineEdit_email->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        int num_tel=ui->lineEdit_telephone->text().toInt();
        QString email=ui->lineEdit_email->text();

        Employe E(id,nom,prenom,num_tel,email);

        bool test=E.modifierEmploye(E.getid(),E.getnom(),E.getprenom(),E.getnum_tel(),E.getemail());

        QMessageBox msgBox;

        if (test)
        {
            N.notification_modifieremploye();
            QMessageBox::information(this, QObject::tr("Modification Succes"),
                               QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
            ui->tableView_employe->setModel(E.afficherEmploye());
        }
        else
        {

            QMessageBox::critical(this, QObject::tr("Modification Errer"),
                               QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);

        }

        ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_telephone->clear();
        ui->lineEdit_email->clear();
}

void MainWindow::on_tableView_employe_clicked(const QModelIndex &index)
{

        ui->lineEdit_id->setText(ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(index.row(),0)).toString());
        ui->lineEdit_nom->setText(ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(index.row(),1)).toString());
        ui->lineEdit_prenom->setText(ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(index.row(),2)).toString());
        ui->lineEdit_telephone->setText(ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(index.row(),3)).toString());
        ui->lineEdit_email->setText(ui->tableView_employe->model()->data(ui->tableView_employe->model()->index(index.row(),4)).toString());

}

void MainWindow::on_lineEdit_recherche_textChanged()
{
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView_employe->setModel(E.RechercheEmploye(rech));
}



void MainWindow::on_comboBox_tri_activated()
{
    if(ui->comboBox_tri->currentText()=="Tri Par Id")
    {
        ui->tableView_employe->setModel(E.trierEmployeParid());

    }else if(ui->comboBox_tri->currentText()=="Tri Par Nom")
    {
        ui->tableView_employe->setModel(E.trierEmployeParnom());

    }else
    {
        ui->tableView_employe->setModel(E.trierEmployeParprenom());
    }

}

void MainWindow::on_pushButton_statestique_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();
                     model->setQuery("select * from EMPLOYE where id < 10 ");
                     float id=model->rowCount();
                     model->setQuery("select * from EMPLOYE where id  between 10 and 100 ");
                     float idd=model->rowCount();
                     model->setQuery("select * from EMPLOYE where id >100 ");
                     float iddd=model->rowCount();
                     float total=id+idd+iddd;
                     QString a=QString("moins de 10  "+QString::number((id*100)/total,'f',2)+"%" );
                     QString b=QString("entre 10 et 100 "+QString::number((idd*100)/total,'f',2)+"%" );
                     QString c=QString("+100 "+QString::number((iddd*100)/total,'f',2)+"%" );
                     QPieSeries *series = new QPieSeries();
                     series->append(a,id);
                     series->append(b,idd);
                     series->append(c,iddd);
             if (id!=0)
             {QPieSlice *slice = series->slices().at(0);
              slice->setLabelVisible();
              slice->setPen(QPen());}
             if ( idd!=0)
             {
                      // Add label, explode and define brush for 2nd slice
                      QPieSlice *slice1 = series->slices().at(1);
                      //slice1->setExploded();
                      slice1->setLabelVisible();
             }
             if(iddd!=0)
             {
                      // Add labels to rest of slices
                      QPieSlice *slice2 = series->slices().at(2);
                      //slice1->setExploded();
                      slice2->setLabelVisible();
             }
                     // Create the chart widget
                     QChart *chart = new QChart();
                     // Add data to chart with title and hide legend
                     chart->addSeries(series);
                     chart->setTitle("Pourcentage Par id :Nombre Des Employes "+ QString::number(total));
                     chart->legend()->hide();
                     // Used to display the chart
                     QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->resize(1000,500);
                     chartView->show();
}

void MainWindow::on_pushButton_PDF_clicked()
{
    QPdfWriter pdf("C:\\Users\\bouali\\Documents\\Gestionemploye\\PDF_Employe.pdf");

       QPainter painter(&pdf);
       int i = 4000;
              painter.setPen(Qt::red);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste Des Employes");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(400,3300,"id");
              painter.drawText(1650,3300,"Nom");
              painter.drawText(2800,3300,"Prenom");
              painter.drawText(4000,3300,"num_tel");
              painter.drawText(5100,3300,"Email");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from EMPLOYE");
              query.exec();
              while (query.next())
              {
                  painter.drawText(400,i,query.value(0).toString());
                  painter.drawText(1650,i,query.value(1).toString());
                  painter.drawText(2800,i,query.value(2).toString());
                  painter.drawText(4000,i,query.value(3).toString());
                  painter.drawText(5100,i,query.value(4).toString());


                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}
