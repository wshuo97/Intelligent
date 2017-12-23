#include "motor.h"

Motor::Motor()
{
}

const QByteArray Motor::MotorA_Pre("\x40\x06\x01\x06\x0a\x57", 6);
const QByteArray Motor::MotorA_Suf("\x40\x06\x01\x06\x0b\x58", 6);
const QByteArray Motor::MotorA_Stp("\x40\x06\x01\x06\x0c\x59", 6);

const QByteArray Motor::MotorB_Pre("\x40\x06\x02\x06\x0a\x58", 6);
const QByteArray Motor::MotorB_Suf("\x40\x06\x02\x06\x0b\x59", 6);
const QByteArray Motor::MotorB_Stp("\x40\x06\x02\x06\x0c\x5a", 6);
const QByteArray Motor::MotorB_AON("\x40\x06\x02\x06\x0d\x5b", 6);
const QByteArray Motor::MotorB_AOF("\x40\x06\x02\x06\x0e\x5c", 6);
