#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria*   inventory[4];
    
public:
    std::string const & getName() const;
    void    equip(AMateria* materia);
    void    unequip(int idx);
    void    use(int idx, ICharacter& target);

    void    print_inventory() const;

    Character();
    Character(const std::string name);
    ~Character();
    Character(const Character &character);
    Character&  operator=(Character character);
};

#endif