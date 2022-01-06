#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>

template <typename T>
bool  easyfind(T container, int n) {
  int result = *std::find(container.begin(), container.end(), n);
  return (result == n);
};

template <typename T>
void  printfind(T &container, int n) {
  if (easyfind(container, n))
    std::cout << n << " found" << std::endl;
  else
    std::cout << n << " not found" << std::endl;
}

#endif