#ifndef _PIDCONTROLLER_H_
#define _PIDCONTROLLER_H_
#include <Arduino.h>
class PIDcontroller
{
private:
    double kP, kI, kD,  P=0, I=0, D=0, error=0, last_error=0;
public:
    double output=0;
    PIDcontroller(double kP, double kI, double kD);
    void calculateOutput(double error);
    void printError();
};

#endif