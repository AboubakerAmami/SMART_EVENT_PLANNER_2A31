#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "QTextStream"
#include "QFileDialog"
#include <QPrinter>
#include <QDate>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /*////////////////////////CONTROLE DE SAISIE///////////////////////////////////*/
    ui->lineEdit_cin->setValidator( new QIntValidator(0, 999999999, this));
    ui->lineEdit_num->setValidator( new QIntValidator(0, 999999999, this));
    ui->lineEdit_num_3->setValidator( new QIntValidator(0, 999999999, this));
    ui->lineEdit_num_2->setValidator( new QIntValidator(0, 999999999, this));
    ui->lineEdit_num_4->setValidator( new QIntValidator(0, 999999999, this));
    /*/////////////////////////////////////////////////////////////////////////////*/


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_9_currentChanged(int index)
{
    client c;
    ui->tableView_3->setModel(c.afficherclient());
    ui->comboBox->clear();
     ui->comboBox->addItems(c.recherche_client());
     c.stat(ui->widget); // c client , stat : function fel classe client , ui->widget


}

void MainWindow::on_pushButton_ajouter_2_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,email,numero,age ;

          cin=ui->lineEdit_cin->text();
          nom=ui->lineEdit_nom->text();
          prenom=ui->lineEdit_prenom->text();
          email=ui->lineEdit_adresse_5->text();
          numero=ui->lineEdit_num->text();
          age=ui->lineEdit_num_3->text();


          client C( cin , nom, prenom, email, numero,age);
          bool test=C.ajouterclient();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("Ajouter client"),
                                                   QObject::tr("client ajouté .\n"
                                                               "Click Cancel to exit ."),QMessageBox::Cancel);
           }
           else
           {
              QMessageBox::critical(nullptr,QObject::tr("Ajouter client"),
                                               QObject::tr("ERooR .\n"
                                                           "Click Cancel to exit ."),QMessageBox::Cancel);
            }

}

void MainWindow::on_pushButton_modifier_2_clicked()
{
    QSqlQuery qry ;
      QString   cin,nom,prenom,email,numero,age ;

       cin=ui->comboBox->currentText();
             nom=ui->lineEdit_nom_2->text();
             prenom=ui->lineEdit_prenom_2->text();
          email=ui->lineEdit_adresse_6->text();
          numero=ui->lineEdit_num_2->text();
          age=ui->lineEdit_num_4->text();

          client c( cin , nom, prenom, email, numero,age);
          bool test=c.modifierclient();
               if (test)
                  {
                   QMessageBox::information(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Modifié .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);

                   }
                   else
                   {
                   QMessageBox::critical(nullptr,QObject::tr("Modifier client"),
                                                    QObject::tr("client Non Modifié .\n"
                                                                "Click Cancel to exit ."),QMessageBox::Cancel);
                    }

}

void MainWindow::on_pushButton_32_clicked()
{
//    QSqlQuery qry;
//        client c;


//         QVariant id_cc = ui->tableView_3->model()->data(ui->tableView_3->selectionModel()->currentIndex(),Qt::DisplayRole);
//         QString idc = id_cc.toString();
//         QMessageBox::StandardButton reply;
//           reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce client?",
//                                         QMessageBox::Yes|QMessageBox::No);
//           if (reply == QMessageBox::Yes) {
//               bool test=c.supprimerclient(idc);
//               if(test)
//               {
//                   ui->tableView_3->setModel(c.afficherclient());

//               }
//           }


}

void MainWindow::on_pushButton_33_clicked()
{
    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_3->model()->rowCount();
    const int columnCount = ui->tableView_3->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");//***************************************
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - CLIENTS LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> LISTE DES CLIENTS </strong></h1>"
        "<h5 style=\"text-align: center;\">Le : "+TT+"</h5>"
        "<br>\n"
        "<table style=\"text-align: center; font-size: 12;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_3->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_3->isColumnHidden(column)) {
                QString data =ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}

void MainWindow::on_pushButton_34_clicked()
{
    client c;
    ui->tableView_3->setModel(c.tri());

}

void MainWindow::on_lineEdit_recherche_2_textEdited(const QString &arg1)
{
    client c;
    ui->tableView_3->setModel(c.rechercher(arg1));

}

void MainWindow::on_deleteButton_clicked()
{
    QSqlQuery qry;
        client c;


         QVariant id_cc = ui->tableView_3->model()->data(ui->tableView_3->selectionModel()->currentIndex(),Qt::DisplayRole);
         QString idc = id_cc.toString();
         QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce client?",
                                         QMessageBox::Yes|QMessageBox::No);
           if (reply == QMessageBox::Yes) {
               bool test=c.supprimerclient(idc);
               if(test)
               {
                   ui->tableView_3->setModel(c.afficherclient());

               }
           }

}
