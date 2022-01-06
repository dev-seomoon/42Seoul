#include "AMateria.hpp"

std::string const &     AMateria::getType() const
{
    return type;
}

void                    AMateria::use(ICharacter& target)
{
    if (type == "ice") {
        std::cout << "* shoots an ice bolt at " 
        << target.getName() << " *" << std::endl;
    }
    else if (type == "cure") {
        std::cout << "* heals " 
        << target.getName() << "'s wounds *" << std::endl;
    }
}

AMateria::AMateria()
{
    std::cout << "AMateria constructor called. " << std::endl;
}

AMateria::AMateria(std::string const & type): type(type)
{
    std::cout << "AMateria constructor called. " << std::endl;
}

AMateria::AMateria(const AMateria& materia)
{
    std::cout << "AMateria copy constructor called. " << std::endl;
    *this = materia;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called. " << std::endl;
}

AMateria&   AMateria::operator=(const AMateria& materia)
{
    if (this != &materia) {
        type = materia.getType();
    }
    return (*this);
}