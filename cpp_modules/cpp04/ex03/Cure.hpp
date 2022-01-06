#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

    Cure();
    Cure(const Cure& cure);
    virtual ~Cure();
    Cure&   operator=(const Cure& cure);
};


#endif