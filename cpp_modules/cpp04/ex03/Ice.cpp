#include "Ice.hpp"

AMateria*   Ice::clone() const
{
    return (new Ice());
}

void        Ice::use(ICharacter& target)
{
    AMateria::use(target);
}

Ice::Ice(): AMateria("ice")
{
    std::cout << "Ice constructor called. " << std::endl;
}

Ice::Ice(const Ice& ice): AMateria(ice)
{
    std::cout << "Ice copy constructor called. " << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice desructor called. " << std::endl;
}

Ice&        Ice::operator=(const Ice& ice)
{
    if (this != &ice) {
        type = ice.getType();
    }
    return (*this);
}

