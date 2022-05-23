#include <Arduino.h>
#include "motor.h"

Command left, right;

/* Public functions */

void init_motor()
{

}

/**
 * @brief Contrôle les deux jeux de moteurs du robot en fonction d'une direction et d'une vitesse
 * 
 * @param dir Détermine la translation / rotation du robot
 * @param val Détermine la vitesse du robot (en %)
 */
void command_motor(int x, int y, int speed) 
{
  diff_steer_motor(x, y, speed);

  write_left_servo(get_ampl_motor(left));
  write_right_servo(get_ampl_motor(right));
}

/**
 * @brief commande en vitesse un jeu de moteurs dans les deux sens de rotation
 * 
 * @param dir détermine le sens de rotation du moteur
 * @param val vitesse de rotation du moteur (en %)
 */
int get_ampl_motor(Command cmd) 
{
  return ZERO_MOTEUR + cmd.dir * (65 * cmd.speed / 100.0);
}

/**
 * @brief Calculates the motor commands based on user input
 * 
 * @param x x position of the joystick
 * @param y y position of the joystick
 * @param speed desired speed of the robot
 */
void diff_steer_motor(int x, int y, int speed) 
{
  // Cas repos
  if(abs(y) < DIFF_GAP && abs(x) < DIFF_GAP) 
  {
    left.speed = right.speed = 0;
    left.dir = right.dir = 1;
    return;
  }

  // Cas rotation
  if(abs(y) < DIFF_GAP) 
  {
    left.speed = right.speed = speed;
    left.dir = (x < 0) ? -1 : 1;
    right.dir = -1 * left.dir;
    return;
  }

  left.dir = right.dir = (y < 0) ? 1 : -1;
  left.speed = calc_speed_motor(speed, x, (x > 0));
  right.speed = calc_speed_motor(speed, x, (x < 0));
}

int calc_speed_motor(int speed, int x, int condition) 
{
  return condition ? speed : speed * (100 - abs(x)) / 100.0;
}