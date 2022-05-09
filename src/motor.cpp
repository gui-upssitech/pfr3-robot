#include <Arduino.h>
#include <Servo.h>
#include "motor.h"

Servo motorG, motorD;

void init_motors() {
  motorD.attach(PIN_SERVO_G);
  motorG.attach(PIN_SERVO_D);
}

/**
 * @brief Contrôle les deux jeux de moteurs du robot en fonction d'une direction et d'une vitesse
 * 
 * @param dir Détermine la translation / rotation du robot
 * @param val Détermine la vitesse du robot (en %)
 */
void commander(int dir, int val) {
  int dirG = (dir == FWD || dir == RGT) ? 1 : -1;
  int dirD = (dir == FWD || dir == LFT) ? 1 : -1;

  commandAmpl(motorG, dirG, val);
  commandAmpl(motorD, dirD, val);
}

/**
 * @brief commande en vitesse un jeu de moteurs dans les deux sens de rotation
 * 
 * @param dir - détermine le sens de rotation du moteur
 * @param val - vitesse de rotation du moteur (en %)
 */
void commandAmpl(Servo m, int dir, int val) {
  int commandVal = ZERO_MOTEUR + dir * (65 * val / 100);
  m.write(commandVal);
}