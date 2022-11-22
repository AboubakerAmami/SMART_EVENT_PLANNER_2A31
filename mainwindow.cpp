#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QFile>
#include <QFileDialog>
#include <QDataStream>
#include <QTextStream>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include "notif.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//ui->numero( new QIntValidator(100, 9999999, this));
   evenement e;
ui->tableevent->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pb_ajouter_clicked()
{

}*/


/*void MainWindow::on_pb_supp_clicked()
{
Salle S1;
S1.setnombre(ui->le_numerosupp->text().toInt());
bool test=S1.supprimer(S1.getnombre());
if(test){


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppresion successful.\n"
                            "suppresion effectuer."), QMessageBox::Cancel);
ui->tab_Salle->setModel(S1.afficher());
}
else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("suppresion failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_clicked()
{
    ui->tab_Salle->setModel(S1.afficher());
}



void MainWindow::on_pb_ajouter_3_clicked()
{
  Salle S1;

       int ref =ui->numero->text().toInt();
       QString  modele=ui->equipement->text();
      QString etat =ui->le_prenom->text();
      QString date =ui->le_date->text();
      int  prix=ui->le_prix->text().toInt();

   Salle E(numerO,tyype,equipement,nombre);
   bool test=E.modifier(ref);
   ui->tablesalle->setModel(S1.afficher());

   if(test)



     {

       QMessageBox::information(nullptr, QObject::tr("SUCCESS"),

                   QObject::tr("update successful.\n"

                               "modifaction effectuer."), QMessageBox::Cancel);





   }

   else



       QMessageBox::critical(nullptr, QObject::tr("ERROR"),

                   QObject::tr("connection failed.\n"

                               "Click Cancel to exit."), QMessageBox::Cancel);

}
*/

/*void MainWindow::on_ajouter_clicked()
{
    int numero =ui->numero->text().toInt();
      //QString tyype =ui->tyype->text();
  if (QComboBox::AdjustToContents==1)
    //if ( ui->tyype==reunion)
       QString equipement =ui->l_equipement->text();
           int nombre =ui->le_nombre->text().toInt();

Salle S(numero,tyype,equipement,nombre);
bool test=S.ajouter();
ui->tab_Salle->setModel(S1.afficher());
if(test)


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout successful.\n"
                            "ajout effectuer."), QMessageBox::Cancel);


else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}*/


