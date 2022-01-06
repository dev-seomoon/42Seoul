#include "Cat.hpp"

void    Cat::makeSound(void) const
{
    std::cout << "냥냥!" << std::endl;
}

Cat::Cat()
{
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
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called. " << std::endl;
}