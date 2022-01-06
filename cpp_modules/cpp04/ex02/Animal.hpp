#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
    std::string type;

public:
    virtual void    makeSound(void) const = 0; // 순수 가상 함수로 변경, 추상클래스화

    std::string     getType(void) const;
    void            printType(void) const;

    Animal();
    Animal(const Animal& animal);
    Animal&         operator=(const Animal& animal);
    virtual ~Animal();
};

#endif