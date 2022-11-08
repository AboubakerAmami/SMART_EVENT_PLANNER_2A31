#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "sponsor.h"

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
    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_tableView_sponsor_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    sponsor S;
};

#endif // MAINWINDOW_H
