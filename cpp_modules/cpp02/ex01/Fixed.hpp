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
};

std::ostream&    operator<<(std::ostream& os, const Fixed& fixed);

#endif