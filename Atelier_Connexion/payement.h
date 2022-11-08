#ifndef PAYEMENT_H
#define PAYEMENT_H

#include <QString>
#include <QSqlQueryModel>
class Payement
{
public:
    Payement();
    Payement(int,QString,QString,float);
    int Get_code();
    QString Get_nom();
    QString Get_prenom();
    float Get_prix();
    void Set_code(int);
    void Set_nom(QString);
    void Set_prenom(QString);
    void Set_prix(float);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);

private:
    int code;
    QString nom,prenom;
    float prix;
};

#endif // PAYEMENT_H
