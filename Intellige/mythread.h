#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class Mythread : public QThread
{
    Q_OBJECT

public:
    explicit Mythread(QTcpSocket *sock = 0);

protected:
    void run();

private:
    QTcpSocket *socket;

signals:
    void sendMsg(QString);

private slots:
    void readMsg();
};

#endif // MYTHREAD_H
