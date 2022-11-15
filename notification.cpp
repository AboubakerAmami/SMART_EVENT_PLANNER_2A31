#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}
//
void notification::notification_ajoutemploye()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employes ","nouveau Employe est ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimeremploye(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employes","un Employe est supprimé",QSystemTrayIcon::Information,15000);
}


void notification::notification_modifieremploye(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Employes ","un Employe est modifié",QSystemTrayIcon::Information,15000);

}
