#ifndef sponsor_H
#define sponsor_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QDate>

class sponsor

{
public:
    sponsor();
    sponsor(int,QString,int,QDate,QDate);
    int getid_sponsor();
    QString getnom_sponsor();
    int getbudget();
    QDate getdatedebut();
    QDate getdatefin();



    void setid_sponsor(int);
    void setnom_sponsor(QString);
    void setbudget(int);
    void setdatedebut(QDate);
    void setdatefin(QDate);


    bool ajoutersponsor();
    QSqlQueryModel* affichersponsor();
    bool supprimersponsor(int);
    bool modifiersponsor(int,QString,int,QDate,QDate);

private:
    int id,budget;
    QString nom;
    QDate date_debut,date_fin;
};



#endif // sponsor_H
