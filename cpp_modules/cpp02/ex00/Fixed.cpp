#include "Fixed.hpp"

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&   Fixed::operator=(const Fixed& fixed)
{
	// this: 객체 자신을 가리키는 포인터
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed) // 자기 자신을 대입하는 경우 X
		value = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw << flacBits;
}
