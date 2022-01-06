#include "WrongCat.hpp"

void    WrongCat::makeSound(void) const
{
    std::cout << "냥냥!" << std::endl;
}

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called. " << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
    *this = wrongCat;
}

WrongCat&    WrongCat::operator=(const WrongCat& wrongCat)
{
    if (this != &wrongCat) {
        type = wrongCat.getType();
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called. " << std::endl;
}