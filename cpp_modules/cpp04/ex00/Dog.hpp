#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
    void    makeSound(void) const;

    Dog();
    Dog(const Dog& dog);
    Dog&    operator=(const Dog& dog);
    ~Dog();
};

#endif