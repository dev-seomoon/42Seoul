#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    iter(T* array, int length, void (*fcnPtr)(T& element))
{
  for (int i = 0; i < length; i++)
  {
    (*fcnPtr)(array[i]);
  }
  std::cout << std::endl;
}

template <typename T>
void    print(T& element)
{
  std::cout << element << " ";
}

#endif