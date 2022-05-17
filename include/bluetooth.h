#ifndef H_BT
#define H_BT

// -------------

#define CMD_LENGTH 12

// -------------

class BTHandler {

    private:
    HardwareSerial& bt;

    public:
    BTHandler(HardwareSerial& serial_port, int baudrate);
    void parse(int *joy_x, int *joy_y, int *speed);
    void send(int lidar_x, int lidar_y, int encorder_left, int encoder_right);

};

// -------------

#endif