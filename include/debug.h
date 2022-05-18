#ifndef H_DEBUG
#define H_DEBUG

#define DEBUG 1

#if DEBUG == 1
#define debug_init() Serial.begin(9600);
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug_init()
#define debug(x)
#define debugln(x)
#endif

#endif