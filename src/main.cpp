#include <main.h>

uint8_t inputPin[5]={26,25,33,32,35};
// uint16_t threshold[5]={740,740,740,740,740};
esp32_motor leftMotor(14,27,5,6,50000,10);
esp32_motor rightMotor(13,12,7,8,50000,10);
line_status error(inputPin, threshold);

PIDcontroller lineFollow(KP,KI,KD);

void setup() {
  Serial.begin(9600);
}

void loop() {
  error.updateLineStatus();
  PIDcontroller.calculateOutput(error.getError());
  // leftMotor.Run(basePWM+lineFollow.output);
  // rightMotor.Run(basePWM-lineFollow.output);

  // // Test Error

  lineFollow.printError();

  // // Test DC

  // leftMotor.Run(500);
  // rightMotor.Run(500);
  // delay(3000);
  // leftMotor.Run(0);
  // rightMotor.Run(0);
  // delay(3000);
  // leftMotor.Run(-500);
  // rightMotor.Run(-500);
  // delay(3000);
  // leftMotor.Run(0);
  // rightMotor.Run(0);
  // delay(3000);

}
