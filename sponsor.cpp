#include "sponsor.h"

sponsor::sponsor()
{

}
sponsor::sponsor(int id,QString nom,int budget,QDate date_debut,QDate date_fin)
{
    this->id = id ;
    this->nom = nom ;
    this->budget = budget ;
    this->date_debut = date_debut ;
    this->date_fin = date_fin ;
}

int sponsor::getid_sponsor(){return id;}
QString sponsor::getnom_sponsor(){return nom;}
int sponsor::getbudget(){return budget;}
QDate sponsor::getdatedebut(){return date_debut;}
QDate sponsor::getdatefin(){return date_fin;}


void sponsor::setid_sponsor(int id){this->id=id;}
void sponsor::setnom_sponsor(QString nom){this->nom=nom;}
void sponsor::setbudget(int budget){this->budget=budget;}
void sponsor::setdatedebut(QDate date_debut){this->date_debut=date_debut;}
void sponsor::setdatefin(QDate date_fin){this->date_fin=date_fin;}




QSqlQueryModel* sponsor::affichersponsor()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM sponsor ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant sponsor"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom sponsor"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Budget"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Debut contract"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Fin contract"));

     return model;
}


bool sponsor::ajoutersponsor()
{

     QSqlQuery query;
     query.prepare("INSERT INTO sponsor (id, nom, budget , date_debut , date_fin) "
                   "VALUES (:id, :nom, :budget, :date_debut ,:date_fin)");// prparation de requette
     query.bindValue(":id", id); //remplir CIN2 dans CIN1
     query.bindValue(":nom", nom);
     query.bindValue(":budget",budget);
     query.bindValue(":date_debut",date_debut);
     query.bindValue(":date_fin",date_fin);
     return query.exec();

}



bool sponsor::supprimersponsor(int id)
{
    QSqlQuery query;
    query.prepare(" Delete from sponsor where id=:id ");
    query.bindValue(":id",id);

    return query.exec();
}




bool sponsor::modifiersponsor(int id,QString nom,int budget,QDate date_debut,QDate date_fin)
{
        QSqlQuery query;
        query.prepare("update sponsor set nom=:nom,budget=:budget,date_debut=:date_debut,date_fin=:date_fin where id=:id");
        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":budget",budget);
        query.bindValue(":date_debut",date_debut);
        query.bindValue(":date_fin",date_fin);
        return query.exec();

    }


