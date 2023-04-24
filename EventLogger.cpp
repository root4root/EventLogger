/*
 *
 * This is an example how to use Power-down mode on Atmega328p MCU
 *
 * Measured values on root4root's "Event Logger" device:
 *     3.3 - 3.5mA in default mode
 *     ~275uA in PWR_DOWN, including ~100uA for DS3231 RTC
 *
 * Author: root4root (at gmail dot com)
 *
 * 06-02-2023
 *
 * */

#include "Arduino.h"
#include <avr/sleep.h>

void gosleep(void);
void wakeup(void);

void setup() {
    pinMode(3, INPUT_PULLUP); //D3 input with built-in pull-up resistor (20K-50K)
}

void loop() {
    delay(10000);
    gosleep();
}

void gosleep()
{
    attachInterrupt(1, wakeup, LOW); //Interrupt to D3
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_cpu();
}

void wakeup(){
    sleep_disable();
    detachInterrupt(1);
}
