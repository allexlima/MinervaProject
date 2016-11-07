#include "Arduino.h"
#include <car.hpp>
#include <pedestrian.hpp>

///car car();
Pedestrian pedestrian();

void setup(){
}

void loop(){
    //car.active();
    if(pedestrian.onPushButton())
        //car.deactive();
        //pedestrian.active();
        //car.active();
}
