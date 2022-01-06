#include "FragTrap.hpp"

int   main(void)
{
  std::string name1 = "You";
  std::string name2 = "Enemy";
  FragTrap  mine(name1);
  FragTrap  enemy(name2);
  std::cout << std::endl;

  mine.highFivesGuys();
  enemy.highFivesGuys();
  std::cout << std::endl;

  mine.setAttackDamage(20);
  enemy.setAttackDamage(10);
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