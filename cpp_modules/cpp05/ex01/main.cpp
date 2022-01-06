#include "Bureaucrat.hpp"
#include "Form.hpp"

int   main()
{
  Form *wrongForm = new Form("wrong", 0, 0);
  delete wrongForm;

  Form *one = new Form("one", 1, 1);
  Form *two = new Form("two", 100, 50);

  Bureaucrat *a = new Bureaucrat("a", 2);
  Bureaucrat *b = new Bureaucrat("b", 40);

  std::cout << std::endl;
  a->signForm(*one);
  std::cout << *one << std::endl;

  a->increaseGrade();
  a->signForm(*one);
  std::cout << *one << std::endl;

  b->signForm(*two);
  std::cout << *two << std::endl;

  delete one;
  delete two;
  delete a;
  delete b;
  
  system("leaks test | grep LEAK");
  return (0);
}