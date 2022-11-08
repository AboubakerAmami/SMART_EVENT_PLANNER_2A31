#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QDebug>
#include "payement.h"

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
    void on_pushButton_clicked();


    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Payement P;
};

#endif // MAINWINDOW_H
