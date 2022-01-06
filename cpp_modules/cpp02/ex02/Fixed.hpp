#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed {
private:
    int value;
    static const int flacBits = 8;

public:
    Fixed&   operator=(const Fixed& fixed);
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& fixed);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    // ex01 members
    Fixed(int const raw);
    Fixed(float const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    //ex02 members
    bool    operator>(const Fixed& later);
    bool    operator<(const Fixed& later);
    bool    operator>=(const Fixed& later);
    bool    operator<=(const Fixed& later);
    bool    operator==(const Fixed& later);
    bool    operator!=(const Fixed& later);

    Fixed   operator+(const Fixed& later);
    Fixed   operator-(const Fixed& later);
    Fixed   operator*(const Fixed& later);
    Fixed   operator/(const Fixed& later);

    Fixed&  operator++(); // 전위
    Fixed&  operator++(int); // 후위
    Fixed&  operator--(); // 전위
    Fixed&  operator--(int); // 후위

    static const Fixed&     min(const Fixed& a, const Fixed& b)
    {
        return (a.getRawBits() >= b.getRawBits() ? b : a);
    }

    static const Fixed&     max(const Fixed& a, const Fixed& b)
    {
        return (a.getRawBits() >= b.getRawBits() ? a : b);
    }
};

std::ostream&    operator<<(std::ostream& os, const Fixed& fixed);

#endif