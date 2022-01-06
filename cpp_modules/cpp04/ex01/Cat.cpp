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
    std::cout << "Cat constructor called. " << std::endl;
    brain = new Brain();
    type = "Cat";
}

Cat::Cat(const Cat& cat)
{
    std::cout << "Cat copy constructor called. " << std::endl;
    brain = new Brain();
    *this = cat;
}

Cat&    Cat::operator=(const Cat& cat)
{
    if (this != &cat) {
        type = cat.getType();
        *brain = *(cat.getBrain());
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called. " << std::endl;
    delete brain;
}