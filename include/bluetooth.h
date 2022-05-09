#ifndef H_BT
#define H_BT

// -------------

#define BT Serial1
#define MAX_MESSAGE_LENGTH 50

// -------------

void init_bt();
void parseSerial(int *dir, int *val);

// -------------

#endif