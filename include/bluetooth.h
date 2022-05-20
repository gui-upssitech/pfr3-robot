#ifndef H_BT
#define H_BT

// -------------

#define BLUETOOTH_SERIAL    Serial1
#define BLUETOOTH_BAUDRATE  115200

#define CMD_LENGTH          12

// -------------

#define joy_map(x) (((x) * 2) - 100)

// -------------

class BTHandler 
{
    private:
    HardwareSerial& bt;

    public:
    BTHandler(HardwareSerial& serial_port, int baudrate);
    void parse(int *joy_x, int *joy_y, int *speed);
    void send(int lidar_x, int lidar_y, int robot_x, int robot_y);
};

// -------------

#endif