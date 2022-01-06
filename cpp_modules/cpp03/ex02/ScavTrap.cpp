#include "ScavTrap.hpp"

void  ScavTrap::attack(std::string const & target)
{
  if (_energy_points <= 0) {
    std::cout << _name << " don't have enough energy to attack!" << std::endl;
    return;
  }
  std::cout << "Armed ScavTrap <" << _name << "> attacks <" << target << ">, causing <" << _attack_damage << "> points of damage!" << std::endl;
  _energy_points--;
}

void  ScavTrap::guardGate(void)
{
  std::cout << "ScavTrap <" << _name 
    << "> has enterred in Gate keeper mode!" << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
  std::cout << "Default ScavTrap created. " << std::endl;

  _hitpoints = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
  std::cout << "ScavTrap <" << name << "> joined!" << std::endl;

  _hitpoints = 100;
  _energy_points = 50;
  _attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap <" << _name << "> exited." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & scavtrap)
{
  *this = scavtrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap & scavtrap){
  if (this != &scavtrap) {
    _name = scavtrap.getName();
    _hitpoints = scavtrap.getHitpoints();
    _energy_points = scavtrap.getEnergyPoints();
    _attack_damage = scavtrap.getAttackDamage();
  }
  return (*this);
}