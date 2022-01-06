#include "span.hpp"

void  test_subject(void)
{
  Span sp = Span(5);

  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl; //2
  std::cout << sp.longestSpan() << std::endl; //14
}

void  test_range(void)
{
  std::vector<int>  numbers;
  for (int i = 0; i < 20000; i++)
    numbers.push_back(i + 1);
  
  Span  sp = Span(20000);
  sp.addNumber(numbers.begin(), numbers.end());

  std::cout << sp.shortestSpan() << std::endl; //1
  std::cout << sp.longestSpan() << std::endl; //19999
}

void  test_all_the_same(void)
{
  Span sp2 = Span(5);
  for (int i = 0; i < 5; i++)
    sp2.addNumber(42);
  std::cout << sp2.shortestSpan() << std::endl; 
  std::cout << sp2.longestSpan() << std::endl;
}

void  test_exception(void)
{
  /* size < 2 */
  try {
    Span sp1 = Span(5);
    sp1.addNumber(1);
    std::cout << sp1.shortestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int   main(void)
{
  test_subject();
  test_range();
  test_all_the_same();
  test_exception();

  return (0);
}