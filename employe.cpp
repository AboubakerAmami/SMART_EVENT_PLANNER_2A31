#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

//

Employe::Employe()
{
id=0; nom=" "; prenom=" ";  num_tel=0; email=" ";
}


Employe::Employe(int id,QString nom,QString prenom,int num_tel,QString email)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->num_tel=num_tel;
    this->email=email;
}


int Employe::getid(){return id;}
QString Employe::getnom(){return nom;}
QString Employe::getprenom(){return prenom;}
int Employe::getnum_tel(){return num_tel;}
QString Employe::getemail(){return email;}


void Employe::setid(int id){this->id=id;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setnum_tel(int num_tel){this->num_tel=num_tel;}
void Employe::setemail(QString email){this->email=email;}





bool Employe::ajouterEmploye()
{

     QSqlQuery query;
     query.prepare("INSERT INTO EMPLOYE (ID, NOM, PRENOM , NUM_TEL, EMAIL) "
                   "VALUES (:id, :nom, :prenom, :num_tel, :email)");
     query.bindValue(":id", id); //remplir CIN2 dans CIN1
     query.bindValue(":nom", nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     return query.exec();

}


bool Employe::supprimerEmploye(int id)
{
    QSqlQuery query;
    query.prepare(" Delete from EMPLOYE where id=:id ");
    query.bindValue(":id",id);

    return query.exec();
}




QSqlQueryModel* Employe::afficherEmploye()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM EMPLOYE ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

     return model;
}





bool Employe::modifierEmploye(int id,QString nom,QString prenom,int num_tel,QString email)
{

    QSqlQuery query;
    query.prepare("update EMPLOYE set nom=:nom,prenom=:prenom,num_tel=:num_tel,email=:email where id=:id");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":email",email);
    return query.exec();

}





QSqlQueryModel* Employe::RechercheEmploye(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM employe WHERE id LIKE '"+recherche+"%' OR nom LIKE '"+recherche+"%' OR prenom LIKE '"+recherche+"%' OR num_tel LIKE '"+recherche+"%' OR email LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));

return model;
}





QSqlQueryModel * Employe::trierEmployeParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}



QSqlQueryModel * Employe::trierEmployeParnom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}




QSqlQueryModel * Employe::trierEmployeParprenom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by prenom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}




