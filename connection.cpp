#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()

{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;

    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("54224709");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::createConnection(){db.close();}