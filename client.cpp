#include "client.h"
#include<QMessageBox>

client::client()
{
    ID_CLIENT="";
    nom="";
    prenom="";
    email="";
    numero="";
    age="";
}

client::client( QString ID_CLIENT, QString nom,QString prenom,QString email, QString numero,QString age)
{
    this->ID_CLIENT=ID_CLIENT;
    this->nom=nom;
    this->prenom=prenom ;
    this->email=email ;
    this->numero=numero ;
    this->age=age ;
}

bool client::ajouterclient()
{
    QSqlQuery qry ;
    qry.prepare("insert into CLIENT values ('"+ID_CLIENT+"','"+nom+"','"+prenom+"','"+email+"','"+numero+"','"+age+"')") ;
       qry.bindValue(":ID_CLIENT",ID_CLIENT);
       qry.bindValue(":NOM",nom);
       qry.bindValue(":PRENOM",prenom);
       qry.bindValue(":ADRESSE",email);
       qry.bindValue(":NUMERO",numero);
       qry.bindValue(":AGE",age);


           return qry.exec();

}

bool client::modifierclient()
{
    QSqlQuery qry ;

       qry.prepare("update CLIENT set  AGE='"+age+"',NOM_CLIENT='"+nom+"',PRENOM_CLIENT='"+prenom+"',EMAIL_CLIENT='"+email+"',TEL_CLIENT='"+numero+"' where ID_CLIENT='"+ID_CLIENT+"' ");
       qry.bindValue(":ID_CLIENT",ID_CLIENT);
       qry.bindValue(":AGE",age);
       qry.bindValue(":NOM_CLIENT",nom);
       qry.bindValue(":PRENOM_CLIENT",prenom);
       qry.bindValue(":EMAIL_CLIENT",email);
       qry.bindValue(":TEL_CLIENT",numero);


          return qry.exec();
}

QSqlQueryModel* client::afficherclient()
{

    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM CLIENT;");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
          return model;

}


bool client::supprimerclient(QString id_c)
{
    QSqlQuery query;

    query.prepare("DELETE FROM CLIENT WHERE ID_CLIENT = :id_c ");
    query.bindValue(":id_c", id_c);
    return    query.exec();


}
QStringList client::recherche_client()
{
    QSqlQuery query;
    query.prepare("select ID_CLIENT from CLIENT");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
void client::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));

    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    fossil->setAntialiased(false);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Clients");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(*) FROM CLIENT where AGE between 0 and 15");
    query.exec();
    int i;
    while(query.next())
    {
        i=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(*) FROM CLIENT where AGE between 15 and 20");
    query.exec();
    int j;
    while(query.next())
    {
        j=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(*) FROM CLIENT where AGE > 20");
    query.exec();
    int k;
    while(query.next())
    {
        k=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "[ 0 ,15 ]" << "[ 15 ,20  ]"<<"Plus que 20" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Intervalle de nombre des clients");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << i << j << k;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
QSqlQueryModel* client::tri()
{

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT ORDER BY NOM_CLIENT;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
          return model;

}
QSqlQueryModel* client::tri_id()
{

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT ORDER BY ID_CLIENT;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
          return model;

}
QSqlQueryModel * client::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT where ID_CLIENT like '%"+a+"%' ||'%' OR NOM_CLIENT like '%"+a+"%' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));
    return model;
}





