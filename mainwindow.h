#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "evenement.h"
#include "notif.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_clicked();

  //  void on_pushButton_3_clicked();

  //  void on_pushButton_2_clicked();

   // void on_pushButton_7_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox1_activated(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    notif n;
   // evenement e;
 /* MainWindow *ajouter;
     MainWindow *modifier;
  MainWindow *afficher;
  MainWindow *supp;*/

};

#endif // MAINWINDOW_H
