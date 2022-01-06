#include "Bureaucrat.hpp"

int   main()
{
  Bureaucrat a("a", 0);
  Bureaucrat b("b", 151);
  std::cout << std::endl;
  
	Bureaucrat bob("Bob", 149);

  bob.decreaseGrade();
  bob.decreaseGrade();
  bob.decreaseGrade();

  std::cout << bob << std::endl;
  std::cout << std::endl;

  bob.increaseGrade();
  bob.increaseGrade();
  bob.increaseGrade();
  bob.increaseGrade();

  std::cout << bob << std::endl;

  return (0);
}