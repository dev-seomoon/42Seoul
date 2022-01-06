#include "Data.hpp"

std::string     Data::getName(void) const
{
    return (_name);
}

int             Data::getProductionYear(void) const
{
    return (_production_year);
}

Data::Data() {}

Data::Data(std::string name, int production_year)
: _name(name), _production_year(production_year)
{}

Data::Data(const Data& src)
{
    *this = src;
}

Data&   Data::operator=(const Data& src)
{
    if (this != &src) {
        _name = src.getName();
        _production_year = src.getProductionYear();
    }
    return (*this);
}

Data::~Data() {}

std::ostream&   operator<<(std::ostream& os, const Data& data)
{
    os << "name: " << data.getName() << "\n"
        << "production year: " << data.getProductionYear() << "\n";
    return (os);
}
