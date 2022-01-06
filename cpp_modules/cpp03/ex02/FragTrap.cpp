#include "FragTrap.hpp"

void  FragTrap::attack(std::string const & target)
{
  if (_energy_points <= 0) {
    std::cout << _name << " don't have enough energy to attack!" << std::endl;
    return;
  }
  std::cout << "Battle tank FragTrap <" << _name << "> attacks <" << target << ">, causing <" << _attack_damage << "> points of damage!" << std::endl;
  _energy_points--;
}

void  FragTrap::highFivesGuys(void)
{
  std::cout << "FragTrap <" << _name 
    << "> said \"Let's high-five, guys!\"" << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap()
{
  std::cout << "Default FragTrap created." << std::endl;

  _hitpoints = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
  std::cout << "FragTrap <" << name << "> joined!" << std::endl;

  _hitpoints = 100;
  _energy_points = 100;
  _attack_damage = 30;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap <" << _name << "> exited." << std::endl;
}

FragTrap::FragTrap(const FragTrap & flagtrap)
{
  *this = flagtrap;
}

FragTrap&  FragTrap::operator=(const FragTrap & flagtrap)
{
  if (this != &flagtrap) {
    _name = flagtrap.getName();
    _hitpoints = flagtrap.getHitpoints();
    _energy_points = flagtrap.getEnergyPoints();
    _attack_damage = flagtrap.getAttackDamage();
  }
  return (*this);
}