#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
    private:
        std::string     _name;
        int             _production_year;
    
    public:
        std::string     getName(void) const;
        int             getProductionYear(void) const;

        Data();
        Data(std::string name, int production_year);
        Data(const Data& src);
        Data&   operator=(const Data& src);
        ~Data();
};

std::ostream&   operator<<(std::ostream& os, const Data& data);

#endif