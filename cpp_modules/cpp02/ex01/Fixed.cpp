#include "Fixed.hpp"

std::ostream&    operator<<(std::ostream& os, const Fixed& fixed)
{
	// print fixed as float
	os << fixed.toFloat();
	return os;
}

Fixed&   Fixed::operator=(const Fixed& fixed)
{
	// this: 객체 자신을 가리키는 포인터
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed) // 자기 자신을 대입하는 경우 X
		value = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//int to fixed
Fixed::Fixed(int const raw): value(raw << flacBits)
{
	std::cout << "Int constructor called" << std::endl;
}

//float to fixed
Fixed::Fixed(float const raw)
	: value(static_cast<int>(roundf(raw * (1 << flacBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

//fixed to int
int		Fixed::toInt(void) const
{
	return value >> Fixed::flacBits;
}

//fixed to float
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << Fixed::flacBits)); 
}

int		Fixed::getRawBits(void) const
{
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}