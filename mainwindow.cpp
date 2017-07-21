#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();

    kas = 0;
    UPLoad = CLOSE;
    videoMonitor = CLOSE;
    mutex_im = new QMutex( QMutex::Recursive );

    serial_control = new SerialService();
    motorA = new Motor();
    motorB = new Motor();
    tempA = new Temp_Humi_Ligh();
    tempB = new Temp_Humi_Ligh();
    //QFile file("/home/log.txt");

    timer1 = new QTimer();
    timer2 = new QTimer();
    timer3 = new QTimer();
    timer4 = new QTimer();
    timer5 = new QTimer();
    timer6 = new QTimer();
    timer7 = new QTimer();

    this->video = new Video(ui->videoWin);
    //ui->videoWin->hide();

    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress("115.159.199.129"), 6666);

    connect(this->serial_control, SIGNAL(receiveMsgFromSerial(QByteArray)), this, SLOT(handleMSG(QByteArray)));
    connect(this, SIGNAL(goMsg(QString)), this, SLOT(upMsg(QString)));
    connect(this->socket, SIGNAL(connected()), this, SLOT(setUpload()));
    connect(ui->Pwm_light, SIGNAL(valueChanged(int)), this, SLOT(setPwm(int)));

    connect(this->timer1, SIGNAL(timeout()), this, SLOT(disConnected1()));
    connect(this->timer2, SIGNAL(timeout()), this, SLOT(disConnected2()));
    connect(this->timer3, SIGNAL(timeout()), this, SLOT(disConnected3()));
    connect(this->timer4, SIGNAL(timeout()), this, SLOT(disConnected4()));
    connect(this->timer5, SIGNAL(timeout()), this, SLOT(disConnected5()));
    connect(this->timer6, SIGNAL(timeout()), this, SLOT(disConnected6()));
    connect(this->timer7, SIGNAL(timeout()), this, SLOT(disConnected7()));


    //serial_control->openCom();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPwm(int value)
{
    unsigned char light = Pwm::PWM_VALUE[value];
    Pwm::PWM_INFO[4] = light;
    Pwm::PWM_INFO[5] = 0x50 + light;

    if(serial_control->writeToSerial(Pwm::PWM_INFO) == FAIL)
    {
        emit goMsg("Pwm set fail!");
        return ;
    }
    emit goMsg("Pwm set success!");
}

void MainWindow::handleMSG(QByteArray msg)
{
    if(msg.length() < 6)
        return ;

    //温度传感器
    if(0x02 == msg[3] && 0x01 == msg[4])
    {
        QString str = "";
        if(0x01 == msg[2]) //1号传感器
        {
            timer3->start(timeBlock);
            tempA->ValueOf(msg);
            upLcd_display(tempA, idA);

            if(kas++ >= 50)
            {
                kas = 0;
                emit goMsg("Update temphumlight A value!");
            }
        }
        else if(0x02 == msg[2]) //2号传感器
        {
            timer4->start(timeBlock);
            tempB->ValueOf(msg);
            upLcd_display(tempB, idB);

            if(kas++ >= 50)
            {
                kas = 0;
                emit goMsg("Update temphumlight B value!");
            }
         }
    }
    else if(0x06 == msg[3])
    {
        if(0x01 == msg[2])
        {
            timer1->start(timeBlock);
            emit goMsg("Led all on!");
        }
        else if(0x02 == msg[3])
        {
            timer2->start(timeBlock);
            emit goMsg("Led all off!");
        }
     }
     else if(0x09 == msg[3])
     {
        timer5->start(timeBlock);
        emit goMsg("Pwm is working!");
     }
     else if(0x04 == msg[3])
     {
        timer7->start(timeBlock);
        if(0x01 == msg[5])
        {
            ui->Smoke_but->setStyleSheet(PINK);
            ui->Smoke_but->setText("WORK");
            emit goMsg("Now have smoke!");
        }
        else
        {
            ui->Smoke_but->setStyleSheet(WHITE);
            ui->Smoke_but->setText("FREE");
            emit goMsg("Now no smoke!");
        }
     }
     else if(0x05 == msg[3])
     {
        timer6->start(timeBlock);
        if(0x01 == msg[5])
        {
            ui->Pir_but->setStyleSheet(PINK);
            ui->Pir_but->setText("WORK");
            emit goMsg("Now have people!");
        }
        else
        {
            ui->Pir_but->setStyleSheet(WHITE);
            ui->Pir_but->setText("FREE");
            emit goMsg("Now no people!");
        }
     }
}

