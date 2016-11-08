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
