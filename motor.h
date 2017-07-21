#ifndef MOTOR_H
#define MOTOR_H

#include "enddevice.h"

class Motor : public Enddevice
{
public:
    explicit Motor();

public :
    const static QByteArray MotorA_Pre;
    const static QByteArray MotorA_Suf;
    const static QByteArray MotorA_Stp;

    const static QByteArray MotorB_Pre;
    const static QByteArray MotorB_Suf;
    const static QByteArray MotorB_Stp;
    const static QByteArray MotorB_AON;
    const static QByteArray MotorB_AOF;
};

#endif // MOTOR_H
