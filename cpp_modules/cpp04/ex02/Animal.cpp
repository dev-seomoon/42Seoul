#include "Animal.hpp"

void            Animal::makeSound(void) const
{
    std::cout << "animaaaaal" << std::endl;
}

std::string     Animal::getType(void) const
{
    return (type);
}

void            Animal::printType(void) const
{
    std::cout << "Type: " << type << std::endl;
}

Animal::Animal(): type("Animal")
{
    std::cout << "Animal constructor called. " << std::endl;
}

Animal::Animal(const Animal& animal)
{
    *this = animal;
    std::cout << "Animal copy constructor called. " << std::endl;
}

Animal&         Animal::operator=(const Animal& animal)
{
    if (this != &animal) {
        type = animal.getType();
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called. " << std::endl;
}