void MainWindow::changeMotor(int ID, int status)
{
    //socket->write("----------------\n");
    //socket->flush();
    if(status == OTHERS)
    {
        if(ID == motorAid)
        {
            if(serial_control->writeToSerial(Motor::MotorB_AON) == FAIL)
            {
                emit goMsg("Led all on fail!");
                return ;
            }
            ui->Led_ALLON->setStyleSheet(PINK);
            ui->Led_ALLOF->setStyleSheet(WHITE);
            emit goMsg("Led all off success!");
        }
        else if(ID == motorBid)
        {
            if(serial_control->writeToSerial(Motor::MotorB_AOF) == FAIL)
            {
                emit goMsg("Led all off fail!");
                return ;
            }
            ui->Led_ALLOF->setStyleSheet(PINK);
            ui->Led_ALLON->setStyleSheet(WHITE);
            emit goMsg("Led all on success!");
        }
    }
    else if(ID == motorAid)
    {
        if(status == preRun)
        {
            if(serial_control->writeToSerial(Motor::MotorA_Pre) == FAIL)
            {
                emit goMsg("Motor A just fail!");
                return ;
            }
            motorA->setStatus(WORKING);
            ui->motorA_but_pre->setStyleSheet(PINK);
            ui->motorA_but_stp->setStyleSheet(WHITE);
            ui->motorA_but_suf->setStyleSheet(WHITE);
            emit goMsg("Motor A just success!");
        }
        else if(status == stpRun)
        {
            if(serial_control->writeToSerial(Motor::MotorA_Stp) == FAIL)
            {
                emit goMsg("Motor A stop fail!");
                return ;
            }
            motorA->setStatus(STOPPING);
            ui->motorA_but_pre->setStyleSheet(WHITE);
            ui->motorA_but_stp->setStyleSheet(PINK);
            ui->motorA_but_suf->setStyleSheet(WHITE);
            emit goMsg("Motor A stop success!");
        }
        else if(status == sufRun)
        {
            if(serial_control->writeToSerial(Motor::MotorA_Suf) == FAIL)
            {
                emit goMsg("Motor A back fail!");
                return ;
            }
            motorA->setStatus(rWORKING);
            ui->motorA_but_pre->setStyleSheet(WHITE);
            ui->motorA_but_stp->setStyleSheet(WHITE);
            ui->motorA_but_suf->setStyleSheet(PINK);
            emit goMsg("Motor A back success!");
        }
    }
    else if(ID == motorBid)
    {
        if(status == preRun)
        {
            if(serial_control->writeToSerial(Motor::MotorB_Pre) == FAIL)
            {
                emit goMsg("Motor B just fail!");
                return ;
            }
            motorB->setStatus(WORKING);
            ui->motorB_but_pre->setStyleSheet(PINK);
            ui->motorB_but_stp->setStyleSheet(WHITE);
            ui->motorB_but_suf->setStyleSheet(WHITE);
            emit goMsg("Motor B just success!");
        }
        else if(status == stpRun)
        {
            if(serial_control->writeToSerial(Motor::MotorB_Stp) == FAIL)
            {
                emit goMsg("Motor B stop fail!");
                return ;
            }
            motorB->setStatus(STOPPING);
            ui->motorB_but_pre->setStyleSheet(WHITE);
            ui->motorB_but_stp->setStyleSheet(PINK);
            ui->motorB_but_suf->setStyleSheet(WHITE);
            emit goMsg("Motor B stop successful!");
        }
        else if(status == sufRun)
        {
            if(serial_control->writeToSerial(Motor::MotorB_Suf) == FAIL)
            {
                emit goMsg("Motor B back fail!");
                return ;
            }
            motorB->setStatus(rWORKING);void on_motorB_but_suf_clicked();
            ui->motorB_but_pre->setStyleSheet(WHITE);
            ui->motorB_but_stp->setStyleSheet(WHITE);
            ui->motorB_but_suf->setStyleSheet(PINK);
            emit goMsg("Motor B back successful!");
        }
    }
}

void MainWindow::upMsg(QString mesg)
{
    ui->msgInfo->append(mesg);
    if(UPLoad == OPEN)
    {
        QString str = mesg + "\r\n";
        socket->write(str.toAscii());
        socket->flush();
        socket->write("-------------\r\n");
        socket->flush();
    }
}

