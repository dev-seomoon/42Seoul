#include "iter.hpp"

int     main(void)
{
    char    c[5] = { 'a', 'b', 'c', 'd', 'e' };
    int     i[5] = { 1, 2, 3, 4, 5 };
    std::string s[5] = { "hello", "world", "by", "42", "seomoon"};

    std::cout << "Char :" << std::endl;
    iter(c, 5, print);
    std::cout << std::endl;

    std::cout << "Int :" << std::endl;
    iter(i, 5, print);
    std::cout << std::endl;

    std::cout << "String :" << std::endl;
    iter(s, 5, print);
    std::cout << std::endl;

    return (0);
}