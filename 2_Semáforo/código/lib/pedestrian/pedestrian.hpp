class Pedestrian{
    public:
        Pedestrian(
            unsigned char led_green_pin,
            unsigned char led_red_pin,
            unsigned char button_pin,
            unsigned char buzzer_pin
        );
        bool onPushButton();
        void active(unsigned int time);

    private:
        unsigned char led_green;
        unsigned char led_red;
        unsigned char button;
        unsigned char buzzer;
        void alert();
        void deactive();
};
