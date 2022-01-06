#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int     main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    
    // wrong case

    const WrongAnimal* animal = new WrongAnimal();
    const WrongAnimal*  cat = new WrongCat();

    cat->makeSound();
    animal->makeSound();

    delete animal;
    delete cat;

    return (0);
}