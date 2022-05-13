#include <Arduino.h>
#include <Servo.h>
#include "motor.h"
#include "debug.h"

/* Public functions */

/**
 * @brief Construct a new Motor Handler object
 * 
 * @param motor_g_pin pin for left motor
 * @param motor_d_pin pin for right motor
 */
MotorHandler::MotorHandler(int motor_g_pin, int motor_d_pin) {
  this->motor_g.attach(motor_g_pin);
  this->motor_d.attach(motor_d_pin);
  debug_init();
}

/**
 * @brief Contrôle les deux jeux de moteurs du robot en fonction d'une direction et d'une vitesse
 * 
 * @param dir Détermine la translation / rotation du robot
 * @param val Détermine la vitesse du robot (en %)
 */
void MotorHandler::command(int x, int y, int speed) {
  diffSteer(x, y, speed);

  commandAmpl(motor_g, left);
  commandAmpl(motor_d, right);
}

/**
 * @brief commande en vitesse un jeu de moteurs dans les deux sens de rotation
 * 
 * @param dir détermine le sens de rotation du moteur
 * @param val vitesse de rotation du moteur (en %)
 */
void MotorHandler::commandAmpl(Servo m, Command cmd) {
  int commandVal = ZERO_MOTEUR + cmd.dir * (65 * cmd.speed / 100);
  m.write(commandVal);
}

/**
 * @brief Calculates the motor commands based on user input
 * 
 * @param x x position of the joystick
 * @param y y position of the joystick
 * @param speed desired speed of the robot
 */
void MotorHandler::diffSteer(int x, int y, int speed) {
  // Cas repos
  if(abs(y) < DIFF_GAP && abs(x) < DIFF_GAP) {
    left.speed = right.speed = 0;
    left.dir = right.dir = 1;
    return;
  }

  // Cas rotation
  if(abs(y) < DIFF_GAP) {
    left.speed = right.speed = speed;
    left.dir = (x < 0) ? -1 : 1;
    right.dir = -1 * left.dir;
    return;
  }

  left.dir = right.dir = (y < 0) ? 1 : -1;
  left.speed = calc_speed(speed, x, (x > 0));
  right.speed = calc_speed(speed, x, (x < 0));
}

int MotorHandler::calc_speed(int speed, int x, int condition) {
  return condition ? speed : speed * (100 - abs(x)) / 100;
}