#include "Cure.hpp"

AMateria*   Cure::clone() const
{
    return (new Cure());
}

void        Cure::use(ICharacter& target)
{
    AMateria::use(target);
}

Cure::Cure(): AMateria("cure")
{
    std::cout << "Cure constructor called. " << std::endl;
}

Cure::Cure(const Cure& cure): AMateria(cure)
{
    std::cout << "Cure copy constructor called. " << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called. " << std::endl;
}

Cure&   Cure::operator=(const Cure& cure)
{
    if (this != &cure) {
        type = cure.getType();
    }
    return (*this);
}