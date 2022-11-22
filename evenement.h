#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
class evenement
{
private :
    int numero ;
    QString tyype,emplacement,responsable,datetime;

public:


    evenement();
    evenement(int num,QString tpe,QString emp,QString res , QString dt)
    {
        this->numero=num;
        this->responsable=res;
        this->tyype=tpe;
        this->emplacement=emp;
      this->datetime=dt;


    }
    evenement (int num)
    {
        this->numero=num;
    }

    bool ajouter();
   QSqlQueryModel *afficher();
    bool modifier ();
    bool supprimer ();
};

#endif // EVENEMENT_H
