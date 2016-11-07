#include "Arduino.h"
#include <car.hpp>

Car::Car(unsigned char led_green_pin = 2, unsigned char led_yellow_pin = 3, unsigned char led_red_pin = 4){
    led_green = pinMode(led_green_pin, OUTPUT);
    led_yellow = pinMode(led_yellow_pin, OUTPUT);
    led_red = pinMode(led_red_pin, OUTPUT);
}

void Car:active(){
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);
}

void Car:alert(){
    for(unsigned short i = 0; i < 10; i++){
        digitalWrite(led_green, LOW);
        delay(300);
        digitalWrite(led_green, HIGH);
        delay(300);
    }
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);
    delay(10000);
    digitalWrite(led_yellow, LOW);
}

void Car:deactive(){
    alert();
    digitalWrite(led_red, HIGH);
}