void MainWindow::openSerial()
{
    if(serial_control->openCom())
    {
        ui->open_Serial->setText("OFF");
        ui->open_Serial->setStyleSheet(PINK);
        emit goMsg("Open serial success!");
    }
    else
        emit goMsg("Open serial fail!");
}

void MainWindow::closeSerial()
{
    //on_open_Serial_clicked();
    //LOCK;
    retUI();
    changeMotor(motorAid, stpRun);
    changeMotor(motorBid, stpRun);
    changeMotor(motorBid, OTHERS);
    if(serial_control->closeCom())
        emit goMsg("Close serial success!");
    else
        emit goMsg("Close serial fail!");
    //UNLOCK;
}



void MainWindow::on_open_Serial_clicked()
{
    //timer1->start(2000);
    if(serial_control->getComState() == OPEN) closeSerial();
    else openSerial();
}

void MainWindow::on_motorA_but_pre_clicked()
{
    changeMotor(motorAid, preRun);
}

void MainWindow::on_motorA_but_stp_clicked()
{
    changeMotor(motorAid, stpRun);
}

void MainWindow::on_motorA_but_suf_clicked()
{
    changeMotor(motorAid, sufRun);
}

void MainWindow::on_motorB_but_pre_clicked()
{
    changeMotor(motorBid, preRun);
}

void MainWindow::on_motorB_but_stp_clicked()
{
    changeMotor(motorBid, stpRun);
}

void MainWindow::on_motorB_but_suf_clicked()
{
    changeMotor(motorBid, sufRun);
}

void MainWindow::upLcd_display(Temp_Humi_Ligh * tmp, int mark)
{
    if(mark == idA)
    {
        ui->lcdA_t->display(tmp->getTemp());
        ui->lcdA_h->display(tmp->getHumi());
        ui->lcdA_l->display(tmp->getLigh());
    }
    else if(mark == idB)
    {
        ui->lcdB_t->display(tmp->getTemp());
        ui->lcdB_h->display(tmp->getHumi());
        ui->lcdB_l->display(tmp->getLigh());
    }
}

void MainWindow::initUI()
{
    //ui->PWM_line->setRange(1,9);
    //ui->PWM_line->setTickPosition(QSlider::TicksRight);
    //ui->PWM_line->setPageStep(1);
    //ui->PWM_line->setVisible(1);
    //ui->horizontalSlider->hide();

    ui->Pwm_light->setRange(1,9);
    ui->Pwm_light->setTickPosition(QSlider::TicksRight);
    ui->Pwm_light->setPageStep(1);

    ui->Pir_but->setStyleSheet(WHITE);
    ui->Smoke_but->setStyleSheet(WHITE);
    ui->upLoad->hide();
    ui->label_5->hide();
    ui->screenShot->setStyleSheet(WHITE);
    ui->vMonitor->setStyleSheet(WHITE);
    ui->upLoad->setStyleSheet(WHITE);
    ui->Led_ALLOF->setStyleSheet(PINK);
    ui->Led_ALLON->setStyleSheet(WHITE);
    ui->motorA_but_pre->setStyleSheet(WHITE);
    ui->motorA_but_stp->setStyleSheet(PINK);
    ui->motorA_but_suf->setStyleSheet(WHITE);
    ui->motorB_but_pre->setStyleSheet(WHITE);
    ui->motorB_but_stp->setStyleSheet(PINK);
    ui->motorB_but_suf->setStyleSheet(WHITE);
    ui->open_Serial->setStyleSheet(WHITE);

    ui->lcdA_t->setNumDigits(8);
    ui->lcdA_t->setPalette(Qt::black);
    ui->lcdA_h->setNumDigits(8);
    ui->lcdA_h->setPalette(Qt::black);
    ui->lcdA_l->setNumDigits(8);
    ui->lcdA_l->setPalette(Qt::black);
    ui->lcdB_t->setNumDigits(8);
    ui->lcdB_t->setPalette(Qt::black);
    ui->lcdB_h->setNumDigits(8);
    ui->lcdB_h->setPalette(Qt::black);
    ui->lcdB_l->setNumDigits(8);
    ui->lcdB_l->setPalette(Qt::black);
}

