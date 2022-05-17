// #include "lidar.h"
                       
                        
// Lidar::Lidar(HardwareSerial& serial_port, int baudrate, int motor_pin) {
//   // bind the RPLIDAR driver to the arduino hardware serial
//   serial_port.begin(baudrate);
//   lidar.begin(serial_port);

//   // set pin modes

//   this->motor_pin = motor_pin;
//   pinMode(motor_pin, OUTPUT);
//   analogWrite(motor_pin, 255);
// }

// void Lidar::parse(int *lidar_x, int *lidar_y) {
//   if (IS_OK(lidar.waitPoint())) {
//     float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
//     float angle    = lidar.getCurrentPoint().angle; //angle value in degree
    
//     //perform data processing here...
//     if(distance > 0.0)
//     {
//       *lidar_x = (int) (distance * cos(angle * PI / 180.0) / 10.0);
//       *lidar_y = (int) (distance * sin(angle * PI / 180.0) / 10.0);
//     }
    
//   } else {
//     analogWrite(motor_pin, 0); //stop the rplidar motor
    
//     // try to detect RPLIDAR... 
//     rplidar_response_device_info_t info;
//     if (IS_OK(lidar.getDeviceInfo(info, 100))) {
//        // detected...
//        lidar.startScan();
       
//        // start motor rotating at max allowed speed
//        analogWrite(motor_pin, 255);
//     }
//   }
// }