#include "Arduino.h"
#include <pedestrian.hpp>

Pedestrian::Pedestrian(unsigned char led_green_pin = 10, unsigned char led_red_pin = 11, unsigned char button_pin = 12, unsigned char buzzer_pin = 13){
    led_green = pinMode(led_green_pin, OUTPUT);
    led_red = pinMode(led_red_pin, OUTPUT);
    button = pinMode(button_pin, INPUT);
    buzzer = pinMode(buzzer_pin, OUTPUT);
    digitalWrite(led_red, HIGH);
}

bool Pedestrian::onPushButton(){
    return (bool) digitalRead(button);
}

void pedestrian::alert(){
    for(unsigned short i = 0; i < 10; i++){
        digitalWrite(led_green, LOW);
        delay(300);
        digitalWrite(led_green, HIGH);
        delay(300);
    }
}

//default time: 40s
void Pedestrian::active(unsigned long timer = 40000){
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    delay(timer);
    deactive();
}

void Pedestrian::deactive(){
    alert();
    digitalWrite(buzzer, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
}
