#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
  Form *shrubbery = new ShrubberyCreationForm("home"); // 145 137
  Form *robotomy = new RobotomyRequestForm("Erick"); // 72 45
  Form *presidential = new PresidentialPardonForm("Jenny"); // 25 5
  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << std::endl;

  Bureaucrat *a = new Bureaucrat("a", 130);
  Bureaucrat *b = new Bureaucrat("b", 40);
  Bureaucrat *c = new Bureaucrat("c", 1);
  Bureaucrat *mini = new Bureaucrat("mini", 140);
  Bureaucrat *little = new Bureaucrat("little", 150);
  std::cout << *a << "\n" << *b << "\n" << *c << "\n" << *little << std::endl;
  std::cout << std::endl;

  little->signForm(*shrubbery);
  a->executeForm(*shrubbery);
  std::cout << std::endl;

  a->signForm(*shrubbery);
  mini->executeForm(*shrubbery);
  std::cout << std::endl; 

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