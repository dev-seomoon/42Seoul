#include "easyfind.hpp"

int   main(void)
{
  std::vector<int>  vec;
  std::list<int>  lst;
  std::deque<int> deck;

  for (int i = 0; i < 3; i++) {
    vec.push_back(i + 1);
    lst.push_back(i + 1);
    deck.push_back(i + 1);
  }

  std::cout << "Vector: " << std::endl;
  printfind(vec, -42);
  printfind(vec, 2);
  printfind(vec, 26);
  std::cout << std::endl;

  std::cout << "List: " << std::endl;
  printfind(lst, -42);
  printfind(lst, 2);
  printfind(lst, 26);
  std::cout << std::endl;

  std::cout << "Deque: " << std::endl;
  printfind(deck, -42);
  printfind(deck, 2);
  printfind(deck, 26);
  std::cout << std::endl;

  return (0);
}