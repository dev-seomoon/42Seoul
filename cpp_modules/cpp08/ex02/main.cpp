#include "mutantstack.hpp"

void  test_iterator(void) // example in subject
{
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;

  mstack.pop();
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;

  for (int i = 0; i < 20; i++) {
    mstack.push(i + 1);
  }

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  while (it != ite)
  {
    std::cout << *it << " ";
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << std::endl;
}

void  test_const_iterator(void)
{
  MutantStack<char> mstack;

  for (int i = 0; i < 5; i++)
    mstack.push('a' + i);
  
  MutantStack<char>::const_iterator cit = mstack.cbegin();
  MutantStack<char>::const_iterator cite = mstack.cend();

  while (cit != cite) {
    std::cout << *cit << " ";
    ++cit;
  }

  std::cout << std::endl;
}

void  test_reverse_iterator(void)
{
  MutantStack<double> mstack;
  mstack.push(1.0);
  mstack.push(2.0);
  mstack.push(3.0);
  mstack.push(4.0);
  mstack.push(5.0);
  MutantStack<double>::reverse_iterator rit = mstack.rbegin();
  MutantStack<double>::reverse_iterator rite = mstack.rend();
  
  while (rit != rite)
  {
    std::cout << *rit << " ";
    ++rit;
  }
  std::cout << std::endl;
}

void  test_const_reverse_iterator(void)
{
  MutantStack<std::string> mstack;
  mstack.push("hello");
  mstack.push("world");
  mstack.push("!!");
  MutantStack<std::string>::const_reverse_iterator crit = mstack.crbegin();
  MutantStack<std::string>::const_reverse_iterator crite = mstack.crend();
  
  while (crit != crite) {
    std::cout << *crit << " ";
    ++crit;
  }
  std::cout << std::endl;
}

int   main(void)
{
  test_iterator();
  test_const_iterator(); // a b c d e
  test_reverse_iterator(); // 5 4 3 2 1
  test_const_reverse_iterator(); // !! world hello

  return (0);
}