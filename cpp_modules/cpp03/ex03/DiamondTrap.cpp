#include "DiamondTrap.hpp"

void  DiamondTrap::attack(std::string const & target)
{
  ScavTrap::attack(target);
}

void  DiamondTrap::whoAmI(void)
{
  std::cout << "Guess who I am? I'm <" << _name << "> and ClapTrap's name is <" << ClapTrap::_name << ">!" << std::endl;
}

std::string   DiamondTrap::getName(void) const
{
  return (_name);
}

DiamondTrap::DiamondTrap(void)
{
  std::cout << "Default DiamondTrap created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
  std::cout << "DiamondTrap <" << name << "> joined!" << std::endl;

  _name = name;
  ClapTrap::_name = _name + "_clap_name";
  _hitpoints = FRAG_HP;
  _energy_points = SCAV_EP;
  _attack_damage = FRAG_AD;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap <" << _name << "> exited." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
{
  *this = diamondtrap;
}

DiamondTrap&  DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
  if (this != &diamondtrap) {
    _name = diamondtrap.getName();
    _hitpoints = diamondtrap.getHitpoints();
    _energy_points = diamondtrap.getEnergyPoints();
    _attack_damage = diamondtrap.getAttackDamage();
  }
  return (*this);
}