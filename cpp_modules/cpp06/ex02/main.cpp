#include "Base.hpp"

int     main()
{
    Base    *ptr = generate();
    Base    &ref = *ptr;

    std::cout << "ptr: ";
    identify(ptr);
    std::cout << "ref: ";
    identify(ref);
    delete ptr;
    return (0);
}