# ESP32 TB6612 driver for esp-idf

## Pin Configuration
 - VM: Motor VCC (<15V)
 - VCC: Logic VCC (3.3V or 5V)
 - PWMA/B: PWM port
 - AIN/BIN/AOUT/BOUT: Used to control state of motor
 - AO1/AO2/BO1/BO2: Motor output
 - STBY: Control on/off of two motors

## Notice
1. There are 6 different MCPWM channels on ESP32. So you can control at most 6 different motors at the same time.
2. Since two IN pins alone can stop and brake the motor, STBY function is ignored. **You should always connect STBY pin to VCC.**
