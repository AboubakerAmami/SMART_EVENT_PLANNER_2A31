#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
///
class Employe

{
public:
    Employe();
    Employe(int,QString,QString,int,QString);
    int getid();
    QString getnom();
    QString getprenom();
    int getnum_tel();
    QString getemail();



    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setnum_tel(int);
    void setemail(QString);


    bool ajouterEmploye();
    QSqlQueryModel* afficherEmploye();
    bool supprimerEmploye(int);
    bool modifierEmploye(int,QString,QString,int,QString);
    QSqlQueryModel* RechercheEmploye(QString);
    QSqlQueryModel * trierEmployeParid();
    QSqlQueryModel * trierEmployeParnom();
    QSqlQueryModel * trierEmployeParprenom();


private:
    int id,num_tel;
    QString nom,prenom,email;
};

#endif // EMPLOYES_H
