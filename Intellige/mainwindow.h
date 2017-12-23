#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMutex>
#include <QTimer>
#include <QFile>
#include <QThread>
#include <QString>

#include "posix_qextserialport.h"
#include "temp_humi_ligh.h"
#include "qextserialbase.h"
#include "serialservice.h"
#include "enddevice.h"
#include "camerainit.h"
#include "motor.h"
#include "video.h"
#include "pwm.h"
#include "pir.h"
#include "smoke.h"
#include "mythread.h"

#define LOCK     mutex_im->lock();
#define UNLOCK   mutex_im->lock();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void changeMotor(int,int);
    
    void openSerial(void);

    void closeSerial(void);

    void upLcd_display(Temp_Humi_Ligh*,int);

    void initUI();

    void retUI();

    void startUpload();

    void closeUpload();

    void openMonitor();

    void closeMonitor();

private slots:
    void on_motorA_but_pre_clicked();

    void upMsg(QString);

    void handleMSG(QByteArray);

    void on_open_Serial_clicked();

    void on_motorA_but_stp_clicked();

    void on_motorA_but_suf_clicked();

    void on_motorB_but_pre_clicked();

    void on_motorB_but_stp_clicked();

    void on_motorB_but_suf_clicked();

    void on_upLoad_clicked();

    void on_vMonitor_clicked();

    void on_screenShot_clicked();

    void on_Led_ALLON_clicked();

    void on_Led_ALLOF_clicked();

    void setUpload();

    void disConnected1();

    void disConnected2();

    void disConnected3();

    void disConnected4();

    void disConnected5();

    void disConnected6();

    void disConnected7();

    void setPwm(int);

    void toControl(QString);

signals :
    void goMsg(QString);

    void genMsg(QString);

private:
    Ui::MainWindow *ui;

private :
    SerialService *serial_control;
    QTcpSocket *socket;
    Motor *motorA;
    Motor *motorB;
    Temp_Humi_Ligh *tempA;
    Temp_Humi_Ligh *tempB;
    QMutex *mutex_im;
    Video *video;
    Mythread *thread;
    //QFile file;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *timer6;
    QTimer *timer7;

};

#endif // MAINWINDOW_H
