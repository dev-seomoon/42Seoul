#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
    std::string type;

public:
    virtual void    makeSound(void) const;

    std::string     getType(void) const;

    Animal();
    Animal(const Animal& animal);
    Animal&         operator=(const Animal& animal);
    virtual ~Animal();
};

#endif