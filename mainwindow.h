#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notif.h"
#include "camera.h"
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_9_currentChanged(int index);

    void on_pushButton_ajouter_2_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_lineEdit_recherche_2_textEdited(const QString &arg1);

    void readfile();


    void on_pushButton_clicked();

    void on_pushButton_35_clicked();

private:
    Ui::MainWindow *ui;
     camera *c;
     QMediaPlayer* player;
     QVideoWidget* vw;



};
#endif // MAINWINDOW_H
