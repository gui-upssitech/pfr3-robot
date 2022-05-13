#ifndef H_BT
#define H_BT

// -------------

#define BT Serial1
#define CMD_LENGTH 12

// -------------

class BTHandler {

    public:
    BTHandler();
    void parse(int *joy_x, int *joy_y, int *speed);

};

// -------------

#endif