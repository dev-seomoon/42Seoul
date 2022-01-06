#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
    virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
    
    Ice();
    Ice(const Ice& ice);
    virtual ~Ice();
    Ice&    operator=(const Ice& ice);
};

#endif