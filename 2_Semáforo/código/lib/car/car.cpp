#include "Arduino.h"
#include "car.hpp"

Car::Car(unsigned char led_green_pin, unsigned char led_yellow_pin, unsigned char led_red_pin){
    led_green = led_green_pin;
    led_yellow = led_yellow_pin;
    led_red = led_red_pin;
    pinMode(led_green, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_red, OUTPUT);
    digitalWrite(led_green, HIGH);
}

void Car::active(){
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);
}

void Car::alert(){
    for(unsigned short i = 0; i < 10; i++){
        digitalWrite(led_green, LOW);
        delay(500);
        digitalWrite(led_green, HIGH);
        delay(500);
    }
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);
    delay(5000);
    digitalWrite(led_yellow, LOW);
}

void Car::deactive(){
    alert();
    digitalWrite(led_red, HIGH);
}
