#include "Data.hpp"

uintptr_t   serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

int         main()
{
    Data    *before = new Data("G6", 2017);
    Data    *after;

    after = deserialize(serialize(before));

    std::cout << "before: \n" << before << std::endl;
    std::cout << serialize(before) << std::endl;
    std::cout << *before << std::endl;

    std::cout << "after: \n" << after << std::endl;
    std::cout << serialize(after) << std::endl;
    std::cout << *after << std::endl;

    delete before;

    return (0);
}