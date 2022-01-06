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
    Brain   *newBrain = new Brain();
    brain = newBrain;
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
        brain = dog.getBrain();
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called. " << std::endl;
}