#include "Brain.hpp"

std::string     Brain::getIdea(int index)
{
    if (index < 0 || index >= 100)
        throw std::out_of_range("Index of ideas: out of range. ");
    return ideas[index];
}

void            Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
        throw std::out_of_range("Index of ideas: out of range. ");
    ideas[index] = idea;
}

Brain::Brain()
{
    std::cout << "Brain constructor called. " << std::endl;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain&         Brain::operator=(const Brain& brain)
{
    if (this != &brain) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = brain.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called. " << std::endl;
}