#include "Base.hpp"

Base::~Base() {}

Base*   generate(void)
{
    int id;

    std::srand(std::time(NULL));
    id = rand() % 3;

    switch (id) {
        case 0:
            return (new A());
        case 1: 
            return (new B());
        case 2:
            return (new C());
        default:
            return (NULL);
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    Base    base;

    try {
        base = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        base = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        base = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    } catch (const std::exception& e) {}
}