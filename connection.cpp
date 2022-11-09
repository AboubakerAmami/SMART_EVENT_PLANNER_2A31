#include "connection.h"

Connection::Connection()
{
// test github push
}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("amira");//inserer nom de l'utilisateur
db.setPassword("amira");//inserer mot de passe de cet utilisateur
// test
if (db.open())
test=true;





    return  test;
}
