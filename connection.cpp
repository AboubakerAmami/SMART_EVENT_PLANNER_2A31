#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("system");//system
db.setPassword("SYSTEM");//SYSTEM

if (db.open())
test=true;





    return  test;
}


