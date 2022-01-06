#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    void    makeSound(void) const;

    std::string     getType(void) const;
    void            printType(void) const;

    WrongAnimal();
    WrongAnimal(const WrongAnimal& animal);
    WrongAnimal&         operator=(const WrongAnimal& animal);
    ~WrongAnimal();
};

#endif