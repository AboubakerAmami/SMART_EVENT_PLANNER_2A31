#include "evenement.h"


evenement::evenement()
{

}
bool evenement::ajouter()
{
    QSqlQuery query;
    //QString numero_string=QString::number(numero);
    //QString nombre_string=QString::number(nombre);
    query.prepare("INSERT INTO event  (numero,emplacement,tyype,responsable,datetime) "
      "VALUES (:numero, :emplacement, :tyype, :responsable, :datetime)");
    query.bindValue(":numero",numero);
    query.bindValue(":emplacement", emplacement);
    query.bindValue(":tyype", tyype);
    query.bindValue(":responsable",responsable );
    query.bindValue(":datetime",datetime );


return query.exec();


}
QSqlQueryModel *evenement ::afficher()
{
QSqlQueryModel*model =new QSqlQueryModel();

     model->setQuery("SELECT* FROM event ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("emplacement"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("tyype"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("responsable"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("datetime"));



          /*QTableView *view = new QTableView;
            view->setModel(model);
            view->show();*/

return model;
}
bool evenement::supprimer()
{
    QSqlQuery query;
QString numero_string= QString::number(numero);
    query.prepare("DELETE FROM event where  numero=:numero");

    query.bindValue(":numero",numero_string);

return query.exec();




}
bool evenement::modifier()
{
    QSqlQuery query;
    query.prepare("update event set numero=:numero, responsable=:responsable, tyype=:tyype,emplacement=:emplacement,datetime=:datetime where numero=:numero");
    query.bindValue(":numero",numero );
    query.bindValue(":responsable", responsable);
    query.bindValue(":tyype", tyype);
    query.bindValue(":emplacement",emplacement );
    query.bindValue(":datetime",datetime );

    return query.exec();

}
