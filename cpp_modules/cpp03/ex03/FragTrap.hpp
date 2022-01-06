#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
  void  attack(std::string const & target);
  void  highFivesGuys(void);

  FragTrap(void);
  FragTrap(std::string name);
  ~FragTrap();
  FragTrap(const FragTrap & flagtrap);
  FragTrap&  operator=(const FragTrap & flagtrap);
};

#endif