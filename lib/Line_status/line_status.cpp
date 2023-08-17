#include <line_status.h>

line_status::line_status(uint8_t* _pin, uint16_t * _threshold) {
    pin = _pin;
    threshold = _threshold;
    pinMode(pin[0], INPUT);
    pinMode(pin[1], INPUT);
    pinMode(pin[2], INPUT);
    pinMode(pin[3], INPUT);
    pinMode(pin[4], INPUT);
}

void line_status::updateLineStatus() {
    for (auto i = 0; i < 5; i++) status[i] = digitalRead(pin[i]);
}

int8_t line_status::getError() {
    if (status[0] & !status[1] & !status[2] & !status[3] & !status[4]) {
        error = -4;
    } else if (status[0] & status[1] & !status[2] & !status[3] & !status[4]) {
        error = -3;
    } else if (!status[0] & status[1] & !status[2] & !status[3] & !status[4]) {
        error = -2;
    } else if (!status[0] & status[1] & status[2] & !status[3] & !status[4]) {
        error = -1;
    } else if (!status[0] & !status[1] & status[2] & !status[3] & !status[4]) {
        error = 0;
    } else if (!status[0] & !status[1] & status[2] & status[3] & !status[4]) {
        error = 1;
    } else if (!status[0] & !status[1] & !status[2] & status[3] & !status[4]) {
        error = 2;
    } else if (!status[0] & !status[1] & !status[2] & status[3] & status[4]) {
        error = 3;
    } else if (!status[0] & !status[1] & !status[2] & !status[3] & status[4]) {
        error = 4;
    } else if (!status[0] & !status[1] & !status[2] & !status[3] & !status[4]) {
        error = -99;
    } else {
        error = 99;
    }
    return error;
}