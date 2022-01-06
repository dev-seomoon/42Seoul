#include "Dog.hpp"

void    Dog::makeSound(void) const
{
    std::cout << "멍멍!" << std::endl;
}

Brain*  Dog::getBrain(void) const
{
    return brain;
}

Dog::Dog()
{
    std::cout << "Dog constructor called. " << std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::Dog(const Dog& dog)
{
    std::cout << "Dog copy constructor called. " << std::endl;
    brain = new Brain();
    *this = dog;
}

Dog&    Dog::operator=(const Dog& dog)
{
    if (this != &dog) {
        type = dog.getType();
        *brain = *(dog.getBrain());
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called. " << std::endl;
    delete brain;
}