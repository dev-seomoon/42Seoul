#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

# define FRAG_HP 100
# define SCAV_EP 50
# define FRAG_AD 30

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
  std::string _name;

public:
  void  attack(std::string const & target);
  void  whoAmI(void);

  std::string   getName(void) const;

  DiamondTrap(void);
  DiamondTrap(std::string name);
  ~DiamondTrap();
  DiamondTrap(const DiamondTrap& diamondtrap);
  DiamondTrap&  operator=(const DiamondTrap& diamondtrap);
};

#endif