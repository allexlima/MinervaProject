#include "Arduino.h"
#include "pedestrian.hpp"

Pedestrian::Pedestrian(unsigned char led_green_pin, unsigned char led_red_pin, unsigned char button_pin, unsigned char buzzer_pin){
    led_green = led_green_pin;
    led_red = led_red_pin;
    button = button_pin;
    buzzer = buzzer_pin;
    pinMode(led_green, OUTPUT);
    pinMode(led_red, OUTPUT);
    pinMode(button, INPUT);
    pinMode(buzzer, OUTPUT);
    digitalWrite(led_red, HIGH);
}

bool Pedestrian::onPushButton(){
    return (bool) digitalRead(button);
}

void Pedestrian::alert(){
    for(unsigned short i = 0; i < 10; i++){
        digitalWrite(led_green, LOW);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(led_green, HIGH);
        digitalWrite(buzzer, LOW);
        delay(500);
    }
}

void Pedestrian::active(unsigned long timer){
    delay(3000);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(timer);
    deactive();
}

void Pedestrian::deactive(){
    alert();
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    delay(2000);
}
