#ifndef CONSTANT_H
#define CONSTANT_H

int kas;
int UPLoad;
int videoMonitor;
const int FAIL = -1;
const int WORKING  = 0;
const int STOPPING = 1;
const int rWORKING = 2;
const int OPEN = 1;
const int CLOSE = 0;
const int OTHERS = 256;

const int preRun = 1;
const int stpRun = 2;
const int sufRun = 3;
const int motorAid = 4;
const int motorBid = 5;

/*
const int Motor1 = 1;
const int Motor2 = 2;
const int TempHumLight1 = 3;
const int TempHumLight2 = 4;
const int Pwm = 5;
const int Pir = 6;
const int Smoke = 7;
*/

const int idA = 1;
const int idB = 2;
const int timeBlock = 15000;


const QString BLUE  = "QPushButton{background:blue}";
const QString GREEN = "QPushButton{background:green}";
const QString RED   = "QPushButton{background:red}";
const QString PINK  = "QPushButton{background:pink}";
const QString BROWN = "QPushButton{background:borwn}";
const QString YELLOW= "QPushButton{background:yellow}";
const QString WHITE = "QPushButton{background:white}";

#endif // CONSTANT_H
