#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <climits>
# include <cmath>

class Convert
{
    private:
        double      _value;
    
    public:
        Convert();
        Convert(const std::string& input);
        Convert(const Convert& src);
        ~Convert();
        Convert&    operator=(const Convert& src);

        double  getValue(void) const;

        char    toChar(void) const;
        int     toInt(void) const;
        float   toFloat(void) const;
        double  toDouble(void) const;

        void    print(void) const;

        class NonDisplaybleException: public std::exception
        {
            const char*     what() const throw();
        };

        class ImpossibleException: public std::exception
        {
            const char*     what() const throw();
        };
};

#endif