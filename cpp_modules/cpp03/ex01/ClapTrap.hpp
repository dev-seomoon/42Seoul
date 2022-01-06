#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <iomanip>

class ClapTrap
{
protected:
  std::string   _name;
  int   _hitpoints; //HP (체력)
  int   _energy_points; //공격 가능횟수?
  int   _attack_damage; //공격 능력

public:
  void    attack(std::string const & target);
  void    takeDamage(unsigned int amount);
  void    beRepaired(unsigned int amount);

  void    printStatus(void);

  ClapTrap(void);
  ClapTrap(std::string name);
  ~ClapTrap();
  ClapTrap(const ClapTrap & claptrap);
  ClapTrap&   operator=(const ClapTrap & claptrap);

  int     getHitpoints(void) const;
  int     getEnergyPoints(void) const;
  int     getAttackDamage(void) const;
  std::string   getName(void) const;
  void    setHitpoints(int hitpoints);
  void    setEnergyPoints(int energy_points);
  void    setAttackDamage(int attack_damage);
  void    setName(std::string name);
};

#endif