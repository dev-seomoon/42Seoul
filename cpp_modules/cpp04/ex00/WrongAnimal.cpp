#include "WrongAnimal.hpp"

void            WrongAnimal::makeSound(void) const
{
    std::cout << "animaaaaal" << std::endl;
}

std::string     WrongAnimal::getType(void) const
{
    return (type);
}

void            WrongAnimal::printType(void) const
{
    std::cout << "Type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called. " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Wronganimal)
{
    *this = Wronganimal;
}

WrongAnimal&         WrongAnimal::operator=(const WrongAnimal& Wronganimal)
{
    if (this != &Wronganimal) {
        type = Wronganimal.getType();
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called. " << std::endl;
}
