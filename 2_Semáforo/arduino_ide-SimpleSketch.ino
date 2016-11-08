class Car{
    public:
        Car(unsigned char led_green_pin=2, unsigned char led_yellow_pin=3, unsigned char led_red_pin=4);
        void active();
        void deactive();

    private:
        unsigned char led_green;
        unsigned char led_yellow;
        unsigned char led_red;
        void alert();
};


class Pedestrian{
    public:
        Pedestrian(
            unsigned char led_green_pin=10,
            unsigned char led_red_pin=11,
            unsigned char button_pin=12,
            unsigned char buzzer_pin=13
        );
        bool onPushButton();
        void active(unsigned long timer=10000);

    private:
        unsigned char led_green;
        unsigned char led_red;
        unsigned char button;
        unsigned char buzzer;
        void alert();
        void deactive();
};


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

