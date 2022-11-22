#ifndef CLIENT_H
#define CLIENT_H
 #include<QString>
#include<QSqlQuery>
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlQueryModel>
class client
{
private:
    QString ID_CLIENT,nom,prenom,email,numero,age ;
public:
     client(QString,QString,QString,QString,QString,QString);
     client();

    void setCin(QString n){ ID_CLIENT=n;}
    void setnom(QString n){ nom=n;}
    void setprenom(QString n){ prenom=n;}
    void setemail(QString n){ email=n;}
    void setnum(QString n){ numero=n;}
    void setage(QString n){ age=n;}

    QString getCin(){return ID_CLIENT;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getemail(){return email;}
    QString getnum(){return numero;}
    QString getage(){return age;}

    bool ajouterclient();
    bool modifierclient();
    QSqlQueryModel* afficherclient();
    bool supprimerclient(QString);
    QStringList recherche_client();

    void stat(QCustomPlot *customPlot);
    QSqlQueryModel * tri();
    QSqlQueryModel * tri_id();
    QSqlQueryModel * rechercher(QString);



};

#endif // CLIENT_H
