/**
 * @file
 * @brief Tower of Hanoi Implementation
 */

#include <iostream>

/**
 * @brief Moves the disks
 * @param fp From pole
 * @param tp To pole
 */
void moveDisk(char fp, char tp) {
  std::cout << "moving disk from " << fp << " to " << tp << std::endl;
}

/**
 * @brief Recursive function to move tower
 * @param height Height of the tower
 * @param fromPole Source pole
 * @param toPole Destination pole
 * @param withPole Auxiliary pole
 */
void moveTower(int height, char fromPole, char toPole, char withPole) {
  if (height >= 1) {
    moveTower(height - 1, fromPole, withPole, toPole);
    moveDisk(fromPole, toPole);
    moveTower(height - 1, withPole, toPole, fromPole);
  }
}

int main() {
  int height = 3;
  moveTower(height, 'A', 'B', 'C');
  return 0;
}
