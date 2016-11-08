#include "Arduino.h"
#include <car.hpp>
#include <pedestrian.hpp>

Car car;
Pedestrian pedestrian;

void setup(){
}

void loop(){
    car.active();
    if(pedestrian.onPushButton()){
        delay(5000);
        car.deactive();
        pedestrian.active();
    }
}
