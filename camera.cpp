#include "camera.h"
#include "ui_camera.h"

camera::camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);

    //Camera devices:
    setCamera(QCameraInfo::defaultCamera());
}

camera::~camera()
{
    delete ui;
}

void camera::setCamera(const QCameraInfo &cameraInfo)
{
    Camera = new QCamera(cameraInfo);
    imageCapture = new QCameraImageCapture(Camera);
    Camera->setViewfinder(ui->viewfinder);
    connect(imageCapture, &QCameraImageCapture::readyForCaptureChanged, this, &camera::readyForCapture);
    Camera->start();
}


void camera::readyForCapture(bool ready)
{
    ui->takeImageButton->setEnabled(ready);
}

void camera::on_takeImageButton_clicked()
{
    isCapturingImage = true;
    QString path = "C:/Users/Pc/Desktop/Proj/IMG/Clients";
    imageCapture->capture(path);
}
