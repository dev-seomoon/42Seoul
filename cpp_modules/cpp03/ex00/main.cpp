#include "ClapTrap.hpp"

int   main(void)
{
  std::string name1 = "You";
  std::string name2 = "Enemy";
  ClapTrap  mine(name1);
  ClapTrap  enemy(name2);
  std::cout << std::endl;

  mine.setAttackDamage(8);
  enemy.setAttackDamage(5);
  mine.printStatus();
  enemy.printStatus();
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