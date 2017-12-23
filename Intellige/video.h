#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QPixmap>
#include <QProcess>

#include "camerainit.h"

namespace Ui {
class Video;
}

class Video : public QWidget
{
    Q_OBJECT
    
public :
    bool pic_write;

public:
    explicit Video(QWidget *parent = 0);
    ~Video();
    
    void devInit();

    void devRele();

private slots :
    void up_date();

private:
    Ui::Video *ui;

private :
    QTimer *timer;
    QImage Imagedata;
    QPixmap Pixmap;
};

#endif // VIDEO_H