/*void MainWindow::on_ajouter_clicked()
{

  int n= ui->numero->text().toInt();
  int no= ui->nombre->text().toInt();
  // QString num=QString::number(numero);

  QString numero_string=QString::number(n);
  QString nombre_string=QString::number(no);
      QString tpe ;
      if (ui->reunion->isCheckable())
      {
          tpe="reunion";
      }
      else if (ui->revision->isCheckable())
      {
          tpe="revision";     }


      QString eqp;
  if (ui->data->isCheckable())
  {
      eqp= "DATA SHOW";
  }
  else if (ui->ordinateur->isCheckable())
  {
      eqp="ORDINATEUR";
  }
  else if (ui->tableau->isCheckable())
  {
      eqp="TABLEAU";
  }
  else if (ui->clima->isCheckable())
  {
      eqp="CLIMATISATION";
  }
//salle s(num,nbr,tpe,eqp);
//salle s(int num,int nbr,QString tpe,QString eqp);

  QSqlQuery query;
salle s(n,no,tpe,eqp);
bool test=s.ajouter();
  if (test)
  {
     QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                 QObject::tr("Create successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tablesalle->setModel(s.afficher());


  }
  else

     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                 QObject::tr("create  failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


  }


void MainWindow::on_pushButton_3_clicked()
{
    int num =ui->numeroooo->text().toInt();
    salle s (num);
    bool test =s.supprimer();
    if (test)
    {

      //s.afficher();
      ui->tablesalle->setModel(s.afficher());

       QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                   QObject::tr("delete sucessful \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("delete failed \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_pushButton_2_clicked()
{
    int n= ui->numero->text().toInt();
    int no= ui->nombre->text().toInt();
    // QString num=QString::number(numero);

    QString numero_string=QString::number(n);
    QString nombre_string=QString::number(no);
        QString tpe ;
        if (ui->reunion->isCheckable())
        {
            tpe="reunion";
        }
        else if (ui->revision->isCheckable())
        {
            tpe="revision";     }


        QString eqp;
    if (ui->data->isCheckable())
    {
        eqp= "DATA SHOW";
    }
    else if (ui->ordinateur->isCheckable())
    {
        eqp="ORDINATEUR";
    }
    else if (ui->tableau->isCheckable())
    {
        eqp="TABLEAU";
    }
    else if (ui->clima->isCheckable())
    {
        eqp="CLIMATISATION";
    }
  //salle s(num,nbr,tpe,eqp);
  //salle s(int num,int nbr,QString tpe,QString eqp);

    QSqlQuery query;
  salle s(n,no,tpe,eqp);
  bool test=s.modifier();
    if (test)
    {
       QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                   QObject::tr("update successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tablesalle->setModel(s.afficher());


    }
    else

       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("update failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


    }


*/
void MainWindow::on_ajouter_clicked()
{
    int num= ui->numero->text().toInt();
    QString emp= ui->emplacement->text();


    // QString num=QString::number(numero);

    QString numero_string=QString::number(num);
   // QString nombre_string=QString::number(no);
        QString tpe ;
        if (ui->mariage->isCheckable())
        {
            tpe="mariage";
        }
        else if (ui->fian->isCheckable())
        {
            tpe="fiançaille";     }
   else if (ui->anniv->isCheckable())
    {
        tpe= "anniversaire";
    }
    else if (ui->babysho->isCheckable())
    {
        tpe="baby shower";
    }
    else if (ui->souten->isCheckable())
    {
        tpe="soutenance";
    }
        QString resp= ui->responsable->text();
        QString dt= ui->date->text();

  //salle s(num,nbr,tpe,eqp);
  //salle s(int num,int nbr,QString tpe,QString eqp);

    QSqlQuery query;
  evenement e( num,tpe, emp,resp ,  dt);
;
  bool test=e.ajouter();
    if (test)
    {
       QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                   QObject::tr("Create successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tableevent->setModel(e.afficher());


    }
    else

       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("create  failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


    notif n("event ajouter avec succees \n","");
            n.afficher();
    }




void MainWindow::on_supprimer_clicked()
{
  int num =ui->numero->text().toInt();
  evenement e (num);
  bool test =e.supprimer();
  if (test)
  {

    //s.afficher();
    ui->tableevent->setModel(e.afficher());

     QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                 QObject::tr("delete sucessful \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else

     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                 QObject::tr("delete failed \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

  notif n("event supprimer avec succees \n","");
          n.afficher();


}

void MainWindow::on_modifier_clicked()
{
  int num= ui->numero->text().toInt();
  QString emp= ui->emplacement->text();


  // QString num=QString::number(numero);

  QString numero_string=QString::number(num);
 // QString nombre_string=QString::number(no);
      QString tpe ;
      if (ui->mariage->isCheckable())
      {
          tpe="mariage";
      }
      else if (ui->fian->isCheckable())
      {
          tpe="fiançaille";     }
 else if (ui->anniv->isCheckable())
  {
      tpe= "anniversaire";
  }
  else if (ui->babysho->isCheckable())
  {
      tpe="baby shower";
  }
  else if (ui->souten->isCheckable())
  {
      tpe="soutenance";
  }
      QString resp= ui->responsable->text();
      QString dt= ui->date->text();

//salle s(num,nbr,tpe,eqp);
//salle s(int num,int nbr,QString tpe,QString eqp);

  QSqlQuery query;
evenement e( num,tpe, emp,resp ,  dt);
;
bool test=e.modifier();
  if (test)
  {
     QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                 QObject::tr("update successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tableevent->setModel(e.afficher());


  }
  else

     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                 QObject::tr("update  failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

  notif n("event modifier"
          " avec succees \n","");
          n.afficher();
  }




void MainWindow::on_recherche_textChanged(const QString &arg1)
{
         QSqlQueryModel *modal=new QSqlQueryModel();
             QSqlQuery request;
            QString val=ui->recherche->text();
            val="%"+val+"%";
         //   if (type=="id")
     request.prepare("SELECT * FROM event WHERE NUMERO LIKE:val OR emplacement LIKE:val OR tyype LIKE:val OR responsable LIKE:val OR datetime LIKE:val");
            request.bindValue(":val",val);
            request.exec();
            modal->setQuery(request);
            ui->tableevent->setModel(modal);
}

void MainWindow::on_comboBox1_activated(const QString &arg1)  // tri
{
  QString val=arg1;

          QString val1=ui->comboBox1->currentText();
//          val="%"+val+"%";
          if (val=="Numero"){
              QSqlQueryModel * modal= new QSqlQueryModel();
              QSqlQuery request;
                  request.prepare("select * from event order by NUMERO DESC");
                  request.exec();
                  modal->setQuery(request);
                  ui->tableevent->setModel(modal);    }
          else if (val=="Emplacement"){
              QSqlQueryModel * modal= new QSqlQueryModel();
              QSqlQuery request;
                  request.prepare("select * from event order by emplacement DESC");
                  request.exec();
                  modal->setQuery(request);
                  ui->tableevent->setModel(modal); }else if (val=="tyype"){
              QSqlQueryModel * modal= new QSqlQueryModel();
              QSqlQuery request;
                  request.prepare("select * from event order by tyype DESC");
                  request.exec();
                  modal->setQuery(request);
                  ui->tableevent->setModel(modal);
      }else if (val=="datetime"){
              QSqlQueryModel * modal= new QSqlQueryModel();
              QSqlQuery request;
                  request.prepare("select * from event order by DATETIME DESC");
                  request.exec();
                  modal->setQuery(request);
                  ui->tableevent->setModel(modal); }
          else if (val=="responsable"){
                      QSqlQueryModel * modal= new QSqlQueryModel();
                      QSqlQuery request;
                          request.prepare("select * from event order by responsable DESC");
                          request.exec();
                          modal->setQuery(request);
                          ui->tableevent->setModel(modal); }
}


void MainWindow::on_pushButton_5_clicked()   // fichie excel
{

      ui->pushButton_5->width(), ui->pushButton_5->height();

      int i=0;

      QTableView *table;
                 table = ui->tableevent;
                 QString filters("CSV files (*.csv);;All files (*.*)");
                 QString defaultFilter("CSV files (*.csv)");
                 QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                    filters, &defaultFilter);
                 QFile file(fileName);
                 QAbstractItemModel *model =  table->model();
                 if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                     QTextStream data(&file);
                     QStringList strList;
                     for (int i = 0; i < model->columnCount(); i++) {
                         if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                             strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                         else
                             strList.append("");
                     }
                     data << strList.join(";") << "\n";
                     for (int i = 0; i < model->rowCount(); i++) {
                         strList.clear();
                         for (int j = 0; j < model->columnCount(); j++) {
                             if (model->data(model->index(i, j)).toString().length() > 0)
                                 strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                             else
                                 strList.append("");
                         }
                         data << strList.join(";") + "\n";
                     }
                     file.close();

                     notif n("Exporter To Excel","Exporter En Excel Avec Succées .\n");
                     n.afficher();
                 }
}

void MainWindow::on_pushButton_6_clicked()  //pdf
{

     QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tableevent->model()->rowCount();
                       const int columnCount = ui->tableevent->model()->columnCount();

                       out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                           <<  "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                           "<center> <H1>Liste des evenements </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableevent->isColumnHidden(column))  //bech yafichie anthete mte3  tableau
                               out << QString("<th>%1</th>").arg(ui->tableevent->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>"; // eli fi west tableau
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableevent->isColumnHidden(column)) {
                                   QString data = ui->tableevent->model()->data(ui->tableevent->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table> </center>\n"
                           "</body>\n"
                           "</html>\n";

                 QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                   if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                  QPrinter printer (QPrinter::PrinterResolution);
                   printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName(fileName);

                  QTextDocument doc;
                   doc.setHtml(strStream);
                   doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                   doc.print(&printer);
}

void MainWindow::on_pushButton_clicked()  // stat
{
  QLinearGradient gradient(0, 0, 0, 400);
  gradient.setColorAt(0, QColor(90, 90, 90));
  gradient.setColorAt(0.38, QColor(105, 105, 105));
  gradient.setColorAt(1, QColor(70, 70, 70));
  ui->customPlot->setBackground(QBrush(gradient));
  QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
  regen->setAntialiased(false);
  regen->setStackingGap(1);
  regen->setName("numero de evenement");
  regen->setPen(QPen(QColor(0, 168, 140).lighter(170)));
  regen->setBrush(QColor(0, 168, 140));


  // prepare x axis with country labels:
  QVector<double> ticks;
  QVector<QString> labels;
  ticks << 1 << 2 << 3 ;
  labels << "" << "" << "";
  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTicks(ticks, labels);
  ui->customPlot->xAxis->setTicker(textTicker);
  ui->customPlot->xAxis->setTickLabelRotation(60);
  ui->customPlot->xAxis->setSubTicks(false);
  ui->customPlot->xAxis->setTickLength(0, 4);
  ui->customPlot->xAxis->setRange(0, 8);
  ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
  ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
  ui->customPlot->xAxis->grid()->setVisible(true);
  ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
  ui->customPlot->xAxis->setTickLabelColor(Qt::white);
  ui->customPlot->xAxis->setLabelColor(Qt::white);

  // prepare y axis:
  ui->customPlot->yAxis->setRange(0,20);
  ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
   ui->customPlot->yAxis->setLabel("Numero des evenements \n");
  ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
  ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
  ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
  ui->customPlot->yAxis->grid()->setSubGridVisible(true);
  ui->customPlot->yAxis->setTickLabelColor(Qt::white);
  ui->customPlot->yAxis->setLabelColor(Qt::white);
  ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
  ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

  // Add data:
  QVector<double> regenData;
  int yos;
  QSqlQuery query;
  query.prepare("SELECT COUNT(*) FROM event where numero >20 ");
  query.exec();
  query.next();
  int numberOfPages = query.value(0).toInt();
  qDebug()<<numberOfPages;
  QSqlQuery query1;
      query1.prepare("SELECT COUNT(*) FROM event where numero <20 ");
      query1.exec();
      query1.next();
      int numberOfPages1 = query1.value(0).toInt();
      QSqlQuery query2;
          query2.prepare("SELECT COUNT(*) FROM event ");
          query2.exec();
          query2.next();
          int numberOfPages2 = query2.value(0).toInt();

  QSqlQueryModel * model= new QSqlQueryModel();
  model->setQuery("select count(*) from event");



  QSqlQuery queri("select count(*) from event where numero = 3 ");
  while (queri.next()) {
                         yos = queri.value(0).toInt();

                           }
  regenData << numberOfPages << numberOfPages1 << numberOfPages2;
  regen->setData(ticks, regenData);

  // setup legend:
  ui->customPlot->legend->setVisible(true);
  ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
  ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
  ui->customPlot->legend->setBorderPen(Qt::NoPen);
  QFont legendFont = font();
  legendFont.setPointSize(10);
  ui->customPlot->legend->setFont(legendFont);
  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

