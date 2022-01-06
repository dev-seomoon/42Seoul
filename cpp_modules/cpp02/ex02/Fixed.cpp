#include "Fixed.hpp"

std::ostream&    operator<<(std::ostream& os, const Fixed& fixed)
{
	// print fixed as float
	os << fixed.toFloat();
	return os;
}

Fixed&   Fixed::Fixed::operator=(const Fixed& fixed)
{
	// this: 객체 자신을 가리키는 포인터
	if (this != &fixed) // 자기 자신을 대입하는 경우 X
		value = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(void): value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

//int to fixed
Fixed::Fixed(int const raw): value(raw << flacBits)
{
}

//float to fixed
Fixed::Fixed(float const raw)
	: value(static_cast<int>(roundf(raw * (1 << flacBits))))
{
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

// ex02 operators overloading
bool    Fixed::operator>(const Fixed& later)
{
    return (value > later.getRawBits());
}

bool    Fixed::operator<(const Fixed& later)
{
    return (value < later.getRawBits());
}

bool    Fixed::operator>=(const Fixed& later)
{
    return (value >= later.getRawBits());
}

bool    Fixed::operator<=(const Fixed& later)
{
    return (value <= later.getRawBits());
}

bool    Fixed::operator==(const Fixed& later)
{
    return (value == later.getRawBits());
}

bool    Fixed::operator!=(const Fixed& later)
{
    return (value != later.getRawBits());
}


Fixed  Fixed::operator+(const Fixed& later)
{
    Fixed   result(this->toFloat() + later.toFloat());

    return result;
}

Fixed  Fixed::operator-(const Fixed& later)
{
    Fixed   result(this->toFloat() - later.toFloat());

    return result;
}

Fixed  Fixed::operator*(const Fixed& later)
{
    Fixed   result(this->toFloat() * later.toFloat());

    return result;
}

Fixed  Fixed::operator/(const Fixed& later)
{
    Fixed   result(this->toFloat() / later.toFloat());

    return result;
}


Fixed&  Fixed::operator++()
{
    ++value;
    return (*this);
}

Fixed&  Fixed::operator++(int)
{
    value++;
    return (*this);
}

Fixed&  Fixed::operator--()
{
    --value;
    return (*this);
}

Fixed&  Fixed::operator--(int)
{
    value++;
    return (*this);
}