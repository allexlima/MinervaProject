#include "Arduino.h"
#include <pedestrian.hpp>

Pedestrian::Pedestrian(unsigned char led_green_pin = 10, unsigned char led_red_pin = 11, unsigned char button_pin = 12, unsigned char buzzer_pin = 13){
    led_green = pinMode(led_green_pin, OUTPUT);
    led_red = pinMode(led_red_pin, OUTPUT);
    button = pinMode(button_pin, INPUT);
    buzzer = pinMode(buzzer_pin, OUTPUT);

    button_state = false;
}

bool Pedestrian::onPushButton(){
    button_state = digitalRead(button);
    return button_state;
}

void Pedestrian::active(unsigned int time){

}

void Pedestrian::deactive(){

}