void MainWindow::retUI()
{
    ui->open_Serial->setText("ON");
    ui->open_Serial->setStyleSheet(WHITE);
    ui->vMonitor->setText("ON");

    ui->Pir_but->setStyleSheet(WHITE);
    ui->Pir_but->setText("FREE");
    ui->Smoke_but->setStyleSheet(WHITE);
    ui->Smoke_but->setText("FREE");

    ui->motorA_but_pre->setStyleSheet(WHITE);
    ui->motorA_but_stp->setStyleSheet(PINK);
    ui->motorA_but_suf->setStyleSheet(WHITE);
    ui->motorB_but_pre->setStyleSheet(WHITE);
    ui->motorB_but_stp->setStyleSheet(PINK);
    ui->motorB_but_suf->setStyleSheet(WHITE);
}

void MainWindow::on_upLoad_clicked()
{
    //timer1->stop();
    if(UPLoad == CLOSE)
        startUpload();
    else if(UPLoad == OPEN)
        closeUpload();
}

void MainWindow::startUpload()
{
    UPLoad = OPEN;
    ui->upLoad->setText("OFF");
    ui->upLoad->setStyleSheet(PINK);
    socket->connectToHost(QHostAddress("115.159.199.129"), 6666);
    emit goMsg("Connect server!");
}

void MainWindow::closeUpload()
{
    UPLoad = CLOSE;

    ui->upLoad->setText("ON");
    ui->upLoad->setStyleSheet(WHITE);
    socket->close();
    emit goMsg("Disconnetc server!");
//    socket->disconnect()
}

void MainWindow::on_vMonitor_clicked()
{
    if(videoMonitor == CLOSE)
        openMonitor();
    else if(videoMonitor == OPEN)
        closeMonitor();
}

void MainWindow::openMonitor()
{
    ui->vMonitor->setText("OFF");
    ui->vMonitor->setStyleSheet(PINK);
    videoMonitor = OPEN;
    ui->videoWin->show();
    ui->msgInfo->hide();
    ui->label->hide();
    //ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();
    ui->label_17->hide();
    ui->label_18->hide();

    ui->lcdA_h->hide();
    ui->lcdA_l->hide();
    ui->lcdA_t->hide();
    ui->lcdB_h->hide();
    ui->lcdB_l->hide();
    ui->lcdB_t->hide();

    //ui->Pwm_light->hide();
    ui->Pir_but->hide();
    ui->Smoke_but->hide();
    this->video->devInit();
    emit goMsg("Open monitor!");
}

void MainWindow::closeMonitor()
{
    this->video->devRele();

    ui->vMonitor->setText("ON");
    ui->vMonitor->setStyleSheet(WHITE);
    //ui->videoWin->hide();

    videoMonitor = CLOSE;
    ui->msgInfo->show();
    ui->label->show();
    //ui->Pwm_light->show();
    ui->Pir_but->show();
    ui->Smoke_but->show();
    //ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->label_13->show();
    ui->label_14->show();
    ui->label_15->show();
    ui->label_16->show();
    ui->label_17->show();
    ui->label_18->show();

    ui->lcdA_h->show();
    ui->lcdA_l->show();
    ui->lcdA_t->show();
    ui->lcdB_h->show();
    ui->lcdB_l->show();
    ui->lcdB_t->show();

    emit goMsg("Close monitor!");
}

void MainWindow::on_screenShot_clicked()
{
    video->pic_write = true;
}

void MainWindow::on_Led_ALLON_clicked()
{
    changeMotor(motorAid, OTHERS);
}

void MainWindow::on_Led_ALLOF_clicked()
{
    changeMotor(motorBid, OTHERS);
}

void MainWindow::disConnected1()
{
    timer1->stop();
    emit goMsg("Motor A disconnect!");
}

void MainWindow::disConnected2()
{
    timer2->stop();
    emit goMsg("Motor B disconnect!");
}

void MainWindow::disConnected3()
{
    timer3->stop();
    emit goMsg("TempHumLight A disconnect!");
}

void MainWindow::disConnected4()
{
    timer4->stop();
    emit goMsg("TempHumLight B disconnect!");
}

void MainWindow::disConnected5()
{
    timer5->stop();
    emit goMsg("Pwm disconnect!");
}

void MainWindow::disConnected6()
{
    timer6->stop();
    emit goMsg("Pir disconnect!");
}

void MainWindow::disConnected7()
{
    timer7->stop();
    emit goMsg("Smoke disconnect!");
}
void MainWindow::setUpload()
{
    if(UPLoad == OPEN)
        UPLoad = CLOSE;
    else
        UPLoad = OPEN;
}
