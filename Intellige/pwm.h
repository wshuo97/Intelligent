#ifndef PWM_H
#define PWM_H

#include "enddevice.h"

class Pwm : Enddevice
{
public:
    explicit Pwm();

    static QByteArray PWM_VALUE;

    static QByteArray PWM_INFO;

};

#endif // PWM_H
