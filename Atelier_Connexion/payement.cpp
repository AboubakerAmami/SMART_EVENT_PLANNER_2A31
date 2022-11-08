#include "payement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Payement::Payement()
{
    code=0;
    prix=0;
    nom="";
    prenom="";

}


Payement::Payement(int code,QString nom,QString prenom,float prix)
{
    this ->code =code;
    this ->nom=nom;
    this ->prenom=prenom;
    this ->prix=prix;
}


int Payement::Get_code()
{
    return code;
}
QString Payement::Get_nom()
{
    return nom;
}
QString Payement::Get_prenom()
{
    return prenom;
}

float Payement::Get_prix()
{
    return prix;
}
void Payement::Set_code(int code)
{
    this ->code =code;
}
void Payement::Set_nom(QString nom)
{
    this ->nom=nom;
}
void Payement::Set_prenom(QString prenom)
{
   this ->prenom=prenom;
}

void Payement::Set_prix(float prix)
{
    this ->prix=prix;
}

bool Payement::ajouter()
{

    QSqlQuery query;
    QString code_string= QString::number(code);
    QString prix_string= QString::number(prix);
          query.prepare("INSERT INTO payement (code, nom, prenom, prix) "
                        "VALUES (:code1, :nom, :prenom, :prix)");
          query.bindValue(":code1", code_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":prix", prix_string);
    return query.exec();
}

bool Payement::supprimer(int code)
{
    QSqlQuery query;
          query.prepare(" Delete from payement where code=:code ");
          query.bindValue(0,code);
    return query.exec();
}

QSqlQueryModel* Payement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM payement");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));



    return model;

}

bool Payement::modifier(int code)
{
    QSqlQuery query;
    QString res=QString::number(code);
    QString prix_string1= QString::number(prix);


             query.prepare("UPDATE payement "" SET code=:code, nom=:nom, prenom=:prenom, prix=:prix where code='"+res+"' ");


                   query.bindValue(":code", res);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":prix", prix_string1);

               return query.exec();
}
























