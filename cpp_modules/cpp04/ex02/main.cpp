#include "Cat.hpp"
#include "Dog.hpp"

void    simple_test(void)
{
    const Animal    *j = new Dog();
    std::cout << std::endl;
    const Animal    *i = new Cat();
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;
}
int     main(void)
{
    simple_test();
}