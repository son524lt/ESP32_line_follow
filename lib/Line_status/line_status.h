#ifndef _LINE_STATUS_H_
#define _LINE_STATUS_H_

#include <Arduino.h>

class line_status
{
private:
    uint8_t pin[5];
    uint16_t threshold[5];
public:
    bool status[5];
    line_status(uint8_t* pin, uint16_t * threshold);
    void updateLineStatus();
    int8_t getError();
};



#endif