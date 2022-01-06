#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
  Intern mini;

  Form *notExisted = mini.makeForm("not existed", "unknown");
  delete notExisted;
  std::cout << std::endl;

  Form *shrubbery = mini.makeForm("shrubbery creation", "home");
  Form *robotomy = mini.makeForm("robotomy request", "Erick");
  Form *presidential = mini.makeForm("presidential pardon", "Jenny");
  std::cout << std::endl;

  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << std::endl;

  Bureaucrat *a = new Bureaucrat("a", 130);
  Bureaucrat *b = new Bureaucrat("b", 40);
  Bureaucrat *c = new Bureaucrat("c", 1);
  Bureaucrat *little = new Bureaucrat("little", 150);
  std::cout << *a << "\n" << *b << "\n" << *c << "\n" << *little << std::endl;
  std::cout << std::endl;

  little->signForm(*shrubbery);
  std::cout << std::endl;

  a->signForm(*shrubbery);
  a->executeForm(*shrubbery);
  std::cout << std::endl;

  b->signForm(*robotomy);
  b->executeForm(*robotomy);
  std::cout << std::endl;

  c->signForm(*presidential);
  c->executeForm(*presidential);
  std::cout << std::endl;

  delete shrubbery;
  delete robotomy;
  delete presidential;
  delete a;
  delete b;
  delete c;
  delete little;

  system("leaks test | grep LEAK");

  return (0);
}