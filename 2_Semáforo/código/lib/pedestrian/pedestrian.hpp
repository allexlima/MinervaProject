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
