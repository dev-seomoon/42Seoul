#include "Dog.hpp"

void    Dog::makeSound(void) const
{
    std::cout << "멍멍!" << std::endl;
}

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor called. " << std::endl;
}

Dog::Dog(const Dog& dog)
{
    *this = dog;
    std::cout << "Dog copy constructor called. " << std::endl;
}

Dog&    Dog::operator=(const Dog& dog)
{
    if (this != &dog) {
        type = dog.getType();
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called. " << std::endl;
}