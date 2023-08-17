#include <PIDcontroller.h>


PIDcontroller::PIDcontroller(double _kP, double _kI, double _kD) {
    kP = _kP;
    kI = _kI;
    kD = _kD;
}

void PIDcontroller::printError() {
    Serial.println(error);
}

void PIDcontroller::calculateOutput(double _error) {
    error = _error;
    if (error>5) error = last_error;
    if (error<-5) {
        if (last_error>0) error=5;
        else if (last_error<0) error = -5;
        else error = 0;
    }
    P = error;
    I += error;
    D = error - last_error;
    output = kP*P + kI*I + kD*D;
    last_error = error; 
};