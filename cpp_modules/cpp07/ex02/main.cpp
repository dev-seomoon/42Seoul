#include "Array.hpp"

int     main(void)
{
    std::cout << "Char: " << std::endl;
    Array<char> char_arr(5);
    for (int i = 0; i < 5; i++) {
        char_arr[i] = static_cast<char>(i + '0');
    }
    print_array<char>(char_arr, 5);
    std::cout << std::endl;

    std::cout << "Int: " << std::endl;
    Array<int> int_arr(5);
    for (int i = 0; i < 5; i++) {
        int_arr[i] = i;
    }
    print_array<int>(int_arr, 5);
    std::cout << std::endl;

    std::cout << "String: " << std::endl;
    
    Array<std::string> str_arr(3);
    for (unsigned int i = 0; i < 3; i++) {
        str_arr[i] = "Hello";
    }
    print_array<std::string>(str_arr, 3);

    Array<std::string> str_arr_copy(str_arr);
    print_array<std::string>(str_arr_copy, 3);
    std::cout << std::endl;

    try {
        str_arr[3] = "Out of Range";
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}