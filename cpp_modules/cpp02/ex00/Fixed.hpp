#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
};

#endif