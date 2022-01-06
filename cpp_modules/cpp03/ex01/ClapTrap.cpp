#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: _name("unknown"), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "Default ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
  std::cout << "ClapTrap <" << name << "> joined!" << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap <" << _name << "> exited." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & claptrap)
{
  *this = claptrap;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& claptrap)
{
  if (this != &claptrap) {
    _name = claptrap.getName();
    _hitpoints = claptrap.getHitpoints();
    _energy_points = claptrap.getEnergyPoints();
    _attack_damage = claptrap.getAttackDamage();
  }
  return (*this);
}

int     ClapTrap::getHitpoints(void) const
{
  return _hitpoints;
}

int     ClapTrap::getEnergyPoints(void) const
{
  return _energy_points;
}

int     ClapTrap::getAttackDamage(void) const
{
  return _attack_damage;
}

std::string   ClapTrap::getName(void) const
{
  return _name;
}

void    ClapTrap::setHitpoints(int hitpoints)
{
  _hitpoints = hitpoints;
}

void    ClapTrap::setEnergyPoints(int energy_points)
{
  _energy_points = energy_points;
}

void    ClapTrap::setAttackDamage(int attack_damage)
{
  _attack_damage = attack_damage;
}

void    ClapTrap::setName(std::string name)
{
  _name = name;
}

void    ClapTrap::attack(std::string const & target)
{
  if (_energy_points <= 0) {
    std::cout << _name << " don't have enough energy to attack!" << std::endl;
    return;
  }
  std::cout << "Noisy ClapTrap <" << _name << "> attacks <" << target << ">, causing <" << _attack_damage << "> points of damage!" << std::endl;
  _energy_points--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
  int damage;

  if (_hitpoints - (int)amount < 0) {
    damage = _hitpoints;
    _hitpoints = 0;
  } else {
    damage = amount;
    _hitpoints -= amount;
  }
  std::cout << "<" << getName() << "> take <" << damage << "> points of damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
  std::cout << "<" << getName() << "> is repaired, recovered <" << amount << "> points!" << std::endl;
  _hitpoints += amount;
}

void    ClapTrap::printStatus(void)
{
  std::cout << "Status: HP " << std::setw(3) << _hitpoints << " | EP "
    << std::setw(3) << _energy_points << " | AD " << std::setw(3) << _attack_damage << " (" << _name << ")" << std::endl;
}