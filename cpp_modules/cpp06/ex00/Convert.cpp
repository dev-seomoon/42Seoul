#include "Convert.hpp"

Convert::Convert(): _value(0.0) {}

Convert::Convert(const std::string& input): _value(std::stod(input)) {}

Convert::Convert(const Convert & src)
{
    *this = src;
}

Convert::~Convert() {}

Convert&    Convert::operator=(const Convert& src) {
    if (this != &src)
        _value = src.getValue();
    return (*this);
}

double  Convert::getValue(void) const 
{
    return (_value);
}

char    Convert::toChar(void) const
{
    if (std::isinf(_value) || std::isnan(_value))
        throw ImpossibleException();
    if (_value > CHAR_MAX || _value < CHAR_MIN)
        throw ImpossibleException();
    char c = static_cast<char>(_value);
    if (!std::isprint(c))
        throw NonDisplaybleException();
    return (c);
}

int     Convert::toInt(void) const
{
    if (std::isinf(_value) || std::isnan(_value))
        throw ImpossibleException();
    if (_value > INT_MAX || _value < INT_MIN)
        throw ImpossibleException();
    return (static_cast<int>(_value));
}

float   Convert::toFloat(void) const
{
    return (static_cast<float>(_value));
}

double  Convert::toDouble(void) const
{
    return (_value);
}

void    Convert::print(void) const
{
    try 
    {
        char c = toChar();
        std::cout << "char: '" << c << "'" << std::endl; 
    } catch(std::exception& e) {
        std::cout << "char: " << e.what() << std::endl;
    }

    try
    {
        int i = toInt();
        std::cout << "int: " << i << std::endl;
    } catch(std::exception &e) {
        std::cout << "int: " << e.what() << std::endl;
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << toFloat() << "f" << std::endl;
    std::cout << "double: " << toDouble() << std::endl;
}

const char* Convert::NonDisplaybleException::what() const throw()
{
    return ("Non displayble");
}

const char* Convert::ImpossibleException::what() const throw()
{
    return ("impossible");
}