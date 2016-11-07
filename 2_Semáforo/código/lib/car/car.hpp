class Car{
    public:
        Car(
            unsigned char led_green_pin,
            unsigned char led_yellow_pin,
            unsigned char led_red_pin,
        );
        void active();
        void deactive();

    private:
        unsigned char led_green;
        unsigned char led_yellow;
        unsigned char led_red;
        void alert();
};
