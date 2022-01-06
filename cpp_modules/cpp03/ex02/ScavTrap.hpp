#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
  void  attack(std::string const & target);
  void  guardGate(void);

  ScavTrap(void);
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap & scavtrap);
  ScavTrap& operator=(const ScavTrap & scavtrap);
};

#endif