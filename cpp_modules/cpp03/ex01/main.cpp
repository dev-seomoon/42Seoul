#include "ScavTrap.hpp"

int   main(void)
{
  std::string name1 = "You";
  std::string name2 = "Enemy";
  ScavTrap  mine(name1);
  ScavTrap  enemy(name2);
  std::cout << std::endl;

  mine.guardGate();
  enemy.guardGate();
  std::cout << std::endl;

  mine.attack(name2);
  enemy.takeDamage(mine.getAttackDamage());
  mine.printStatus();
  enemy.printStatus();
  std::cout << std::endl;

  enemy.beRepaired(3);
  enemy.attack(name1);
  mine.takeDamage(enemy.getAttackDamage());
  mine.printStatus();
  enemy.printStatus();
  std::cout << std::endl;
  
  enemy.attack(name1);
  mine.takeDamage(enemy.getAttackDamage());
  mine.beRepaired(1);
  mine.printStatus();
  enemy.printStatus();
  std::cout << std::endl;

  mine.attack(name2);
  enemy.takeDamage(mine.getAttackDamage());
  mine.printStatus();
  enemy.printStatus();
  std::cout << std::endl;

  return (0);
}