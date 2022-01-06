#include "Cat.hpp"

void    Cat::makeSound(void) const
{
    std::cout << "냥냥!" << std::endl;
}

Brain*   Cat::getBrain(void) const
{
    return brain;
}

Cat::Cat()
{
    Brain *newBrain = new Brain();
    brain = newBrain;
    type = "Cat";
    std::cout << "Cat constructor called. " << std::endl;
}

Cat::Cat(const Cat& cat)
{
    *this = cat;
    std::cout << "Cat copy constructor called. " << std::endl;
}

Cat&    Cat::operator=(const Cat& cat)
{
    if (this != &cat) {
        type = cat.getType();
        brain = cat.getBrain();
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called. " << std::endl;
}