#include "video.h"
#include "ui_video.h"

#include <stdio.h>

Video::Video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);

    //deviceOpen();
    //deviceInit();

    pic_write = false;
    timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(up_date()));
}

Video::~Video()
{
    delete ui;
}

void Video::devInit()
{
    ui->vDisplay->show();
    captureStart();
    timer->start(300);
}

void Video::devRele()
{
    //deviceUninit();
    ui->vDisplay->hide();
    timer->stop();
}

void Video::up_date()
{
    unsigned char image_buf[1536000+54];

    frameRead(image_buf);
    this->Imagedata = QImage::fromData(image_buf, 800*480*4+54, NULL);
    Pixmap = QPixmap::fromImage(this->Imagedata, 0);
    ui->vDisplay->setPixmap(this->Pixmap);

    if(pic_write)
    {
        FILE *bmp = fopen("photo.bmp", "w+");
        fwrite(image_buf, 1, 800*480*4+54, bmp);
        fclose(bmp);
        pic_write = false;
    }
}

















